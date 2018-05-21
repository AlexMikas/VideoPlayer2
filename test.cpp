#include "test.h"

Test::Test(QWidget *parent)
{
    QPixmap p("F:/work/test/picture.png");
    QLabel *label = new QLabel(parent);
    label -> resize(150,34);
    label -> setPixmap(p);
    label -> move(610,14);
}

Test::~Test()
{
    delete ui;
}
