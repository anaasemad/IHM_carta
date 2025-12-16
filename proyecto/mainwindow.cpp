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

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>

#include <QSplitter>
#include <QHBoxLayout>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    sceneMapa(new QGraphicsScene(this))
  // ,sceneCompas(new QGraphicsScene(this))


{
    ui->setupUi(this);
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
    QHBoxLayout *layout = new QHBoxLayout(ui->horizontalWidget);
    layout->setContentsMargins(0, 0, 0, 0); // para que ocupe todo el widget
    layout->setSpacing(0);
    layout->addWidget(splitter);
    //*************************************************************

    ui->widget_2->setAttribute(Qt::WA_StyledBackground, true);
    ui->widget_2->setStyleSheet(
        "QWidget#widget_2 { background-color:  #FFFFFF;}"//*****************barra herramientas blanca
        );


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

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_boton_lista_clicked()
{
     ui->stackedWidget_2->setCurrentWidget(ui->lista_problemas);
}


//#############################################################################################
void MainWindow::on_boton_historial_clicked()
{
    m_previousWidgetIndex = ui->stackedWidget->currentIndex();

    ui->stackedWidget->setCurrentWidget(ui->historial);
}

void MainWindow::on_boton_Modificar_perfil()
{
    m_previousWidgetIndex = ui->stackedWidget->currentIndex();

    ui->stackedWidget->setCurrentWidget(ui->editar_perfil);
}


void MainWindow::on_boton_volver_clicked()
{
    ui->stackedWidget->setCurrentIndex(m_previousWidgetIndex);
}
void MainWindow::on_boton_volver_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(m_previousWidgetIndex);
}


/*bool MainWindow::initDatabase()
{
    qDebug() << "he llamado a init bbdd";
    // Carga el driver y crea una conexión
    m_db = QSqlDatabase::addDatabase("QSQLITE");

    // NOTA: El archivo .sqlite debe estar en la carpeta de ejecución de tu proyecto (build)
    m_db.setDatabaseName("C:/Users/bolum/Documents/IHM/GITHUB/IHM_carta/navdb/navdb.sqlite");

    if (!m_db.open()) {
        qDebug() << "Error al abrir la base de datos:" << m_db.lastError().text();
        return false;
    }

    qDebug() << "Conexión a la BBDD 'navdb.sqlite' establecida correctamente.";

    QStringList tables = m_db.tables();
    if (tables.isEmpty()) {
        qDebug() << "ADVERTENCIA: No se encontraron tablas en la BBDD, ¿está vacía?";
    } else {
        qDebug() << "Tablas encontradas:" << tables; // Esto nos dirá el nombre REAL de la tabla
    }

    // Configurar el modelo la primera vez
    //setupHistorialTable();

    return true;
}

void MainWindow::setupHistorialTable()
{
    qDebug() << "he entrado en setup";
    // 1. Inicialización del modelo (para evitar el error "No model set")
    if (m_historialModel) {
        delete m_historialModel;
    }
    qDebug() << "primera funcion";
    m_historialModel = new QSqlQueryModel(this);

    qDebug() << "segunda funcion";

    // Asignamos el modelo inmediatamente (incluso si está vacío)
    ui->tableViewHistorial->setModel(m_historialModel); // Importante que esto esté antes del posible fallo
    qDebug() << "despues de asignar modelo";

    if (!m_db.isOpen()) {
        qDebug() << "ADVERTENCIA: La BBDD no está abierta. Mostrando tabla vacía.";
    } else {
        qDebug() << "DEBUG 1: BBDD abierta. Preparando consulta."; // <-- Nuevo Debug 1

        // La consulta con la corrección de la tabla 'session'
        //const QString queryStr = "SELECT timeStamp, hits, faults FROM session ORDER BY timeStamp DESC";
        //const QString queryStr = "SELECT * FROM session"; // <-- ¡NUEVA PRUEBA CRÍTICA!
        const QString queryStr = "SELECT * FROM user"; // <-- ¡NUEVA PRUEBA CRÍTICA!

        //El fallo casi seguro ocurre en la siguiente línea:
        m_historialModel->setQuery(queryStr, m_db);

        qDebug() << "DEBUG 2: Consulta ejecutada. Verificando errores SQL."; // <-- Nuevo Debug 2

        if (m_historialModel->lastError().isValid()) {
            qDebug() << "Error en la consulta SQL:" << m_historialModel->lastError().text();
            qDebug() << "La consulta fallida fue:" << queryStr;
        }
    }

    // 3. Configura los encabezados de las columnas (funciona incluso si no hay datos)
    m_historialModel->setHeaderData(0, Qt::Horizontal, tr("Fecha / Sesión"));
    m_historialModel->setHeaderData(1, Qt::Horizontal, tr("Aciertos"));
    m_historialModel->setHeaderData(2, Qt::Horizontal, tr("Fallos"));

    ui->tableViewHistorial->resizeColumnsToContents();

    qDebug() << "DEBUG 3: Configuración de tabla finalizada."; // <-- Nuevo Debug 3
}

void MainWindow::on_boton_historial_clicked()
{

    //##################################################################################################
    // --- 1. Inicializar la BBDD ---
    if (!initDatabase()) {
        qDebug() << "ERROR: Falló la inicialización de la BBDD. La aplicación no funcionará correctamente.";
    } else{
        qDebug() << "he iniciado la bbdd";
    }
    //##################################################################################################
    // 1. Corregido el stackedWidget (ver respuesta anterior)


    ui->stackedWidget->setCurrentWidget(ui->historial);

    // 2. Recargar/Actualizar los datos del modelo al entrar en la página
    if (m_historialModel) {
        // Ejecuta de nuevo la consulta para mostrar datos frescos
        qDebug() << "antes de setup";
       setupHistorialTable();
        if (m_historialModel->lastError().isValid()) {
            qDebug() << "Error al recargar el modelo:" << m_historialModel->lastError().text();
        }
    } else {
        // Si por alguna razón el modelo es null, intenta configurarlo de nuevo
        setupHistorialTable();
    }

}

//#############################################################################################
*/



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
        // BLOQUE 1: MANEJO DE MOUSE MOVE (Actualización de Coordenadas/Estado)
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
            }
            //AÑADIR COMPÁS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
                        texto->setFont(QFont("Arial", gros));
                        texto->setDefaultTextColor(Qt::black);
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

