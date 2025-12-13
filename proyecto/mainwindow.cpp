#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "tool.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsScale>
#include <QListWidget>
//#include "navigation.h"
//#include "navdaoexception.h"
#include <QMessageBox>
#include <QDate>
#include <QDateTime>




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
    QPixmap regla(":/img/icons/ruler");


    QGraphicsPixmapItem *itemMapa = sceneMapa->addPixmap(mapa);
    //QGraphicsPixmapItem *ruler = scene->addPixmap(regla);
    itemMapa->setZValue(0);
    itemMapa->setScale(0.25);

    ui->carta_mapa->setScene(sceneMapa);
    ui->carta_mapa->setDragMode(QGraphicsView::ScrollHandDrag);

   // Tool *compas=new Tool(":/resources/img/icons/compass_leg.svg");
    //sceneCompas->addItem(compas);
   // scene->addItem(transportador);
   // ui->carta_mapa->setScene(sceneCompas);
   // ui->carta_mapa->setDragMode(QGraphicsView::ScrollHandDrag);

    //transportador->setToolSize(300);
    //transportador->setPos(200, 200);
    //herramientas
   // transportador=new Tool(":/resources/img/transportador.svg", this);
    //transportador->setToolSize()
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
void MainWindow::on_arco_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->ini_sesion);
}



void MainWindow::on_boton_lista_clicked()
{
     ui->stackedWidget_2->setCurrentWidget(ui->lista_problemas);
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->stackedWidget_2->setCurrentWidget(ui->problema);
}

