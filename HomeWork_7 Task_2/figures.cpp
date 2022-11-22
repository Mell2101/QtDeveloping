#include "figures.h"

Figures::Figures(QObject *parent)
    : QObject{parent}, QGraphicsItem()
{
    _x = 0;
    _y = 0;
    _brush.setColor(QColor(rand() % 256, rand() % 256,rand() % 256));
    _brush.setStyle(Qt::BrushStyle::SolidPattern);
    _geometry = Geometry::RECTANGLE;
    setPos(0,0);
    _moving = false;
}

void Figures::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        _moving = true;
        _point = event->pos().toPoint();


    }
    if(event->button() == Qt::RightButton)
    {
        _geometry = Geometry::DELETE;
        emit reDraw();
    }

}

void Figures::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        _moving = false;
        emit reDraw();
    }
}

void Figures::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(_moving)
    {
        QPoint p = event->pos().toPoint() - _point;
        _x += p.x();
        _y += p.y();
        _point = event->pos().toPoint();
        emit reDraw();
    }

}

void Figures::paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(_brush);
    if(_geometry == Geometry::ELLIPS) painter->drawEllipse(_x, _y, 200, 100);
    if(_geometry == Geometry::RECTANGLE) painter->drawRect(_x, _y, 200, 100);

    if(_geometry == Geometry::DELETE) return;

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Figures::boundingRect()const
{
    return QRectF(_x,_y, 200, 100);
}
