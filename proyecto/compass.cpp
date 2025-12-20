#include "compass.h"
//#include "mainwindow.h"
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
        if (clickedItem == compas1 || clickedItem == compas2 || isAncestorOf(clickedItem))
        {
            // 1. ANCLAR EL CENTRO: Usamos la posición global de la punta fija
            m_fixedPointScene = mapToScene(transformOriginPoint());

            // 2. CALCULAR RADIO Y ÁNGULO INICIAL
            QPointF movingTipScene = compas2->mapToScene(tipOfLeg(compas2));
            QLineF radiusLine(m_fixedPointScene, movingTipScene);

            m_circleRadius = radiusLine.length();
            m_lastAngle = radiusLine.angle(); // Sistema Qt: 0-360 antihorario

            // 3. INICIAR EL TRAZO
            m_currentPath = QPainterPath();
            m_currentPath.moveTo(movingTipScene);
            m_arcItem = new QGraphicsPathItem();
            m_arcItem->setPen(QPen(m_drawingColor, m_grosor, Qt::SolidLine, Qt::RoundCap));
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
        // 1. OBTENER POSICIÓN DEL RATÓN RESPECTO AL CENTRO FIJO
        QPointF mouseInScene = event->scenePos();
        QLineF currentLine(m_fixedPointScene, mouseInScene);

        // 2. ROTAR EL COMPÁS (Sincronizado)
        // Usamos el ángulo de la línea directamente.
        // Como setRotation es horario y QLineF::angle es antihorario, compensamos:
        qreal newAngle = currentLine.angle();
        setRotation(-newAngle -180); // El +90 depende de la orientación de tu SVG original

        // 3. CALCULAR EL MOVIMIENTO DE LA PATA MÓVIL
        // No usamos la posición del ratón para el dibujo, sino la posición real de la "punta"
        QPointF tipScene = compas2->mapToScene(tipOfLeg(compas2));
        QLineF tipLine(m_fixedPointScene, tipScene);
        qreal currentTipAngle = tipLine.angle();

        // 4. CALCULAR EL DIFERENCIAL (Sweep)
        qreal sweep = currentTipAngle - m_lastAngle;

        // Corrección de cruce 0/360
        if (sweep > 180)  sweep -= 360;
        if (sweep < -180) sweep += 360;

        // 5. DIBUJAR
        QRectF rect(m_fixedPointScene.x() - m_circleRadius,
                    m_fixedPointScene.y() - m_circleRadius,
                    m_circleRadius * 2,
                    m_circleRadius * 2);

        m_currentPath.arcTo(rect, m_lastAngle, sweep);
        m_arcItem->setPath(m_currentPath);

        m_lastAngle = currentTipAngle;
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
