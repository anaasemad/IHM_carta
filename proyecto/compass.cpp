#include "compass.h"
#include <QDebug>
#include <QCursor>
#include <QtMath>
#include <QApplication>
#include <QGraphicsScene>
#include <QSvgRenderer>
#include <QGraphicsRectItem>

Compass::Compass(const QString &svgPath, QGraphicsItem *parent)
    : QGraphicsItemGroup(parent)
{
    // Flags
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable );
             //QGraphicsItem::ItemIgnoresTransformations); // para que no cambie el tamaño al hacer zoom -> NO VA

    setAcceptHoverEvents(true); // Necesario para el cambio de cursor



    //Pata Movil
    compas2 = new QGraphicsSvgItem(svgPath, this);
    compas2->setScale(SCALE_FACTOR);
    compas2->setTransformOriginPoint(0, 0);

    //Pata Fija
    compas1 = new QGraphicsSvgItem(svgPath, this);
    compas1->setScale(SCALE_FACTOR);
    compas1->setTransformOriginPoint(0, 0);

    // Rotación inicial para que se vea abierto
    setRotation(90);
    compas2->setRotation(-30);

    //altura escalada (longitud de la pata)
    //m_pataHeight = compas2->boundingRect().height() * SCALE_FACTOR;


    qreal tipSize = 20.0; // Un cuadrado de 20x20 píxeles para la detección


    // Definimos el área en la punta de la pata móvil (centrada en X)
    m_detectionTip = new QGraphicsRectItem(
        tipSize *9,       // X
        0,            // Y
        tipSize,              // Ancho
        tipSize,              // Alto
        compas2           // PATA MÓVIL
        );

    // --- IMPORTANTE PARA LA DEPURACIÓN ---
    // Para hacer visible temporalmente y ver dónde está el cuadrado de detección
    m_detectionTip->setPen(Qt::NoPen); //visible cambiar setPen(QtPen(Qt::red))
    m_detectionTip->setBrush(QBrush(Qt::transparent));
    m_detectionTip->setZValue(10);
}



//#########################_RotarCompás_##############################################
void Compass::wheelEvent(QGraphicsSceneWheelEvent *event)
{

    const int delta = event->delta(); // Qt5: 120 por "clic" de rueda
    if (delta == 0) {
        event->ignore();
        return;
    }
    double deltaDegrees = (delta / 8.0) * 0.1; // ≈ 1.5° por "clic"
    m_angleDeg += deltaDegrees;
    setRotation(m_angleDeg);

    if (scene())
        scene()->update();

    event->accept();
}


//#########################_RatónEnZonaDetección_##############################################

bool Compass::isCursorInRotationZone(const QPointF& scenePos)
{
    // 1. Convertir la posición de la escena a coordenadas locales del ÍTEM DE DETECCIÓN
    QPointF posInTip = m_detectionTip->mapFromScene(scenePos);

    // 2. Verificar si el ítem contiene esta posición
    if (m_detectionTip->contains(posInTip))
    {
        //qDebug() << "ZONA DETECTADA! Pos Local en Tip:" << posInTip;
        return true;
    }

    // Debugging si falla la detección:
    // qDebug() << "Fallo de Detección. Posición en Scene:" << scenePos;

    return false;
}


//##############################_RotacionAbrirCompas_###################################################
void Compass::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_isRotating)
    {
        QPointF mousePos = event->pos();

        // 1. CALCULAR EL ÁNGULO ACTUAL DEL RATÓN
        qreal angleRad = qAtan2(-mousePos.x(), mousePos.y());
        qreal currentMouseAngle = qRadiansToDegrees(angleRad);

        // 2. CALCULAR EL CAMBIO DEL RATÓN DESDE EL CLIC
        qreal deltaMouseAngle = currentMouseAngle - m_mouseClickAngle;

        // Manejar el cruce de 360/0 grados (para que el movimiento sea continuo)
        while (deltaMouseAngle > 180) deltaMouseAngle -= 360;
        while (deltaMouseAngle < -180) deltaMouseAngle += 360;

        // 3. CALCULAR LA NUEVA ROTACIÓN APLICANDO EL CAMBIO A LA POSICIÓN INICIAL DE LA PATA
        qreal targetRotation = m_initialAngle + deltaMouseAngle;
        qreal newRotation = targetRotation;

        // 4. LIMITACIÓN DE APERTURA
        qreal maxAngle = compas1->rotation();
        qreal minAngle = compas1->rotation() - 180;

        if (newRotation > maxAngle) {
            newRotation = maxAngle;
        } else if (newRotation < minAngle) {
            newRotation = minAngle;
        }

        // Aplicar la rotación
        compas2->setRotation(newRotation);
        event->accept();
    } else {
        QGraphicsItemGroup::mouseMoveEvent(event);
    }
}

void Compass::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    // Si eliminamos la implementación anterior, el cursor debe ser manejado por MainWindow.
    QGraphicsItemGroup::hoverMoveEvent(event);
}



void Compass::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (isCursorInRotationZone(event->scenePos())) {
            m_isRotating = true;

            m_initialAngle = compas2->rotation(); // Ángulo de la pata en el momento del clic

            QPointF mousePos = event->pos();
            qreal angleRad = qAtan2(-mousePos.x(), mousePos.y());
            m_mouseClickAngle = qRadiansToDegrees(angleRad);


            event->accept();
            return;
        } else {
            m_isRotating = false;
            QGraphicsItemGroup::mousePressEvent(event);
        }
    }
}


void Compass::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_isRotating = false;
    QGraphicsItemGroup::mouseReleaseEvent(event);
}
