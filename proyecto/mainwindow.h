#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <qlistwidget.h>
//#include <QGraphicsSvgItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_arco_clicked();
    void on_boton_lista_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *sceneMenu;
    QGraphicsScene *sceneMapa;
    QGraphicsScene *sceneCompas;
    QGraphicsView *view;
    double scale=1.0;
    void applyZoom(double factor);
};
#endif // MAINWINDOW_H
