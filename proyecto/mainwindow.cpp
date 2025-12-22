#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QAction>

#include <QMouseEvent> // NUEVO
#include <QKeyEvent> // NUEVO
#include <QPen> // NUEVO
#include <QApplication> // NUEVO
#include <QMessageBox>
#include <QDebug>
#include <QColorDialog>
#include "tool.h"
#include <QFile>

#include <QStandardItemModel>

#include <QSplitter>
#include <QHBoxLayout>

#include "navigation.h"
#include "navdaoexception.h"
#include <QFileDialog>
#include <QRandomGenerator>
#include <QGraphicsOpacityEffect>


//#define QString CurrentUser = "";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    sceneMapa(new QGraphicsScene(this))
// ,sceneCompas(new QGraphicsScene(this))
{
    ui->setupUi(this);
    connect(ui->link_registro, &QLabel::linkActivated,
            this, &MainWindow::on_link_registro_linkActivated);


    QFile file(":/qss/estilos/estilos.qss"); //ruta al css

    if (file.open(QFile::ReadOnly)){
        QString styleSheet = QString::fromUtf8(file.readAll());
        this -> setStyleSheet(styleSheet);
        file.close();
    }

    //***************************************BLOQUEAR MENU SUP
    connect(ui->stackedWidget, &QStackedWidget::currentChanged, this, [=]() {
        actualizarEstadoMenuSuperior();
    });
    // Llamada inicial para bloquearlo al arrancar la app
    actualizarEstadoMenuSuperior();


    //*****************************************************SPLITTER
    if (ui->horizontalWidget->layout()) {
        delete ui->horizontalWidget->layout();//si no borramos el layout el splitter se pone mal
    }

    QSplitter *splitter = new QSplitter(Qt::Horizontal, ui->horizontalWidget);
    splitter->addWidget(ui->stackedWidget_2);//mete lo q teniamos en al ui en cada lado del splitter
    splitter->addWidget(ui->verticalWidget);
    ui->stackedWidget_2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);//declara sizepolicy de cada parte
    ui->verticalWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    splitter->setSizes({400, 400});  // tamaño inicial
    // Después de añadir los widgets al splitter en tu constructor
    splitter->setStretchFactor(0, 1); // stackedWidget_2 (Problema/Lista)
    splitter->setStretchFactor(1, 3); // verticalWidget (Mapa)
    QHBoxLayout *layout = new QHBoxLayout(ui->horizontalWidget);
    layout->setContentsMargins(0, 0, 0, 0); // para que ocupe todo el widget
    layout->setSpacing(0);
    layout->addWidget(splitter);
    //*************************************************************BARRA HERRAMIENTAS

    view = ui->graphicsView;
    ui->graphicsView->viewport()->installEventFilter(this);
    ui->graphicsView->viewport()->setMouseTracking(true);

    ui->linea->setCheckable(true);
    ui->goma->setCheckable(true);
    ui->texto->setCheckable(true);
    connect(ui->linea, &QPushButton::toggled,
            this, &MainWindow::setDrawLineMode);
    connect(ui->limpiar, &QPushButton::clicked,
            this, &MainWindow::limpiarTodo);
    connect(ui->goma, &QPushButton::toggled,
            this, &MainWindow::borrarGoma);
    connect(ui->texto, &QPushButton::toggled, this, &MainWindow::ponerTexto);
    connect(ui->punto, &QPushButton::toggled, this, &MainWindow::ponerPunto);

    //*************************************************************BARRA SUPERIOR/MENU DESPLEGABLE
    QMenu *menuUsuario = new QMenu(this); //crear menu

    // acciones del menu
    QAction *actionPerfil = new QAction(tr("Editar Perfil"), this);
    QAction *actionCerrarSesion = new QAction(tr("Cerrar Sesión"), this);

    menuUsuario->addAction(actionPerfil);
    menuUsuario->addSeparator(); // Añade una línea divisoria
    menuUsuario->addAction(actionCerrarSesion);

    ui->B_MenuUsuario->setMenu(menuUsuario);

    //Conectar acciones a los cambios de página
    connect(actionPerfil, &QAction::triggered, this, [=]() {
        m_origenProblema = -1;
        setupPerfil();
        ui->stackedWidget->setCurrentWidget(ui->editar_perfil);
    });

    connect(actionCerrarSesion, &QAction::triggered, this, [=]() {
        // Lógica para cerrar sesión, por ejemplo volver al login_________TEMPORAL!!!!
        // 1. GUARDAR EN LA BASE DE DATOS
        Navigation &nav = Navigation::instance();
        User *u = nav.findUser(m_usuarioActual);                // CAMBIAR POR USUARIO LOGEADO!!!!

        // 2. Crear un objeto Session con los datos actuales
        // (Asumiendo que Session tiene un constructor o setters para hits/faults)
        //Session nuevaSesion;
        Session nuevaSesion(QDateTime::currentDateTime(), m_aciertosActuales, m_fallosActuales);
        qDebug() << "Aciertos totales: "<<m_aciertosActuales << "Fallos" << m_fallosActuales;
        // 3. USAR LA FUNCIÓN: addSession
        // Esto añade la sesión a la lista interna del objeto User
        u->addSession(nuevaSesion);

        qDebug() << "Sesión añadida al objeto User en memoria.";

        // 4. Guardar en la Base de Datos (SQL)
        if(u->insertedInDb()){
            qDebug() << "Base de datos actualizada (creo)";
        } else {
            u->setInsertedInDb(true);
        }
        // 2. RESETEAR VARIABLES LÓGICAS
        m_aciertosActuales = 0;
        m_fallosActuales = 0;

        // Desmarcar y limpiar estilos de los radio buttons
        QVector<QRadioButton*> rbs = {ui->answer1, ui->answer2, ui->answer3, ui->answer4};
        for(auto* rb : rbs) {
            rb->setAutoExclusive(false); // Truco para poder desmarcarlo
            rb->setChecked(false);
            rb->setAutoExclusive(true);
            rb->setStyleSheet("");       // Quitar rojos/verdes
            rb->setEnabled(true);
        }
        ui->stackedWidget->setCurrentWidget(ui->ini_sesion);
    });

    //************************************************************BOTÓN USUARIO
    ui->B_MenuUsuario->setFixedSize(60, 60);
    ui->B_MenuUsuario->setIconSize(QSize(55, 55));
    ui->boton_historial->setFixedSize(100, 40);
    ui->boton_volver->setFixedSize(60, 40);
    ui->boton_editar_avatar->setFixedSize(42, 42);
    //***********************************************************TABLA HISTORIAL
    ui->tableViewHistorial->setShowGrid(false); // Quita todas las líneas de cuadrícula
    ui->tableViewHistorial->setAlternatingRowColors(true); // Habilita el fondo distinto para filas pares/impares
    ui->tableViewHistorial->verticalHeader()->setVisible(false); // Oculta los números de fila de la izquierda
    ui->tableViewHistorial->setSelectionMode(QAbstractItemView::NoSelection); // Evita que se resalte en azul al clicar
    ui->tableViewHistorial->setFocusPolicy(Qt::NoFocus); // Quita el recuadro punteado de enfoque

    // Estirar las columnas para que ocupen todo el ancho disponible
    ui->tableViewHistorial->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // view->setScene(sceneMenu);
    // view->setScene(sceneMapa);

    QPixmap mapa(":/img/carta_nautica");

    QGraphicsPixmapItem *itemMapa = sceneMapa->addPixmap(mapa);
    itemMapa->setZValue(0);

    ui->graphicsView->setScene(sceneMapa);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    double initialScale = 0.3;
    ui->graphicsView->scale(initialScale, initialScale);

    scale = initialScale;
    m_currentColor = Qt::red;

    ui->horizontalSlider->setValue(30);//val inicial

    // ===============================TRANSPORTADOR
    transportador = new Tool(":/img/icons/transportador.svg");
    sceneMapa->addItem(transportador);
    // Tamaño "lógico" aproximado, como antes
    transportador->setToolSize(QSizeF(580, 380));
    // Z alta para que quede en overlay
    transportador->setZValue(1000);
    // Posición inicial en la esquina superior izquierda de la vista
    transportador->setVisible(false);
    // ===============================REGLA
    regla = new Tool(":/img/icons/ruler.svg");
    sceneMapa->addItem(regla);
    // Tamaño "lógico" aproximado, como antes
    regla->setToolSize(QSizeF(580, 380));
    // Z alta para que quede en overlay
    regla->setZValue(1000);
    // Posición inicial en la esquina superior izquierda de la vista
    regla->setVisible(false);
    // ===============================COMPÁS
    compas = new Compass(":/img/icons/compass_leg.svg");
    sceneMapa->addItem(compas);
    regla->setToolSize(QSizeF(580, 380));
    // Z alta para que quede en overlay
    compas->setZValue(1000);
    // Posición inicial en la esquina superior izquierda de la vista
    compas->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//#############################################################################################
