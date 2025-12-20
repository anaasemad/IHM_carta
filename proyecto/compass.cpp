#include "compass.h"

#include <QtMath>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainterPath>
#include <QPen>

// ======================================================
// Constructor
// ======================================================
Compass::Compass(const QString &svgPath, QGraphicsItem *parent)
    : QGraphicsItemGroup(parent),
    m_angleDeg(90),
    m_isRotating(false),
    m_isDrawingCircle(false),
    m_arcItem(nullptr)
{
    setFlags(QGraphicsItem::ItemIsMovable |
             QGraphicsItem::ItemIsSelectable);

    setAcceptHoverEvents(true);

    // ---------------- PATA FIJA ----------------
    compas1 = new QGraphicsSvgItem(svgPath, this);
    compas1->setScale(SCALE_FACTOR);
    compas1->setTransformOriginPoint(0, 0);

    // ---------------- PATA MÓVIL ----------------
    compas2 = new QGraphicsSvgItem(svgPath, this);
    compas2->setScale(SCALE_FACTOR);
    compas2->setTransformOriginPoint(0, 0);

    // Apertura inicial
    setRotation(m_angleDeg);
    compas2->setRotation(-30);

    // ---------------- ZONA DE DETECCIÓN (abrir compás) ----------------
    qreal tipSize = 20.0;
    m_detectionTip = new QGraphicsRectItem(
        tipSize * 9,
        0,
        tipSize,
        tipSize,
        compas2
        );

    m_detectionTip->setPen(Qt::NoPen);
    m_detectionTip->setBrush(Qt::transparent);
    m_detectionTip->setZValue(10);

    updateTransformOrigin();
}

void Compass::updateTransformOrigin()
{
    QPointF fixedTipLocal = compas1->mapToParent(tipOfLeg(compas1));
    setTransformOriginPoint(fixedTipLocal);
}

QPointF Compass::tipOfLeg(QGraphicsSvgItem *leg) const
{
    QRectF br = leg->boundingRect();
    return QPointF(br.right(), br.center().y());
}

void Compass::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    const int delta = event->delta();
    if (delta == 0) { event->ignore(); return; }

    double deltaDegrees = (delta / 8.0) * 0.1;
    m_angleDeg += deltaDegrees;
    setRotation(m_angleDeg);
    event->accept();
}

bool Compass::isCursorInRotationZone(const QPointF &scenePos)
{
    QPointF posInTip = m_detectionTip->mapFromScene(scenePos);
    return m_detectionTip->contains(posInTip);
}

// ======================================================
// Mouse Press
// ======================================================
void Compass::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem *clickedItem = scene()->itemAt(event->scenePos(), QTransform());

    if (event->button() == Qt::LeftButton && (event->modifiers() & Qt::ShiftModifier))
    {
        // Solo si pinchamos en el cuerpo del compás
        if (clickedItem == compas1 || clickedItem == compas2 || isAncestorOf(clickedItem))
        {
            m_fixedPointScene = mapToScene(transformOriginPoint());
            QPointF movingTipScene = compas2->mapToScene(tipOfLeg(compas2));

            m_circleRadius = QLineF(m_fixedPointScene, movingTipScene).length();

            // Guardamos el ángulo inicial
            m_lastAngle = QLineF(m_fixedPointScene, movingTipScene).angle();

            // Iniciamos un Path vacío
            m_currentPath = QPainterPath();
            m_currentPath.moveTo(movingTipScene);

            m_arcItem = new QGraphicsPathItem();
            m_arcItem->setPen(QPen(Qt::blue, 2, Qt::SolidLine, Qt::RoundCap));
            m_arcItem->setZValue(5);
            scene()->addItem(m_arcItem);

            m_isDrawingCircle = true;
            event->accept();
            return;
        }
    }

    if (event->button() == Qt::LeftButton && isCursorInRotationZone(event->scenePos()))
    {
        m_isRotating = true;
        m_initialAngle = compas2->rotation();
        QPointF mousePos = event->pos();
        qreal angleRad = qAtan2(-mousePos.x(), mousePos.y());
        m_mouseClickAngle = qRadiansToDegrees(angleRad);
        event->accept();
        return;
    }

    QGraphicsItemGroup::mousePressEvent(event);
}

// ======================================================
// Mouse Move
// ======================================================
void Compass::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_isDrawingCircle)
    {
        QPointF mouse = event->scenePos();

        // 1. Rotar el compás para que siga al ratón
        qreal angleRad = qAtan2(mouse.y() - m_fixedPointScene.y(),
                                mouse.x() - m_fixedPointScene.x());
        setRotation(qRadiansToDegrees(angleRad));

        // 2. Calcular el nuevo arco a añadir
        QPointF currentMovingTip = compas2->mapToScene(tipOfLeg(compas2));
        QLineF currentLine(m_fixedPointScene, currentMovingTip);
        qreal currentAngle = currentLine.angle();

        // Diferencia entre el ángulo anterior y el actual
        qreal sweep = currentAngle - m_lastAngle;

        // Corrección para el cruce de 0/360 grados
        if (sweep > 180) sweep -= 360;
        if (sweep < -180) sweep += 360;

        // Rectángulo para el arco
        QRectF rect(m_fixedPointScene.x() - m_circleRadius,
                    m_fixedPointScene.y() - m_circleRadius,
                    m_circleRadius * 2,
                    m_circleRadius * 2);

        // AÑADIR el segmento al path existente (permite > 360 grados)
        m_currentPath.arcTo(rect, m_lastAngle, sweep);
        m_arcItem->setPath(m_currentPath);

        m_lastAngle = currentAngle; // Actualizamos para el siguiente movimiento
        event->accept();
        return;
    }

    if (m_isRotating)
    {
        QPointF mousePos = event->pos();
        qreal angleRad = qAtan2(-mousePos.x(), mousePos.y());
        qreal currentMouseAngle = qRadiansToDegrees(angleRad);
        qreal deltaMouseAngle = currentMouseAngle - m_mouseClickAngle;

        while (deltaMouseAngle > 180) deltaMouseAngle -= 360;
        while (deltaMouseAngle < -180) deltaMouseAngle += 360;

        qreal newRotation = m_initialAngle + deltaMouseAngle;
        if (newRotation > 0)    newRotation = 0;
        if (newRotation < -120) newRotation = -120;

        compas2->setRotation(newRotation);
        event->accept();
        return;
    }

    QGraphicsItemGroup::mouseMoveEvent(event);
}

// ======================================================
// Mouse Release
// ======================================================
void Compass::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_isDrawingCircle) {
        m_isDrawingCircle = false;
        m_arcItem = nullptr;
        event->accept();
        return;
    }
    m_isRotating = false;
    QGraphicsItemGroup::mouseReleaseEvent(event);
}

void Compass::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    QGraphicsItemGroup::hoverMoveEvent(event);
}