// Registrarse
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
    QDate nacimiento = ui->campo_cumple->date(); //

    bool valido = true;

    //
    QRegularExpression reUser("^[A-Za-z0-9_-]{6,15}$");
    if (!reUser.match(usuario).hasMatch()) {
        ui->error_user->setText(
            "Usuario entre 6 y 15 caracteres (letras, números, - o _)"
            );
        ui->error_user->setStyleSheet("color:red;");
        ui->error_user->show();
        valido = false;
    }

    //
    QRegularExpression reMail("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
    if (!reMail.match(correo).hasMatch()) {
        ui->error_correo->setText("Correo electrónico no válido");
        ui->error_correo->setStyleSheet("color:red;");
        ui->error_correo->show();
        valido = false;
    }

    //
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

    // EDAD > 16
    if (nacimiento.addYears(16) > QDate::currentDate()) {
        ui->error_edad->setText("Debes tener más de 16 años");
        ui->error_edad->setStyleSheet("color:red;");
        ui->error_edad->show();
        valido = false;
    }

    // Cambiar para después
    if (valido) {
        QMessageBox::information(
            this,
            "Registro completado",
            "Usuario registrado correctamente"
            );


        // Aquí luego:
        // Guardar usuario registrado
        usuarioRegistrado = usuario;
        passwordRegistrado = password;

        // Ir a la pantalla de inicio de sesión
        ui->stackedWidget->setCurrentWidget(ui->ini_sesion);

    }


}

void MainWindow::on_calendario_clicked(const QDate &date)
{
    // Pasar la fecha del calendario al QDateEdit
    ui->campo_cumple->setDate(date);
}



// Inicio sesion
void MainWindow::on_boton_entrar_clicked()
{
    QString usuario = ui->campo_user->text();
    QString password = ui->campo_pass->text();


    if (usuario.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(
            this,
            "Error",
            "Introduce usuario y contraseña"
            );
        return;
    }

    // Comprobación de usuario existente
    if (usuario == usuarioRegistrado &&
        password == passwordRegistrado) {

        // Login correcto
        ui->campo_user->clear();
        ui->campo_pass->clear();

        // Acceso al resto de funciones
        ui->stackedWidget->setCurrentWidget(ui->menu_principal);

    } else {
        QMessageBox::critical(
            this,
            "Error de autenticación",
            "Usuario o contraseña incorrectos"
            );
    }
}




