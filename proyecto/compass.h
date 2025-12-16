#ifndef COMPAS_H
#define COMPAS_H

#include <QGraphicsSceneWheelEvent>
#include <QSizeF>
#include <QGraphicsItemGroup>
#include <QGraphicsSvgItem>
#include <QGraphicsSceneMouseEvent>
#include <QtMath>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QTransform>


class Compass : public QGraphicsItemGroup
{
public:

    Compass(const QString &svgPath, QGraphicsItem *parent = nullptr);
    // Detección de la zona activa (parte inferior para rotar)
    bool isCursorInRotationZone(const QPointF& localPos);
    QGraphicsRectItem *m_detectionTip;

protected:
    // Redefinición de eventos de ratón para controlar la rotación/apertura
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;
    void wheelEvent(QGraphicsSceneWheelEvent *event); //rotar

private:
    QGraphicsSvgItem *compas2;  // Pata fija
    QGraphicsSvgItem *compas1; // Pata móvil
    qreal m_initialAngle = 0.0;
    qreal m_mouseClickAngle = 0.0;

    bool m_isRotating = false;
    const qreal SCALE_FACTOR =4.0; // Ajustar el tamaño del SVG
    qreal m_pataHeight;           // Altura de la pata escalada
    double m_angleDeg = 0.0;

    //bool m_isDrawingArc = false; // Bandera para saber si estamos en modo arco
    //QGraphicsPathItem *m_currentArcItem = nullptr; // El ítem que dibuja el arco
    //QPainterPath m_currentArcPath; // La trayectoria del arco

    // Almacenamos el radio (la apertura) del arco
    //qreal m_arcRadius = 0.0;
};


#endif // COMPAS_H