//################### historial ####################
/*void MainWindow::setupHistorialTable()
{


    // --- 1. Gestión de Excepciones y Acceso al Singleton ---
    try {
        Navigation &nav = Navigation::instance();

        // --- 2. Obtener el Usuario y Sesiones ---
        const User *u = nav.findUser("user1");                                          //CAMBIAR POR USUARIO CONCRETO!!!!!
        const QList<Session> &sessions = u->sessions();

        // --- 3. Crear el QStandardItemModel (Modelo de Datos C++) ---
        // 0 filas, 3 columnas (Fecha, Aciertos, Fallos)
        // Usamos 'this' como padre para que se borre automáticamente.
        QStandardItemModel *stdModel = new QStandardItemModel(0, 3, this);

        // Configurar los encabezados (headers)
        stdModel->setHeaderData(0, Qt::Horizontal, tr("Sesión"));
        stdModel->setHeaderData(1, Qt::Horizontal, tr("Aciertos"));
        stdModel->setHeaderData(2, Qt::Horizontal, tr("Fallos"));

        // --- 4. Rellenar el Modelo con los Objetos Session ---
        for (const Session &s : sessions) {
            QList<QStandardItem*> row;

            // 1. OBTENER EL DATETIME (Fecha y Hora)
            // Usamos QDateTime porque el historial necesita saber la hora exacta de la sesión
            //QDateTime sesion = s.timeStamp().toString("dd/MM/yyyy HH:mm");
            QString sesion = s.timeStamp().toString("dd/MM/yyyy HH:mm");

            // 2. CREAR EL OBJETO (¡Paso vital: el 'new'!)
            // Sin el 'new', el programa intenta escribir en una memoria que no existe y se cierra.
            QStandardItem* itemFecha = new QStandardItem();

            // Guardamos el dato real (objeto QDateTime)
            itemFecha->setData(sesion, Qt::EditRole);
            qDebug() << "ItemFecha:" << sesion;
            // Ponemos el texto que verá el usuario (Día/Mes/Año Hora:Min:Seg)
            itemFecha->setText(sesion);
            qDebug() << "ItemFecha_final:" << itemFecha;

            // 3. AÑADIR LAS COLUMNAS A LA FILA
            // Primera columna: El objeto que acabamos de configurar
            //row.append(new QStandardItem(sesion.toString("dd/MM/yyyy HH:mm:ss")));
            row.append(itemFecha);

            // Segunda columna: Aciertos (hits)
            row.append(new QStandardItem(QString::number(s.hits())));

            // Tercera columna: Fallos (faults)
            row.append(new QStandardItem(QString::number(s.faults())));

            // 4. INSERTAR LA FILA EN EL MODELO
            stdModel->appendRow(row);

        }

        // --- 5. Asignar el nuevo modelo a la tabla ---
        // ¡IMPORTANTE! Si ya había un modelo, Qt lo liberará automáticamente si le pones 'this' como padre.
        ui->tableViewHistorial->setModel(stdModel);
        ui->tableViewHistorial->setColumnWidth(0, 180); // Un poco más ancho para el formato completo
        ui->tableViewHistorial->resizeColumnsToContents();

    } catch (const NavDAOException &ex) {
        QMessageBox::critical(this, tr("DB error"), ex.what());
    }
}
*/

