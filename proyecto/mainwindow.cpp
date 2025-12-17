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

#include <QStandardItemModel>

#include <QSplitter>
#include <QHBoxLayout>

#include "navigation.h"
#include "navdaoexception.h"



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
    //*************************************************************BARRA HERRAMIENTAS

    ui->widget_2->setAttribute(Qt::WA_StyledBackground, true);
    ui->widget_2->setStyleSheet(
        "QWidget#widget_2 { background-color:  #D5D5D5;}"//barra herramientas gris claro
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
        ui->stackedWidget->setCurrentWidget(ui->editar_perfil);
    });

    connect(actionCerrarSesion, &QAction::triggered, this, [=]() {
        // Lógica para cerrar sesión, por ejemplo volver al login_________TEMPORAL!!!!
        ui->stackedWidget->setCurrentWidget(ui->ini_sesion);
    });

    //colores barra:
    ui->MenuSup->setAttribute(Qt::WA_StyledBackground, true);
    ui->MenuSup->setStyleSheet(
        "QWidget#MenuSup { background-color:  #CED9E4;}"
        );
    //boton usuario
    ui->B_MenuUsuario->setFixedSize(60, 60);

    ui->B_MenuUsuario->setStyleSheet(
        "QPushButton {"
        "  background-color: #4E7592;"
        "  border-radius: 30px;"//radio
        "  border: 2px solid white;"
        "}"
        "QPushButton::menu-indicator { image: none; }" // Quita la flechita del menú
        );

//#################################################################################BOTONES PROBLEMAS
    ui->boton_alet->setAttribute(Qt::WA_StyledBackground, true);
    ui->boton_alet->setStyleSheet(
        "QWidget#boton_alet { background-color:  #404064;}");

    ui->boton_lista->setAttribute(Qt::WA_StyledBackground, true);
    ui->boton_lista->setStyleSheet(
        "QWidget#boton_lista { background-color:  #404064;}");



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


void MainWindow::on_boton_lista_clicked()
{
     ui->stackedWidget_2->setCurrentWidget(ui->lista_problemas);
}


//#############################################################################################
//################### historial ####################
void MainWindow::setupHistorialTable()
{
    // --- 1. Gestión de Excepciones y Acceso al Singleton ---
    try {
        Navigation &nav = Navigation::instance();

        // --- 2. Obtener el Usuario y Sesiones ---
        // Debes saber qué usuario es el actual. Asumo que el nick es "alumno" como en el código del profesor.
        const User *currentUser = nav.findUser("user1");

        if (!currentUser) {
            qDebug() << "ERROR: Usuario 'alumno' no encontrado para cargar historial.";
            // Si el modelo existente es QSqlQueryModel, necesitamos cambiarlo para usar QStandardItemModel.
            // Para simplificar, si no hay usuario, retornamos.
            return;
        }

        const QList<Session> &sessions = currentUser->sessions();

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

            QDateTime timestamp = s.timeStamp();

            QString dateString;

            if (timestamp.isValid()) {
                // Este formato de salida es más estándar y visible en la tabla:
                dateString = timestamp.toString("dd/MM/yyyy hh:mm:ss");
            } else {
                // Si sigue siendo inválido, indica que la capa Navigation no lo lee bien.
                dateString = "Timestamp Inválido o Nulo";
            }

            // DEBUG: Muestra la cadena que se está añadiendo (¡MUY IMPORTANTE!)
            qDebug() << "DEBUG Fecha a tabla: " << dateString;

            row.append(new QStandardItem(dateString));
            row.append(new QStandardItem(QString::number(s.hits())));
            row.append(new QStandardItem(QString::number(s.faults())));

            stdModel->appendRow(row);
        }

        // --- 5. Asignar el nuevo modelo a la tabla ---
        // ¡IMPORTANTE! Si ya había un modelo, Qt lo liberará automáticamente si le pones 'this' como padre.
        ui->tableViewHistorial->setModel(stdModel);
        ui->tableViewHistorial->setColumnWidth(0, 180); // Un poco más ancho para el formato completo
        ui->tableViewHistorial->resizeColumnsToContents();

    } catch (const NavDAOException &ex) {
        // Mostrar un mensaje de error si hay un problema al acceder a Navigation (ej: BBDD cerrada)
        QMessageBox::critical(this, tr("Error de BBDD"), tr("No se pudo cargar el historial: %1").arg(ex.what()));
    }
}

void MainWindow::on_boton_historial_clicked()
{
    m_previousWidgetIndex = ui->stackedWidget->currentIndex();

    ui->stackedWidget->setCurrentWidget(ui->historial);
}
void MainWindow::on_Modificar_perfil_clicked()
{
    m_previousWidgetIndex = ui->stackedWidget->currentIndex();

    ui->stackedWidget->setCurrentWidget(ui->editar_perfil);
}
void MainWindow::on_Boton_volver_clicked()
{
    ui->stackedWidget->setCurrentIndex(m_previousWidgetIndex);
}
void MainWindow::on_Boton_volver_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(m_previousWidgetIndex);
}

//#############################################################################################



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


//##################################_REGISTRO_INI.SESION_##########################################################
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
    QDate nacimiento = ui->campo_cumple->date();

    bool valido = true;

    // Usuario
    QRegularExpression reUser("^[A-Za-z0-9_-]{6,15}$");
    if (!reUser.match(usuario).hasMatch()) {
        ui->error_user->setText(
            "Usuario entre 6 y 15 caracteres (letras, números, - o _)"
            );
        ui->error_user->setStyleSheet("color:red;");
        ui->error_user->show();
        valido = false;
    }

    // Correo
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
    if (valido) {
        try {
            Navigation &nav = Navigation::instance();

            // Usuario ya existe
            if (nav.findUser(usuario)) {
                ui->error_user->setText("El nombre de usuario ya existe");
                ui->error_user->show();
                return;
            }

            // Crear usuario
            User u(
                usuario,
                correo,
                password,
                QImage(),      // avatar por defecto
                nacimiento
                );

            nav.addUser(u);

            QMessageBox::information(this, "DEBUG", "Registro correcto");

            //
            ui->stackedWidget->setCurrentWidget(ui->ini_sesion);


        } catch (const NavDAOException &ex) {
            QMessageBox::critical(this, tr("DB error"), ex.what());
        }
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

    try {
        Navigation &nav = Navigation::instance();

        const User *u = nav.findUser(usuario);

        // Usuario no existe
        if (!u) {
            QMessageBox::critical(
                this,
                "Error de autenticación",
                "Usuario o contraseña incorrectos"
                );
            return;
        }

        // Contraseña incorrecta  (Cambiar a text label oculto si no gusta q salga así)
        if (u->password() != password) {
            QMessageBox::critical(
                this,
                "Error de autenticación",
                "Usuario o contraseña incorrectos"
                );
            return;
        }

        // Login correcto → acceso al sistema
        ui->campo_user->clear();
        ui->campo_pass->clear();

        // No se porque no me va a lista de problemas

        ui->stackedWidget_2->setCurrentWidget(ui->lista_problemas);

    } catch (const NavDAOException &ex) {
        QMessageBox::critical(this, tr("DB error"), ex.what());
    }
}

void MainWindow::on_label_registro_linkActivated(const QString &)
{
    // No me cambia de pagina mirarlo
    ui->stackedWidget->setCurrentWidget(ui->registro);
}

// realmente creo q lo unico q falla es el cambio de ventana, el resto creo q esta bien


