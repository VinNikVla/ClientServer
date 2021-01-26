#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* buttonEnd = new QPushButton(this);
    QVBoxLayout* Vlayout = new QVBoxLayout(this);
    QHBoxLayout* temperature = new QHBoxLayout(this);
    QLabel* name = new QLabel("Temperature", this);
    QLCDNumber* num = new QLCDNumber(3, this);
    QLabel* type = new QLabel("K", this);

    temperature->addWidget(name);
    temperature->addWidget(num);
    temperature->addWidget(type);

    //temperature->se
    Vlayout->addWidget(buttonEnd);
    Vlayout->addItem(temperature);
    elementsOnGUI.push_back(buttonEnd);



    //ui
}

Widget::~Widget()
{
    delete ui;
}
