#include "trianglee.h"
trianglee::trianglee() {}

trianglee::~trianglee()
{

}
void trianglee::initialization()
{
    area = (w * h) / 2.0;
    now_area = area;
    perimeter = w + 2 * sqrt(pow(w / 2, 2) + pow(h, 2));
    now_perimeter = perimeter;
}

void trianglee::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(hasFocus() ? QPen(QColor(255, 166, 21), 3) : QPen(QColor(95, 0, 45), 3));
    painter->drawPoint(0, 0);
    painter->setPen(QPen(QColor(R, G, B), PenSize));
    painter->drawLine(0, -h / 2, w / 2, h / 2);
    painter->drawLine(w / 2, h / 2, -w / 2, h / 2);
    painter->drawLine(-w / 2, h / 2, 0, -h / 2);
    QThread::msleep(10);

    double delta = ang - now_ang;
    now_ang += delta / 100;

    double deltaSize = size - now_size;
    now_size += deltaSize / 100;

    now_area = area * now_size * now_size;
    now_perimeter = perimeter * now_size;

    this->setRotation(now_ang);
    this->setScale(now_size);

    if (this->hasFocus())
        Output();

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
