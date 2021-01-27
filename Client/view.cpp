#include "view.h"

View::View(const ControlTypes::Conditioner& _type, const QString &_name, const bool avaliableMenu, QWidget *parent) : QWidget(parent),
    mustPushed(avaliableMenu),
    valueType(_type)
{
    layout = new QHBoxLayout(this);
    type = new QLabel(_name, this);
    createButton();
    if(avaliableMenu)
    {
        createMenu();
    }

    layout->addWidget(type);
    layout->addWidget(button);

    layout->setContentsMargins(13,13,13,13);
    setLayout(layout);

    //connect(this, SIGNAL(signalChangeTypeMeasurements(QString)), this, SLOT(slotChangeValue(QString)));

}

void View::slotActivated(QAction *pAction)
{
    qDebug() << pAction->text();
    emit signalChangeTypeMeasurements(valueType, pAction->text());
}

void View::slotChangeValue(const QString &value)
{
    button->setText(value);
}

void View::createButton()
{
    button = new QPushButton(this);
    button->setFlat(true);

        button->setDisabled(!mustPushed);

}

void View::createMenu()
{
    menu = new QMenu(button);

    menu->addAction("°C");
    menu->addSeparator();
    menu->addAction("°F");
    menu->addSeparator();
    menu->addAction(" K");

    connect(menu, SIGNAL(triggered(QAction*)), SLOT(slotActivated(QAction*)));

    button->setMenu(menu);
}