void MainWindow::setupHistorialTable()
{
    // Limpiamos la tabla (importante para que no se dupliquen datos al recargar)
    ui->tableViewHistorial->setRowCount(0);

    int totalAciertos = 0;
    int totalFallos = 0;

    // Obtenemos la fecha del filtro (asegúrate de que el nombre coincida)
    QDate fechaFiltro = ui->dateEditFiltro->date();

    Navigation &nav = Navigation::instance();
    const User *u = nav.findUser(m_usuarioActual);

    if (u) {
        // Usamos el QVector de sesiones que tienes en tu .h
        const QVector<Session> &sesiones = u->sessions();

        qDebug() << "Filtrando desde:" << fechaFiltro << "Total Sesiones:" << sesiones.size();

        // Bucle inverso para ver lo más reciente primero
        for(int i = sesiones.size() - 1; i >= 0; --i) {
            const Session &s = sesiones[i];

            // Comprobamos la fecha de la sesión contra el filtro
            //if (s.timeStamp().date() >= fechaFiltro) {

            int fila = ui->tableViewHistorial->rowCount();
            ui->tableViewHistorial->insertRow(fila);

            // --- COLUMNA 0: FECHA ---
            // Convertimos el QDateTime a texto para el item de la tabla
            QTableWidgetItem *itemFecha = new QTableWidgetItem(s.timeStamp().toString("dd/MM/yyyy HH:mm"));
            itemFecha->setTextAlignment(Qt::AlignCenter);
            ui->tableViewHistorial->setItem(fila, 0, itemFecha);

            // --- COLUMNA 1: ACIERTOS ---
            QTableWidgetItem *itemHits = new QTableWidgetItem(QString::number(s.hits()));
            itemHits->setTextAlignment(Qt::AlignCenter);
            itemHits->setForeground(Qt::darkGreen);

            QFont negrita = itemHits->font();
            negrita.setBold(true);
            itemHits->setFont(negrita);
            ui->tableViewHistorial->setItem(fila, 1, itemHits);

            // --- COLUMNA 2: FALLOS ---
            QTableWidgetItem *itemFaults = new QTableWidgetItem(QString::number(s.faults()));
            itemFaults->setTextAlignment(Qt::AlignCenter);
            if (s.faults() > 0) {
                itemFaults->setForeground(Qt::red);
                itemFaults->setFont(negrita);
            }
            ui->tableViewHistorial->setItem(fila, 2, itemFaults);

            // Sumamos para el resumen
            totalAciertos += s.hits();
            totalFallos += s.faults();
            // }
        }
    }

    // Actualizamos el label de resumen final
    /*ui->lblSummary->setText(QString("Resumen del periodo: %1 Aciertos | %2 Fallos")
                                .arg(totalAciertos).arg(totalFallos));*/
}

void MainWindow::on_boton_historial_clicked()
{
    m_origenProblema = -1;

    setupHistorialTable();

    ui->stackedWidget->setCurrentWidget(ui->historial);
}

//################################### Modificar perfil ###############################################
void MainWindow::setupPerfil()
{
    try {
        Navigation &nav = Navigation::instance();

        const User *u = nav.findUser(m_usuarioActual);
        if (!u) return;

        // Cargar datos en el formulario
        ui->labelNombre->setText(u->nickName());
        ui->labelEmail->setText(u->email());
        ui->labelContrasenia->setText(u->password());
        ui->dateEdit->setDate(u->birthdate());

        // Avatar
        if (!u->avatar().isNull()) {
            ui->avatar->setPixmap(QPixmap::fromImage(u->avatar()));
            ui->avatar->setScaledContents(true);
        } else {
            ui->avatar->setPixmap(QPixmap(":/recursos/default_avatar.png"));
            ui->avatar->setScaledContents(true);
        }

        // Evitar editar nombre de usuario
        ui->labelNombre->setEnabled(false);

    } catch (const NavDAOException &ex) {
        QMessageBox::critical(this, tr("DB error"), ex.what());
    }
}

void MainWindow::on_boton_editar_avatar_clicked()
{
    // 1. Abrir el buscador de archivos
    // Filtramos para que solo aparezcan imágenes
    QString fileName = QFileDialog::getOpenFileName(this, tr("Seleccionar Imagen de Perfil"), "", tr("Imágenes (*.png *.jpg *.jpeg *.bmp)"));

    // 2. Comprobar si el usuario seleccionó algo o canceló
    if (!fileName.isEmpty()) {
        QImage imagen(fileName); // Cargamos la imagen desde la ruta

        if (!imagen.isNull()) {
            // 3. Actualizar la PREVIA en la interfaz
            // Como vimos antes, QLabel necesita QPixmap
            ui->avatar->setPixmap(QPixmap::fromImage(imagen));
            ui->avatar->setScaledContents(true);

            // 4. Guardar la imagen en el objeto User para luego hacer el updateUser
            // Suponiendo que 'u' es tu puntero al usuario
            // u->setAvatar(imagen);

            qDebug() << "Nueva imagen cargada desde:" << fileName;
        } else {
            QMessageBox::warning(this, tr("Error"), tr("No se pudo cargar la imagen."));
        }
    }
}

