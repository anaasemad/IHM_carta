#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QGraphicsLineItem>
#include "tool.h"
#include "compass.h"

#include <QSqlDatabase> // Necesario para la conexión
#include <QSqlQueryModel> // Necesario para el modelo de la tabla

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
    void ponerPunto(bool enabled);

    void on_color_clicked();
    void on_boton_entrar_clicked();
    void on_boton_registro_clicked();
    void on_calendario_clicked(const QDate &date);
    //void on_label_registro_linkActivated(const QString &link);

//#################################################################################################################
    void on_boton_historial_clicked();
    void on_boton_volver_clicked();
    void on_boton_editar_avatar_clicked();
    void on_boton_guardar_clicked();
    void on_listWidget_doubleClicked(const QModelIndex &index);
    void on_corregir_clicked();
    void on_boton_aleat_clicked();
//#################################################################################################################


    void on_Bcompas_clicked();

private:
    Ui::MainWindow *ui;
   // QGraphicsScene *sceneMenu;
    QGraphicsScene *sceneMapa;
  //  QGraphicsScene *sceneCompas;
    QGraphicsView *view;
    double scale=1.0;

    Tool* transportador = nullptr; //inicializar en null por si para evitar errores
    Tool* regla = nullptr;
    Tool* compasFijo = nullptr;
    Compass *compas = nullptr;
    QString m_usuarioActual;

    //#########################################################################################################
    // --- Variables para la BBDD ---
    QSqlDatabase m_db; // Objeto de conexión a la BBDD
    int m_previousWidgetIndex = 0; //para guardar widget anterior para volver
    QSqlQueryModel *m_historialModel = nullptr; // Modelo para vincular datos a tableView
    int m_aciertosActuales = 0;
    int m_fallosActuales = 0;
    int m_problema_actual = -1;
    //const Problem *problemaActual = nullptr;

    // --- Funciones de BBDD ---
    bool initDatabase(); // Inicializa la conexión y el modelo
    void setupHistorialTable(); // Configura la tabla y el modelo
    void setupPerfil();
    void cargarListaProblemas();
    void corregirRespuesta(int indiceSeleccionado);

    //#########################################################################################################



    void applyZoom(double factor);
    QAction *m_actDrawLine = nullptr;
    bool m_eraserMode = false;
    bool m_drawLineMode = false;
    bool m_textMode = false;
    bool m_pointMode = false;
    QGraphicsLineItem *m_tempLine = nullptr;
    QGraphicsLineItem *m_currentLineItem = nullptr;
    QPointF m_lineStart;
    QColor m_currentColor;

    QPointF getCurrentMapCenter() const; //función para saber el centro actual de la carta
    void updateToolPositions();

    void updateStatusLabel(const QPointF &scenePos, const QString &status); //label coordenadas y actividad


};
#endif // MAINWINDOW_H
