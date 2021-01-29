#include "view.h"

View::View(const ControlTypes::Conditioner &_typeDetector,
           const bool avaliableMenu,
           const QVector<QString>* _measurement,
           QWidget *parent
           ) :
    QWidget(parent),
    m_typeDetector(_typeDetector),
    mustPushed(avaliableMenu),
   m_measurement(_measurement)
{

    layout = new QHBoxLayout(this);
    type = new QLabel(toString(m_typeDetector), this);
    createButton();



    if(avaliableMenu)
    {
        createMenu();
    }



    layout->addWidget(type);
    layout->addWidget(button);

    layout->setContentsMargins(13,13,13,13);
    setLayout(layout);
}

ControlTypes::Conditioner View::getTypeDetector() const
{
    return m_typeDetector;
}

void View::slotActivated(QAction *pAction)
{
    qDebug() << pAction->text();
    emit signalChangeTypeMeasurements(pAction->text());
}

void View::slotChangeValue(const QString &value)
{
    qDebug() << value;
    button->setText(value);
}

void View::createButton()
{
    button = new QPushButton(this);

    button->setFlat(true);

}

void View::createMenu()
{
    menu = new QMenu(button);

    if(m_measurement)
    {
    for(QVector<QString>::const_iterator itb = m_measurement->begin(), ite = m_measurement->end(); itb != ite; ++itb)
    {
        menu->addAction(*itb);
        if(itb != (ite - 1))
        {
            menu->addSeparator();
        }
    }
    }

    connect(menu, SIGNAL(triggered(QAction*)), SLOT(slotActivated(QAction*)));

    button->setMenu(menu);

}
