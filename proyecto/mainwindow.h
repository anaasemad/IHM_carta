#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QGraphicsLineItem>
#include "tool.h"

#include <qlistwidget.h>
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

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_Btransportador_clicked();
    void on_Bregla_clicked();
    void on_boton_lista_clicked();
    void setDrawLineMode(bool enabled);
 //   void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_horizontalSlider_valueChanged(int value);
    void limpiarTodo();
    void borrarGoma(bool enabled);
    void ponerTexto(bool enabled);

private:
    Ui::MainWindow *ui;
   // QGraphicsScene *sceneMenu;
    QGraphicsScene *sceneMapa;
  //  QGraphicsScene *sceneCompas;
    QGraphicsView *view;
    double scale=1.0;

    Tool* transportador = nullptr; //inicializar en null por si para evitar errores
    Tool* regla = nullptr;

    void applyZoom(double factor);
    QAction *m_actDrawLine = nullptr;
    bool m_eraserMode = false;
    bool m_drawLineMode = false;
    bool m_textMode = false;
    QGraphicsLineItem *m_tempLine = nullptr;
    QGraphicsLineItem *m_currentLineItem = nullptr;
    QPointF m_lineStart;

    QPointF getCurrentMapCenter() const; //función para saber el centro actual de la carta
    void updateToolPositions();

    void updateStatusLabel(const QPointF &scenePos, const QString &status); //label coordenadas y actividad
};
#endif // MAINWINDOW_H
