#ifndef FIGURES_H
#define FIGURES_H

#include <QObject>
#include <QGraphicsItem>
#include <QBrush>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

class Figures : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QBrush brush)
public:
    explicit Figures(QObject *parent = nullptr);
    void setBrush(QBrush brush) {this->_brush; emit reDraw();}
signals:
    void reDraw();
    void dblClick();
private:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    QRectF boundingRect() const override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
private:
    enum Geometry {RECTANGLE, ELLIPS, STAR, DELETE};
    int _x, _y;
    Geometry _geometry;
    QPoint _point;
    bool _moving;
    QBrush _brush;

};

#endif // FIGURES_H
