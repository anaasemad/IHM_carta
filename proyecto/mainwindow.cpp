#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QAction>

#include <QMouseEvent> // NUEVO
#include <QKeyEvent> // NUEVO
#include <QPen> // NUEVO
#include <QApplication> // NUEVO
#include <QDebug>

#include "tool.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    sceneMapa(new QGraphicsScene(this))
  // ,sceneCompas(new QGraphicsScene(this))


{
    ui->setupUi(this);
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



   // view->setScene(sceneMenu);
   // view->setScene(sceneMapa);


    QPixmap mapa(":/img/carta_nautica");


    QGraphicsPixmapItem *itemMapa = sceneMapa->addPixmap(mapa);
    itemMapa->setZValue(0);
    itemMapa->setScale(0.25);

    ui->graphicsView->setScene(sceneMapa);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

//NUEVO

    ui->horizontalSlider->setValue(60);//val inicial

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


/*void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->stackedWidget_2->setCurrentWidget(ui->problema);
}*/

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    int gros = ui->grosor->value();
    if (obj == ui->graphicsView->viewport()) {

        if (event->type() == QEvent::MouseButtonPress ||
            event->type() == QEvent::MouseButtonRelease ||
            event->type() == QEvent::MouseMove)
        {
            auto *e = static_cast<QMouseEvent*>(event);
            QPointF scenePos = ui->graphicsView->mapToScene(e->pos());

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
                }
                return false;
            }
            if (m_textMode)
            {
                if (event->type() == QEvent::MouseButtonPress)
                {
                    auto *e = static_cast<QMouseEvent*>(event);
                    if (e->button() == Qt::LeftButton)
                    {
                        QPointF scenePos = ui->graphicsView->mapToScene(e->pos());

                        // Crear item de texto
                        QGraphicsTextItem* texto = new QGraphicsTextItem("Nuevo texto");
                        texto->setTextInteractionFlags(Qt::TextEditorInteraction);
                        texto->setFont(QFont("Arial", gros));
                        texto->setDefaultTextColor(Qt::black);
                        texto->setFlag(QGraphicsItem::ItemIsMovable);
                        texto->setFlag(QGraphicsItem::ItemIsSelectable);

                        texto->setPos(scenePos);

                        sceneMapa->addItem(texto);

                        return true; // consumimos el evento
                    }
                }

                return false;
            }

            if (!m_drawLineMode)
                return QMainWindow::eventFilter(obj, event);

            // Dibujar línea
            if (event->type() == QEvent::MouseButtonPress && e->button() == Qt::RightButton) {
                m_lineStart = scenePos;



                QPen pen(Qt::red, gros);
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
//####################################  DIBUJAR   ##############################################################################

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
    } else {
        ui->graphicsView->unsetCursor();
        ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    }
}

//################################################TEXTO###########################################################################
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


//#####################################REGLAS#######################################################################################
//funcion para saber las coordenadas actuales del centro de la carta
QPointF MainWindow::getCurrentMapCenter() const
{
    //punto central del viewport
    QPoint viewCenter = view->viewport()->rect().center();

    //Mapear ese punto a coordenadas de la escena (incluye pan y zoom)
    QPointF sceneCenter = view->mapToScene(viewCenter);

    return sceneCenter;
}

void MainWindow::on_Bregla_clicked()
{
    if (!regla) return;

    // visibilidad
    bool isVisible = !regla->isVisible();
    regla->setVisible(isVisible);

    //posicionar en el centro
    if (isVisible)
    {
        // centro del mapa
        QPointF sceneCenter = getCurrentMapCenter();
        //tamaño de la herramienta para centrarlo (si no se coloca la esquina sup izq del item)
        QRectF herrBounds = regla->boundingRect();
        //posición corregida
        QPointF posCorregida = sceneCenter - QPointF(herrBounds.width() / 2, herrBounds.height() / 2);
        regla->setPos(posCorregida);
    }
}
void MainWindow::on_Btransportador_clicked()
{
    if (!transportador) return;

    // visibilidad
    bool isVisible = !transportador->isVisible();
    transportador->setVisible(isVisible);

    //posicionar en el centro
    if (isVisible)
    {
        // centro del mapa
        QPointF sceneCenter = getCurrentMapCenter();
        //tamaño de la herramienta para centrarlo (si no se coloca la esquina sup izq del item)
        QRectF herrBounds = transportador->boundingRect();
        //posición corregida
        QPointF posCorregida = sceneCenter - QPointF(herrBounds.width() / 2, herrBounds.height() / 2);
        transportador->setPos(posCorregida);
    }
}

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
    }

}

