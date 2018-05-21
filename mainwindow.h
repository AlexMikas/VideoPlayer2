#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QWidget>
#include <QVideoWidget>
#include "qpaintwidget.h"
#include <QPainter>
#include <QLabel>
#include <QBitmap>
#include <QSplashScreen>
#include <QImage>
#include <QDebug>

namespace Ui {
class MainWindow;
class MyVideoWidget;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

class MyVideoWidget : public QVideoWidget
{
    Q_OBJECT
private:
    //Ui::MyVideoWidget *ui;

protected:
    virtual void paintEvent(QPaintEvent *event){
        //Попытка 0. Изображение рисуется под видео
       /* QVideoWidget::paintEvent(event);
        QPainter p(this);
        QPixmap pixmap("F:/work/test/picture.png");
        //p.fillRect(0, 0, width(), height(), QBrush(pixmap));
        //QRegion r1(QRect(100,100,200,80));
        //p.setClipRegion(r1);
        p.drawPixmap(0,0,pixmap);*/
    }

public:
    MyVideoWidget::MyVideoWidget(QWidget *parent) //:
        //QVideoWidget(parent), ui(new Ui::MyVideoWidget)
    {
        //ui->setupUi(this);
        //Попытка 1

        QPixmap p("../VideoPlayer/src/picture.png");

        QLabel *label = new QLabel(parent);
        label->resize(p.width(),p.height());
        //QPixmap p_new = p.scaled(h,w);
        //label->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
        label->setPixmap(p);
        label->setMask(p.createHeuristicMask()); //или просто p.mask()
        //label -> move(0,0);

/*
        //Попытка 2
        QSplashScreen *splash = new QSplashScreen(parent);//, Qt::WStyle_Customize | Qt::WStyle_NoBorder);
        splash->setPixmap(p);
        //splash->show();*/
/*
 *
 *    //Попытка 3
       QImage image("F:/work/test/picture.png");
        // Create new picture for transparent
        QPixmap transparent(image.size());
        // Do transparency
        transparent.fill(Qt::transparent);
        QPainter p(this);
        p.begin(&transparent);
        p.setCompositionMode(QPainter::CompositionMode_Source);
        p.drawPixmap(0, 0, QPixmap::fromImage(image));
        p.setCompositionMode(QPainter::CompositionMode_DestinationIn);

        // Set transparency level to 150 (possible values are 0-255)
        // The alpha channel of a color specifies the transparency effect,
        // 0 represents a fully transparent color, while 255 represents
        // a fully opaque color.
        p.fillRect(transparent.rect(), QColor(0, 0, 0, 150));
        p.end();

        //put semi-transparent picture to QLabel
        QLabel* label = new QLabel(parent);
        label->setPixmap(transparent);
        label->setMask(transparent.mask());
        label->render(&p);
        label -> move(100,100);
*/
        //Попытка 4
        QPixmap input("F:/work/test/picture.png");
/*
        QImage image(input.size(), QImage::Format_ARGB32_Premultiplied);
        image.fill(Qt::transparent);
        QPainter p(&image);
        p.setOpacity(0.2);
        p.drawPixmap(0, 0, input);
        p.end();
        QPixmap output = QPixmap::fromImage(image);
        QLabel *label = new QLabel(parent);
        label->setAutoFillBackground(false);
        label->setAttribute(Qt::WA_TranslucentBackground, true);
        label->setWindowOpacity(0.5);
        label->setPixmap(output);
        label->resize(output.width(),output.height());
        label->setMask(output.mask());
 */
        //Попытка 5. Долго прорисовывается
/*
        QPixmap result(input.size());
        result.fill(Qt::transparent);

        QPainter painter;
        painter.begin(&result);
        painter.setOpacity(0.5);
        painter.drawPixmap(0, 0, input);
        painter.end();
        QLabel *label = new QLabel(parent);
        label->setAttribute(Qt::WA_TranslucentBackground, true);
        label->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
        label->setPixmap(result);
        label->resize(result.width(),result.height());
        label->setMask(result.mask());
        label->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
*/
    }
    ~MyVideoWidget(){}
};

#endif // MAINWINDOW_H
