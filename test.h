#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QPainter>
#include <QPicture>
#include <QVideoWidget>
#include <QImage>

namespace Ui {
    class Test;
}

struct Graphics {
    QImage pixmapLogo;
};

class Test : public QVideoWidget
{
    Q_OBJECT

    Ui::Test *ui;
    QPixmap          mPixmap;
    QImage           pixmapL;
    Graphics          mGraphics;

protected:
    void paintEvent(QPaintEvent *);

public:
    Test(QWidget *parent = 0);
    ~Test();
};

#endif // TEST_H
