#include "view.h"

View::View(const QString& _name, const bool avaliableMenu, QWidget *parent, const QVector<QString>* _measurement) :
    QWidget(parent),
    m_name(_name),
    mustPushed(avaliableMenu)
{
    layout = new QHBoxLayout(this);
    type = new QLabel(_name, this);
    createButton();


    if(_measurement)
        m_measurement = _measurement;

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

QString View::getName() const
{
    return m_name;
}

void View::slotActivated(QAction *pAction)
{
    qDebug() << pAction->text();
    emit signalChangeTypeMeasurements(pAction->text());
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

    for(QVector<QString>::const_iterator itb = m_measurement->begin(), ite = m_measurement->end(); itb != ite; ++itb)
    {
        menu->addAction(*itb);
        if(itb != (ite - 1))
        {
            menu->addSeparator();
        }
    }

//    menu->addAction("°C");
//    menu->addSeparator();
//    menu->addAction("°F");
//    menu->addSeparator();
//    menu->addAction(" K");

    connect(menu, SIGNAL(triggered(QAction*)), SLOT(slotActivated(QAction*)));

    button->setMenu(menu);
}
