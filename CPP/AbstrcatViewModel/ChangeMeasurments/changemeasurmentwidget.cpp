#include "changemeasurmentwidget.h"



ChangeMeasurmentWidget::ChangeMeasurmentWidget(const bool _flat,
                                               const bool _menu,
                                               const Measurments *_measurments,
                                               const ControlTypes::Conditioner &_typeDetector,
                                               QWidget *parent):
    AbstractGUI(_typeDetector, parent),
    m_flat(_flat),
    m_menu(_menu),
    m_measurments(_measurments)

{
    layout = new QHBoxLayout(this);
    QLabel* label = new QLabel(toString(m_typeDetector), this);
    layout->addWidget(label);
    m_widget = createControlWidget();

    if(m_menu)
        createMenu();

    layout->addWidget(m_widget);

    layout->setContentsMargins(13,13,13,13);
    setLayout(layout);

}

void ChangeMeasurmentWidget::slotChangeValue(const QString &value)
{
    qDebug() << value;
    static_cast<QPushButton*>(m_widget)->setText(value);
}

void ChangeMeasurmentWidget::slotActivated(QAction *pAction)
{
    qDebug() << pAction->text();
    emit signalChangeTypeMeasurements(pAction->text());
}

void ChangeMeasurmentWidget::createMenu()
{
    QMenu* menu = new QMenu(static_cast<QPushButton*>(m_widget));

    if(m_measurments)
    {
        for(auto itb = m_measurments->begin(), ite = m_measurments->end(); itb != ite; ++itb)
        {
            menu->addAction(itb->first);
            if(itb != (ite - 1))
            {
                menu->addSeparator();
            }
        }
    }

    connect(menu, SIGNAL(triggered(QAction*)), SLOT(slotActivated(QAction*)));

    static_cast<QPushButton*>(m_widget)->setMenu(menu);
}

QWidget *ChangeMeasurmentWidget::createControlWidget()
{
    QPushButton* button = new QPushButton(this);

    button->setFlat(m_flat);

    return button;
}