void MainWindow::on_boton_guardar_clicked()
{
    Navigation &nav = Navigation::instance();
    User *u = nav.findUser(m_usuarioActual);
    if (!u) return;

    bool valido = true;

    // Validaciones (usuario, email, contraseña)
    QRegularExpression reMail("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
    if (!reMail.match(ui->labelEmail->text()).hasMatch()) {
        ui->error_correo->setText("Correo electrónico no válido");
        ui->error_correo->setStyleSheet("color:red;");
        ui->error_correo->show();
        valido = false;
    }

    QRegularExpression rePass(
        "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[!@#$%&*()\\-+=]).{8,20}$"
        );
    if (!rePass.match(ui->labelContrasenia->text()).hasMatch()) {
        ui->error_pass->setText(
            "8-20 caracteres, mayúscula, minúscula, número y carácter especial"
            );
        ui->error_pass->setStyleSheet("color:red;");
        ui->error_pass->show();
        valido = false;
    }

    if(valido){
        u->setEmail(ui->labelEmail->text());
        u->setPassword(ui->labelContrasenia->text());
        u->setBirthdate(ui->dateEdit->date());

        QPixmap pix = ui->avatar->pixmap();
        if (!pix.isNull()) u->setAvatar(pix.toImage());

        nav.updateUser(*u);

        QMessageBox::information(this, "Éxito", "Perfil actualizado correctamente");
    }
}

//################################## lista problemas #####################################################

void MainWindow::cargarListaProblemas() {
    Navigation &nav = Navigation::instance();

    // 1. Obtenemos la lista real de la base de datos
    //const std::vector<Problem*>& problemas = nav.problems();
    auto problemas = nav.problems();

    // 2. Limpiamos el QListWidget para no duplicar
    ui->listWidget->clear();

    // 3. El bucle for sigue funcionando igual
    for (int i = 0; i < (int)problemas.size(); ++i) {
        QString nombre = "Problema " + QString::number(i + 1);
        ui->listWidget->addItem(nombre);
    }
}
void MainWindow::on_boton_aleat_clicked()
{
    m_origenProblema = 0;
    Navigation &nav = Navigation::instance();
    auto listaProblemas = nav.problems(); // Usamos auto para evitar errores de tipo
    int totalProblemas = listaProblemas.size();
    int numeroRandom = QRandomGenerator::global()->bounded(1, totalProblemas + 1);

    m_problema_actual = numeroRandom;     //en vez de index.row -> random

    if (m_problema_actual < totalProblemas) {
        const Problem &p = listaProblemas.at(m_problema_actual); // Cambia '*' por '&' y añade 'const'
        auto respuestas = p.answers();

        std::shuffle(respuestas.begin(), respuestas.end(),
                     std::default_random_engine(QRandomGenerator::global()->generate()));

        ui->num_problema->setText(QString("Problema %1").arg(m_problema_actual + 1));
        ui->enunciado->setText(p.text());
        if (respuestas.size() >= 4) {
            ui->answer1->setText(respuestas.at(0).text());
            ui->answer2->setText(respuestas.at(1).text());
            ui->answer3->setText(respuestas.at(2).text());
            ui->answer4->setText(respuestas.at(3).text());
        }
    }
    // Cambiamos a la página del mapa/problema
    ui->stackedWidget_2->setCurrentWidget(ui->problema);
}
void MainWindow::on_boton_lista_clicked()
{
    m_origenProblema = 1;
    cargarListaProblemas();
    ui->stackedWidget_2->setCurrentWidget(ui->lista_problemas);
}
void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    // index.row() te dará el número (0 para Problema 1, 1 para Problema 2...)
    int fila = index.row();
    m_problema_actual= fila;

    Navigation &nav = Navigation::instance();
    auto listaProblemas = nav.problems(); // Usamos auto para evitar errores de tipo

    if (fila < (int)listaProblemas.size()) {
        const Problem &p = listaProblemas.at(fila); // Cambia '*' por '&' y añade 'const'
        auto respuestas = p.answers();
        ui->num_problema->setText(QString("Problema %1").arg(m_problema_actual + 1));
        ui->enunciado->setText(p.text());
        if (respuestas.size() >= 4) {
            ui->answer1->setText(respuestas.at(0).text());
            ui->answer2->setText(respuestas.at(1).text());
            ui->answer3->setText(respuestas.at(2).text());
            ui->answer4->setText(respuestas.at(3).text());
        }
    }
    // Cambiamos a la página del mapa/problema
    ui->stackedWidget_2->setCurrentWidget(ui->problema);
}
void MainWindow::corregirRespuesta(int indiceSeleccionado)
{
    Navigation &nav = Navigation::instance();
    auto listaProblemas = nav.problems(); // Usamos auto para evitar errores de tipo
    const Problem &p = listaProblemas.at(m_problema_actual);//#######Averiguar en que problema estamos#######
    // 1. Obtener la lista de respuestas del problema actual
    QVector<Answer> respuestas = p.answers();

    // 2. Verificar si el índice es válido y comprobar la validez
    if (indiceSeleccionado >= 0 && indiceSeleccionado < respuestas.size())
    {
        if (respuestas[indiceSeleccionado].validity()) {
            m_aciertosActuales++;
            qDebug() << "¡Correcto! Aciertos:" << m_aciertosActuales;
            // Aquí podrías mostrar un label en verde o un icono
        } else {
            m_fallosActuales++;
            qDebug() << "Incorrecto... Fallos:" << m_fallosActuales;
            // Aquí podrías mostrar un label en rojo
        }
    }
}
void MainWindow::on_corregir_clicked()
{
    // 1. Averiguar cuál está marcado
    int indiceSeleccionado = -1;
    int indiceCorrecto = -1;

    if (ui->answer1->isChecked())      indiceSeleccionado = 0;
    else if (ui->answer2->isChecked()) indiceSeleccionado = 1;
    else if (ui->answer3->isChecked()) indiceSeleccionado = 2;
    else if (ui->answer4->isChecked()) indiceSeleccionado = 3;

    // 2. Validar que haya seleccionado algo
    if (indiceSeleccionado == -1) {
        qDebug() << "Debes elegir una respuesta.";
        QMessageBox::information(this, "Error", "Debes elegir una respuesta");

        return;
    }
    // 3. Comparar con la respuesta correcta del problema actual
    Navigation &nav = Navigation::instance();
    auto listaProblemas = nav.problems(); // Usamos auto para evitar errores de tipo
    const Problem &p = listaProblemas.at(m_problema_actual); // /////Averiguar en que problema estamos#######
    auto respuestas = p.answers();
    int aux = -1;

    for(int i=0; i<4; i++){
        aux = i;
        if(respuestas.at(aux).validity()){
            indiceCorrecto=i;
        }
    }

    if (indiceSeleccionado < respuestas.size())
    {
        if (indiceSeleccionado==indiceCorrecto) {
            m_aciertosActuales++;
            //indiceCorrecto = indiceSeleccionado;
            qDebug() << "¡Respuesta Correcta!";

        } else {
            m_fallosActuales++;
            qDebug() << "Respuesta Incorrecta.";
        }
    }

    switch (indiceSeleccionado){
    case 0:
        ui->answer1->setStyleSheet("color: red; font-weight: bold;");
        break;
    case 1:
        ui->answer2->setStyleSheet("color: red; font-weight: bold;");
        break;
    case 2:
        ui->answer3->setStyleSheet("color: red; font-weight: bold;");
        break;
    case 3:
        ui->answer4->setStyleSheet("color: red; font-weight: bold;");
        break;
    default:
        break;
    }

    switch (indiceCorrecto){
    case 0:
        ui->answer1->setStyleSheet("color: green; font-weight: bold;");
        break;
    case 1:
        ui->answer2->setStyleSheet("color: green; font-weight: bold;");
        break;
    case 2:
        ui->answer3->setStyleSheet("color: green; font-weight: bold;");
        break;
    case 3:
        ui->answer4->setStyleSheet("color: green; font-weight: bold;");
        break;
    default:
        break;
    }

    qDebug() << "Indice Seleccionado: "<<indiceSeleccionado<<" Indice correcto: "<<indiceCorrecto;

    // 4. Bloquear los radio buttons para que no pueda cambiar la respuesta ya corregida
    ui->answer1->setEnabled(false);
    ui->answer2->setEnabled(false);
    ui->answer3->setEnabled(false);
    ui->answer4->setEnabled(false);

    // Y desactivamos el propio botón de corregir
    ui->corregir->setEnabled(false);
}
//############################################################################################

