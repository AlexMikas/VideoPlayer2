#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QGraphicsVideoItem>
#include <QGLWidget>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QMediaPlayer* player = new QMediaPlayer;
    QVideoWidget* vw = new MyVideoWidget(this);

    player->setVideoOutput(vw);
    player->setMedia(QUrl::fromLocalFile("../VideoPlayer/src/video2.mp4"));
    player->play();
    ui->mainLayer->addWidget(vw);

    //Попытка 6. Наложение.
/*
    QWidget *w = new QWidget;
    QMediaPlayer* player = new QMediaPlayer;
    QVideoWidget* vw = new MyVideoWidget(w);
    player->setVideoOutput(vw);
    player->setMedia(QUrl::fromLocalFile("F:/work/test/video2.mp4"));
    QGridLayout *l = new QGridLayout(w);
    QPixmap p("F:/work/test/picture.png");
    QLabel *label = new QLabel;
    label->setAttribute(Qt::WA_TranslucentBackground, true);
    label->setWordWrap(true);
    label->resize(p.width(),p.height());
    label->setPixmap(p);
    label->setMask(p.mask());
    l->addWidget(vw, 0, 0);
    l->addWidget(label, 0, 0);
    ui->mainLayer->addWidget(w);
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
