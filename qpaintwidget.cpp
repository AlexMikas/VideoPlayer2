#include "qpaintwidget.h"

#include <QPainter>

QPaintWidget::QPaintWidget(QWidget * parent) : QWidget(parent)
{
}

void QPaintWidget::paintEvent(QPaintEvent *) {
    QPainter p(this); // Создаём новый объект рисовальщика
    QImage image("F:/work/test/picture.png");
    QPixmap pixmap("F:/work/test/picture.png");
    QRectF target(10.0, 20.0, 80.0, 60.0);
    QRectF source(0.0, 0.0, 70.0, 40.0);
    //p.drawImage(0,0,image);
    p.drawPixmap(0,0,pixmap);

}