void MainWindow::on_boton_volver_clicked()
{
    if(m_origenProblema==0){

        ui->stackedWidget_2->setCurrentWidget(ui->menu_principal);

    } else if (m_origenProblema==1){

        ui->stackedWidget_2->setCurrentWidget(ui->lista_problemas);

    } else{
        ui->stackedWidget->setCurrentWidget(ui->mapa);
        ui->stackedWidget_2->setCurrentWidget(ui->menu_principal);
    }

    ui->corregir->setEnabled(true);

    QVector<QRadioButton*> rbs = {ui->answer1, ui->answer2, ui->answer3, ui->answer4};
    for(auto* rb : rbs) {
        rb->setAutoExclusive(false); // Truco para poder desmarcarlo
        rb->setChecked(false);
        //rb->setAutoExclusive(true);
        rb->setStyleSheet("color: black; font-weight: none;");       // Quitar rojos/verdes
        rb->setEnabled(true);
    }

    m_origenProblema = -1;

}
//############################################################################################


/*void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->stackedWidget_2->setCurrentWidget(ui->problema);
}*/

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    int gros = ui->grosor->value();
    if (obj == ui->graphicsView->viewport()) {

        auto *e = static_cast<QMouseEvent*>(event);
        QPointF scenePos;

        // =================================================================
        // BLOQUE 1: MOUSE MOVE (Coordenadas/Actividad)
        // =================================================================

        if (event->type() == QEvent::MouseMove)
        {
            // 1. RECOGIDA DE COORDENADAS:
            // ASIGNAR el valor a la variable declarada arriba.
            scenePos = ui->graphicsView->mapToScene(e->pos());

            QString currentStatus = "Navegación (Arrastrar mapa)";

            if (m_eraserMode) {
                currentStatus = "Modo Goma de Borrar";
            } else if (m_textMode) {
                currentStatus = "Modo Anotar Texto (Clic Izquierdo)";
            } else if (m_drawLineMode) {
                currentStatus = m_currentLineItem ? "Dibujando Línea (Botón Derecho pulsado)" : "Modo Línea (Clic Derecho para empezar)";
            } else if (regla && regla->isVisible()) {
                currentStatus = "Regla visible";
            } else if (transportador && transportador->isVisible()) {
                currentStatus = "Transportador visible";
            } else if (compas && compas->isVisible()) {

                if (compas->isCursorInRotationZone(scenePos)) {
                    // El cursor está sobre la zona de apertura de la punta
                    ui->graphicsView->viewport()->setCursor(QCursor(Qt::SizeFDiagCursor));
                    currentStatus = "Compás: Abrir/Cerrar";
                } else {
                    currentStatus = "Compás visible";
                }
            } else if (compas && compas->isVisible()) {

                if (compas->isCursorInRotationZone(scenePos)) {
                    // El cursor está sobre la zona de apertura de la punta
                    ui->graphicsView->viewport()->setCursor(QCursor(Qt::SizeFDiagCursor));
                    currentStatus = "Compás: Abrir/Cerrar";
                } else {
                    currentStatus = "Compás visible";
                }
            }
            // Si ningún modo especial está activo y el compás está oculto, usamos el cursor por defecto (ArrowCursor).
            else if (!m_eraserMode && !m_drawLineMode && !m_textMode) {
                ui->graphicsView->viewport()->setCursor(Qt::ArrowCursor);
            }

            updateStatusLabel(scenePos, currentStatus);
        }

        // =================================================================
        // BLOQUE 2: MANEJO DE ACCIONES (Press, Release, Move con botones)
        // =================================================================

        if (event->type() == QEvent::MouseButtonPress ||
            event->type() == QEvent::MouseButtonRelease ||
            (event->type() == QEvent::MouseMove && e->buttons() != Qt::NoButton))
        {
            // IMPORTANTE: Si el evento no fue un MouseMove, scenePos debe calcularse.
            // Si fue un MouseMove con botón, usamos la última scenePos calculada arriba.
            if (event->type() != QEvent::MouseMove) {
                scenePos = ui->graphicsView->mapToScene(e->pos());
            }

            if (m_eraserMode)
            {
                if (event->type() == QEvent::MouseButtonPress && e->button() == Qt::LeftButton)
                {
                    QGraphicsItem* item = sceneMapa->itemAt(scenePos, QTransform());
                    QGraphicsLineItem* line = qgraphicsitem_cast<QGraphicsLineItem*>(item);

                    if (line) {
                        sceneMapa->removeItem(line);
                        delete line;
                        return true;
                    }
                    else if (auto text = qgraphicsitem_cast<QGraphicsTextItem*>(item))
                    {
                        sceneMapa->removeItem(text);
                        delete text;
                        return true;
                    }
                    else if (auto path = qgraphicsitem_cast<QGraphicsPathItem*>(item)) {
                        sceneMapa->removeItem(path);
                        delete path;
                        return true;
                    }
                    else if (auto pix = qgraphicsitem_cast<QGraphicsPixmapItem*>(item)) {
                        // Borrar solo los puntos creados por el usuario
                        if (pix->data(0).toString() == "userPoint") {
                            sceneMapa->removeItem(pix);
                            delete pix;}
                    }
                }
                return false;
            }
            if (m_textMode)
            {
                if (event->type() == QEvent::MouseButtonPress)
                {
                    if (e->button() == Qt::LeftButton)
                    {
                        QGraphicsTextItem* texto = new QGraphicsTextItem("Nuevo texto");
                        texto->setTextInteractionFlags(Qt::TextEditorInteraction);
                        texto->setFont(QFont("Arial", gros+30));
                        texto->setDefaultTextColor(m_currentColor);
                        texto->setFlag(QGraphicsItem::ItemIsMovable);
                        texto->setFlag(QGraphicsItem::ItemIsSelectable);

                        texto->setPos(scenePos);

                        sceneMapa->addItem(texto);
                        return true;
                    }
                }
                return false;
            }
            if (m_pointMode)
            {
                if (event->type() == QEvent::MouseButtonPress)
                {
                    if (e->button() == Qt::LeftButton)
                    {
                        QPixmap pixmap(":/img/icons/punto.png");  // Ruta de recurso
                        if (!pixmap.isNull())
                        {
                            QGraphicsPixmapItem* item = new QGraphicsPixmapItem(pixmap);
                            item->setScale(0.1);
                            QRectF rect = item->boundingRect();
                            QPointF centeredPos = scenePos - QPointF(pixmap.width()*0.1/2.0, pixmap.height()*0.1/2.0);
                            item->setPos(centeredPos);
                            item->setData(0, "userPoint");  // clave 0, valor identificador
                            item->setFlag(QGraphicsItem::ItemIsMovable);
                            item->setFlag(QGraphicsItem::ItemIsSelectable);
                            sceneMapa->addItem(item);
                        }
                        return true;
                    }
                }
                return false;
            }
            if (!m_drawLineMode)
                return QMainWindow::eventFilter(obj, event);
            // Dibujar línea
            if (event->type() == QEvent::MouseButtonPress && e->button() == Qt::RightButton) {
                m_lineStart = scenePos;
                QPen pen(m_currentColor, gros); //cambia al color seleccionado
                m_currentLineItem = new QGraphicsLineItem();
                m_currentLineItem->setZValue(10);
                m_currentLineItem->setPen(pen);
                m_currentLineItem->setLine(QLineF(m_lineStart, m_lineStart));
                sceneMapa->addItem(m_currentLineItem);
                return true;
            }
            else if (event->type() == QEvent::MouseMove && (e->buttons() & Qt::RightButton) && m_currentLineItem) {
                QPointF p2 = scenePos;
                m_currentLineItem->setLine(QLineF(m_lineStart, p2));
                return true;
            }
            else if (event->type() == QEvent::MouseButtonRelease && e->button() == Qt::RightButton && m_currentLineItem) {
                m_currentLineItem = nullptr;
                return true;
            }
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

//##############################################################################################################################
//####################################_DIBUJAR_##############################################################################

void MainWindow::setDrawLineMode(bool enabled)
{
    qDebug() << "DrawLineMode:" << enabled;
    m_drawLineMode = enabled;

    if (m_drawLineMode) {
        ui->graphicsView->setCursor(Qt::CrossCursor);
        ui->graphicsView->setDragMode(QGraphicsView::NoDrag);  // desactiva arrastre
    } else {
        ui->graphicsView->unsetCursor();
        ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag); // vuelve a arrastrar
    }
    if(m_eraserMode){
        m_eraserMode=false;
        ui->goma->setChecked(false);

    }
}
void MainWindow::limpiarTodo()
{
    QList<QGraphicsItem*> items = sceneMapa->items();

    for (QGraphicsItem* item : items)
    {
        if (auto line = qgraphicsitem_cast<QGraphicsLineItem*>(item))
        {
            sceneMapa->removeItem(line);
            delete line;
        }
        else if (auto text = qgraphicsitem_cast<QGraphicsTextItem*>(item))
        {
            sceneMapa->removeItem(text);
            delete text;
        }
        // --- NUEVA CONDICIÓN PARA EL ARCO DEL COMPÁS ---
        else if (auto path = qgraphicsitem_cast<QGraphicsPathItem*>(item))
        {
            sceneMapa->removeItem(path);
            delete path;
        }
        else if (auto pix = qgraphicsitem_cast<QGraphicsPixmapItem*>(item))
        {
            // Borrar solo los puntos creados por el usuario
            if (pix->data(0).toString() == "userPoint") {
                sceneMapa->removeItem(pix);
                delete pix;
            }
        }
    }
}

void MainWindow::borrarGoma(bool enabled)
{
    m_eraserMode = enabled;

    // Cambiar cursor y modo de arrastre
    if (enabled) {
        ui->graphicsView->setCursor(Qt::CrossCursor);
        ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
        // Desactivar el modo de dibujar línea si estaba activo
        if (m_drawLineMode) {
            m_drawLineMode = false;
            ui->linea->setChecked(false);
            ui->graphicsView->unsetCursor();
            //ui->graphicsView->setDragMode(QGraphicsView::NoDrag); // opcional según diseño
        }
        if(m_pointMode){
            m_pointMode=false;
            ui->punto->setChecked(false);     // desactivar punto
        }
    } else {
        ui->graphicsView->unsetCursor();
        ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    }
}

void MainWindow::on_color_clicked()
{
    // Diálogo de color-> QColorDialog::getColor()
    QColor newColor = QColorDialog::getColor(
        m_currentColor,
        this,
        tr("Seleccionar color de dibujo") // Título del diálogo
        );
    //Verificar
    if (newColor.isValid())
    {
        //Actualizar
        m_currentColor = newColor;
        for (QGraphicsItem* item : sceneMapa->items()) {
            if (Compass* compas = dynamic_cast<Compass*>(item)) {
                compas->setDrawingColor(m_currentColor);
            }
        }
        //pista visual de que el color cambió
        qDebug() << "Nuevo color seleccionado:" << m_currentColor.name();
    }
}

//################################################_TEXTO_###########################################################################
void MainWindow::ponerTexto(bool enabled)
{
    m_textMode = enabled;

    if (enabled) {
        ui->graphicsView->setCursor(Qt::IBeamCursor); // cursor de texto
        ui->linea->setChecked(false);    // desactivar modo línea
        m_drawLineMode = false;
        ui->goma->setChecked(false);     // desactivar goma
        m_eraserMode = false;
    } else {
        ui->graphicsView->unsetCursor();
        ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    }
}
//################################################_PUNTO_###########################################################################
void MainWindow::ponerPunto(bool enabled)
{
    m_pointMode = enabled;

    if (enabled) {
        ui->graphicsView->setCursor(Qt::PointingHandCursor); // cursor de mano apuntando
        ui->linea->setChecked(false);    // desactivar modo línea
        m_drawLineMode = false;
        ui->goma->setChecked(false);     // desactivar goma
        m_eraserMode = false;
        ui->texto->setChecked(false);    // desactivar texto
        m_textMode = false;
    } else {
        ui->graphicsView->unsetCursor();
        ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    }
}

//#####################################_REGLAS_#######################################################################################
//funcion para saber las coordenadas actuales del centro de la carta
QPointF MainWindow::getCurrentMapCenter() const
{
    //punto central del viewport
    QPoint viewCenter = view->viewport()->rect().center();

    //Mapear ese punto a coordenadas de la escena (incluye pan y zoom)
    QPointF sceneCenter = view->mapToScene(viewCenter);

    return sceneCenter;
}

void MainWindow::updateToolPositions()
{
    QPoint viewCenter = ui->graphicsView->viewport()->rect().center();

    // La posición Top-Left debe ser el centro del viewport menos la mitad del tamaño de la herramienta en PIXELES DE PANTALLA.

    //Regla:
    if (regla && regla->isVisible()) {
        // Obtenemos el tamaño del objeto en coordenadas de ESCENA (que para ItemIgnoresTransformations es el tamaño en píxeles de pantalla)
        QRectF herrBounds = regla->boundingRect();
        QPointF screenPos = viewCenter - QPointF(herrBounds.width() / 2, herrBounds.height() / 2);
        QPointF scenePos = ui->graphicsView->mapToScene(screenPos.toPoint());

        regla->setPos(scenePos);
    }
    //Transportador:
    if (transportador && transportador->isVisible()) {
        QRectF herrBounds = transportador->boundingRect();
        QPointF screenPos = viewCenter - QPointF(herrBounds.width() / 2, herrBounds.height() / 2);
        QPointF scenePos = ui->graphicsView->mapToScene(screenPos.toPoint());

        transportador->setPos(scenePos);
    }
    //compas:
    if (compas && compas->isVisible()) {
        // Obtenemos el tamaño del objeto en coordenadas de ESCENA
        // (boundingRect funciona para el grupo)
        QRectF herrBounds = compas->boundingRect();
        QPointF screenPos = viewCenter - QPointF(herrBounds.width() / 2, herrBounds.height() / 2);
        QPointF scenePos = ui->graphicsView->mapToScene(screenPos.toPoint());

        compas->setPos(scenePos);
    }
}

void MainWindow::on_Bregla_clicked()
{
    if (!regla) return;
    bool isVisible = !regla->isVisible();
    regla->setVisible(isVisible);

    if (isVisible)
    {
        updateToolPositions();
    }
}

void MainWindow::on_Btransportador_clicked()
{
    if (!transportador) return;
    bool isVisible = !transportador->isVisible();
    transportador->setVisible(isVisible);

    if (isVisible)
    {
        updateToolPositions();
    }
}

void MainWindow::on_Bcompas_clicked()
{
    if (!compas) return;
    bool isVisible = !compas->isVisible();
    compas->setVisible(isVisible);

    if (isVisible)
    {
        updateToolPositions();
    }
}


//##########################################_ZOOM_####################################################################
void MainWindow::applyZoom(double factor){
    double newScale=scale * factor;
    const double minScale=0.01;
    const double maxScale=1;

    if(newScale<minScale){
        factor=minScale/scale;
        newScale=minScale;
    }else if(newScale>maxScale){
        factor=maxScale/scale;
        newScale=maxScale;}
    view->scale(factor,factor);
    scale=newScale;

}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    const int sliderMin = 1;
    const int sliderMax = 100;

    const double targetMinScale = 0.1;
    const double targetMaxScale = 1.0;

    // posición relativa (0.0 a 1.0) del slider
    double normalizedValue = (double)(value - sliderMin) / (sliderMax - sliderMin);
    // Mapea la posición relativa al rango de escalado deseado
    double desiredNewScale = targetMinScale + normalizedValue * (targetMaxScale - targetMinScale);

    // Comprobar si hay un cambio significativo en la escala y evitar división por cero.
    // Usamos 'scale' como la variable actual de la escala del mapa.
    if (qAbs(desiredNewScale - scale) > 0.0001 && scale != 0.0)
    {
        // Factor de cambio = (Escala Deseada) / (Escala Actual)
        double factor = desiredNewScale / scale;
        applyZoom(factor);
        updateToolPositions();
    }
}

