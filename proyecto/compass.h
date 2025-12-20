#ifndef COMPAS_H
#define COMPAS_H

#include <QGraphicsItemGroup>
#include <QGraphicsSvgItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QtMath>

class Compass : public QGraphicsItemGroup
{
public:
    Compass(const QString &svgPath, QGraphicsItem *parent = nullptr);

    // Detección de la zona activa (coordenadas de ESCENA)
    bool isCursorInRotationZone(const QPointF& scenePos);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;
    void updateTransformOrigin();
    // Punta de una pata
    QPointF tipOfLeg(QGraphicsSvgItem *leg) const;

private:
    // Patas del compás
    QGraphicsSvgItem *compas1; // Pata FIJA
    QGraphicsSvgItem *compas2; // Pata MÓVIL

    // Zona de detección para abrir/cerrar
    QGraphicsRectItem *m_detectionTip = nullptr;

    // Apertura
    qreal m_initialAngle = 0.0;
    qreal m_mouseClickAngle = 0.0;
    bool m_isRotating = false;

    // Rotación general
    double m_angleDeg = 0.0;

    // Escala
    const qreal SCALE_FACTOR = 4.0;

    // Dibujo de círculo
    bool m_isDrawingCircle = false;
    QGraphicsEllipseItem* m_circleItem = nullptr;
    QPointF m_fixedPointScene;
    qreal m_circleRadius = 0.0;
    QGraphicsPathItem* m_currentPathItem = nullptr; // ítem del camino que dibuja la punta
    QPainterPath m_currentPath;                     // camino actual
    // En la sección private de tu clase:
    QGraphicsPathItem *m_arcItem = nullptr;
    QPainterPath m_arcPath;
    qreal m_startAngle; // Para saber dónde empezó el trazo
    qreal m_lastAngle;

};

#endif // COMPAS_H
