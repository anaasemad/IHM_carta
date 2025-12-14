#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QAction>

#include <QMouseEvent> // NUEVO
#include <QKeyEvent> // NUEVO
#include <QPen> // NUEVO
#include <QApplication> // NUEVO



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    sceneMapa(new QGraphicsScene(this))
  // ,sceneCompas(new QGraphicsScene(this))


{
    ui->setupUi(this);
   // view->setScene(sceneMenu);
   // view->setScene(sceneMapa);


    QPixmap mapa(":/img/carta_nautica");
   // QPixmap regla(":/img/icons/ruler");


    QGraphicsPixmapItem *itemMapa = sceneMapa->addPixmap(mapa);
    //QGraphicsPixmapItem *ruler = scene->addPixmap(regla);
    itemMapa->setZValue(0);
    itemMapa->setScale(0.25);

    ui->graphicsView->setScene(sceneMapa);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

//NUEVO
    //dibuja linea
    m_actDrawLine = ui->linea->addAction(tr("Línea"));
    m_actDrawLine->setCheckable(true);
    connect(m_actDrawLine, &QAction::toggled, this, &MainWindow::setDrawLineMode);

    // ===============================TRANSPORTADOR
    transportador = new Tool(":/img/icons/transportador.svg");
    sceneMapa->addItem(transportador);
    // Tamaño "lógico" aproximado, como antes
    transportador->setToolSize(QSizeF(580, 380));
    // Z alta para que quede en overlay
    transportador->setZValue(1000);
    // Posición inicial en la esquina superior izquierda de la vista
    transportador->setPos(QPointF(20, 20));
    transportador->setVisible(false);
    // ===============================REGLA
    regla = new Tool(":/img/icons/ruler.svg");
    sceneMapa->addItem(regla);
    // Tamaño "lógico" aproximado, como antes
    regla->setToolSize(QSizeF(580, 380));
    // Z alta para que quede en overlay
    regla->setZValue(1000);
    // Posición inicial en la esquina superior izquierda de la vista
    regla->setPos(QPointF(20, 20));
    regla->setVisible(false);

}


MainWindow::~MainWindow()
{
    delete ui;
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
    if (obj == ui->graphicsView->viewport()) {
        if (!m_drawLineMode)
            return false; // no estamos en modo línea, que lo gestione la vista

        if (event->type() == QEvent::MouseButtonPress) {
            auto *e = static_cast<QMouseEvent*>(event);
            if (e->button() == Qt::RightButton) {
                QPointF scenePos = view->mapToScene(e->pos());
                m_lineStart = scenePos;

                QPen pen(Qt::red, 8);
                m_currentLineItem = new QGraphicsLineItem();
                m_currentLineItem->setZValue(10);
                m_currentLineItem->setPen(pen);
                m_currentLineItem->setLine(QLineF(m_lineStart, m_lineStart));
                sceneMapa->addItem(m_currentLineItem);

                return true; // consumimos el evento
            }
        }
        else if (event->type() == QEvent::MouseMove) {
            auto *e = static_cast<QMouseEvent*>(event);
            if (e->buttons() & Qt::RightButton && m_currentLineItem) {
                QPointF p2 = ui->graphicsView->mapToScene(e->pos());
                m_currentLineItem->setLine(QLineF(m_lineStart, p2));
                return true;
            }
        }
        else if (event->type() == QEvent::MouseButtonRelease) {
            auto *e = static_cast<QMouseEvent*>(event);
            if (e->button() == Qt::RightButton && m_currentLineItem) {
                // aquí podrías validar la longitud, borrar si es muy corta, etc.
                m_currentLineItem = nullptr;
                return true;
            }
        }
    }

    return QMainWindow::eventFilter(obj, event);
}


void MainWindow::setDrawLineMode(bool enabled)
{
    m_drawLineMode = enabled;

    if (m_drawLineMode) {
        ui->graphicsView->setCursor(Qt::CrossCursor);
    } else {
        ui->graphicsView->unsetCursor();
    }
}

void MainWindow::on_Bregla_clicked()
{
    if (!regla) return;
    regla->setVisible(!regla->isVisible());
}
void MainWindow::on_Btransportador_clicked()
{
    if (!transportador) return;
    transportador->setVisible(!transportador->isVisible());
}