//#################################_BARRA INFERIOR COORD/ACTIV_###################################################

void MainWindow::updateStatusLabel(const QPointF &scenePos, const QString &status)
{
    //scenePos y status los recibe desde eventFilter
    QString xStr = QString::number(scenePos.x(), 'f', 1); // Convierte X a string con 1 decimal
    QString yStr = QString::number(scenePos.y(), 'f', 1); // Convierte Y a string con 1 decimal

    QString coordText = QString("Posición (Escena): X=%1, Y=%2")
                            .arg(xStr)
                            .arg(yStr);

    QString fullText = coordText + " | Estado: " + status;

    // Actualizar el QLabel en la UI
    ui->labelStatus->setText(fullText);
}

//####################################_BLOQUEAR BARRA SUP_##########################################
void MainWindow::actualizarEstadoMenuSuperior() {
    QWidget* paginaActual = ui->stackedWidget->currentWidget();

    // Creamos o recuperamos el efecto de opacidad
    QGraphicsOpacityEffect *efecto = qobject_cast<QGraphicsOpacityEffect*>(ui->MenuSup->graphicsEffect());
    if (!efecto) {
        efecto = new QGraphicsOpacityEffect(ui->MenuSup);
        ui->MenuSup->setGraphicsEffect(efecto);
    }

    if (paginaActual == ui->ini_sesion || paginaActual == ui->registro) {
        ui->MenuSup->setEnabled(false);
        efecto->setOpacity(0.5); // Ahora sí funciona a través del efecto
    } else {
        ui->MenuSup->setEnabled(true);
        efecto->setOpacity(1.0);
    }
}

//##################################_REGISTRO_INI.SESION_##########################################################
//##################################_REGISTRO_##########################################################
void MainWindow::on_boton_registro_clicked()
{
    // Ocultar errores
    ui->error_user->hide();
    ui->error_correo->hide();
    ui->error_pass->hide();
    ui->error_edad->hide();

    QString usuario = ui->campo_name->text();
    QString correo = ui->campo_correo->text();
    QString password = ui->campo_pass_2->text();
    QDate nacimiento = ui->campo_cumple->date();

    bool valido = true;

    // Usuario: 6–15 caracteres o dígitos, sin espacios, permite - y _
    QRegularExpression reUser("^[A-Za-z0-9_-]{6,15}$");
    if (!reUser.match(usuario).hasMatch()) {
        ui->error_user->setText(
            "Usuario entre 6 y 15 caracteres o dígitos (letras, números, - o _)"
            );
        ui->error_user->setStyleSheet("color:red;");
        ui->error_user->show();
        valido = false;
    }

    // Correo electrónico
    QRegularExpression reMail("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
    if (!reMail.match(correo).hasMatch()) {
        ui->error_correo->setText("Correo electrónico no válido");
        ui->error_correo->setStyleSheet("color:red;");
        ui->error_correo->show();
        valido = false;
    }

    // Contraseña
    QRegularExpression rePass(
        "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[!@#$%&*()\\-+=]).{8,20}$"
        );
    if (!rePass.match(password).hasMatch()) {
        ui->error_pass->setText(
            "8-20 caracteres, mayúscula, minúscula, número y carácter especial"
            );
        ui->error_pass->setStyleSheet("color:red;");
        ui->error_pass->show();
        valido = false;
    }

    // Edad > 16
    if (nacimiento.addYears(16) > QDate::currentDate()) {
        ui->error_edad->setText("Debes tener más de 16 años");
        ui->error_edad->setStyleSheet("color:red;");
        ui->error_edad->show();
        valido = false;
    }

    // Registro correcto
    // Registro correcto
    if (valido) {
        try {
            Navigation &nav = Navigation::instance();

            // Usuario ya existe
            if (nav.findUser(usuario)) {
                ui->error_user->setText("El nombre de usuario ya existe");
                ui->error_user->show();
                return;
            }

            // Crear usuario con avatar seleccionado
            User u(
                usuario,
                correo,
                password,
                avatarRegistro,   // avatar que seleccionaste
                nacimiento
                );

            nav.addUser(u);

            // Establecer usuario actual para modificar perfil
            m_usuarioActual = usuario;

            // Limpiar campos
            ui->campo_name->clear();
            ui->campo_correo->clear();
            ui->campo_pass_2->clear();

            // NOTA: No cambiamos tu flujo, seguimos a menu_principal
            ui->stackedWidget->setCurrentWidget(ui->mapa);
            ui->stackedWidget_2->setCurrentWidget(ui->menu_principal);

        } catch (const NavDAOException &ex) {
            QMessageBox::critical(this, tr("DB error"), ex.what());
        }
    }

}
void MainWindow::on_link_registro_linkActivated(const QString &)
{
    ui->stackedWidget->setCurrentWidget(ui->registro);
}



void MainWindow::on_calendario_clicked(const QDate &date)
{
    // Pasar la fecha del calendario al QDateEdit
    ui->campo_cumple->setDate(date);
}

void MainWindow::on_editar_avatar2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Seleccionar Imagen de Perfil"),
        "",
        tr("Imágenes (*.png *.jpg *.jpeg *.bmp)")
        );

    if (!fileName.isEmpty()) {
        QImage imagen(fileName);

        if (!imagen.isNull()) {
            // Vista previa en registro
            ui->avatarRegistro->setPixmap(QPixmap::fromImage(imagen));
            ui->avatarRegistro->setScaledContents(true);

            // Guardar temporalmente si lo necesitas
            avatarRegistro = imagen;

            // --- Crear avatar circular ---
            int size = ui->B_MenuUsuario->width(); // Usamos el ancho del botón para tamaño
            QPixmap pixmap = QPixmap::fromImage(imagen).scaled(size, size, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

            QPixmap circularPixmap(size, size);
            circularPixmap.fill(Qt::transparent);

            QPainter painter(&circularPixmap);
            painter.setRenderHint(QPainter::Antialiasing);
            QPainterPath path;
            path.addEllipse(0, 0, size, size); // Dibuja círculo
            painter.setClipPath(path);
            painter.drawPixmap(0, 0, pixmap);

            // Asignar al botón
            ui->B_MenuUsuario->setIcon(QIcon(circularPixmap));
            ui->B_MenuUsuario->setIconSize(QSize(size, size));

            qDebug() << "Avatar actualizado en registro y en B_MenuUsuario:" << fileName;
        } else {
            QMessageBox::warning(this, "Error", "No se pudo cargar la imagen.");
        }
    }
}



// Inicio sesión
void MainWindow::on_boton_entrar_clicked()
{
    QString usuario = ui->campo_user->text();
    QString password = ui->campo_pass->text();

    if (usuario.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this,
                             "Error",
                             "Introduce usuario y contraseña");
        return;
    }

    try {
        Navigation &nav = Navigation::instance();
        const User *u = nav.findUser(usuario);
        ui->B_MenuUsuario->setIcon(QPixmap::fromImage(u->avatar()));

        // Usuario o contraseña incorrectos
        if (!u || u->password() != password) {
            QMessageBox::critical(this,
                                  "Error de autenticación",
                                  "Usuario o contraseña incorrectos");
            return;
        }

        // ===== LOGIN CORRECTO =====

        // Guardar usuario actual
        m_usuarioActual = usuario;

        // Limpiar campos
        ui->campo_user->clear();
        ui->campo_pass->clear();

        //EDITADO- Ya va

        // Cambiar a la ventana principal (mapa)
        ui->stackedWidget->setCurrentWidget(ui->mapa);
        ui->stackedWidget_2->setCurrentWidget(ui->menu_principal);

        // Mostrar problema aleatorio directamente
        //on_boton_aleat_clicked();

    } catch (const NavDAOException &ex) {
        QMessageBox::critical(this, tr("DB error"), ex.what());
    }
}
