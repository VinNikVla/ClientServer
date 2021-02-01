#include "circlestate.h"

CircleState::CircleState(QWidget *parent) : QWidget(parent)
{
    m_state = DeviceState::Unknown;
    mapColor[DeviceState::Unknown] = Qt::gray;
    mapColor[DeviceState::Red] = Qt::red;
    mapColor[DeviceState::Green] = Qt::green;
    mapColor[DeviceState::Yellow] = Qt::yellow;

}

void CircleState::changeState(const DeviceState &state)
{
    if(state == m_state)
    {
        return;
    }

    m_state = state;

    this->repaint();
}


void CircleState::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);//отрисовка как я понял
    //painter.setBrush();

    painter.setPen(QPen(mapColor[m_state], 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(mapColor[m_state], Qt::SolidPattern));

    qDebug() << width() << " " << height();
    int minimum = (width() > height() ? height() : width());
    //painter.drawEllipse(QPointF(minimum / 2., minimum /2.), minimum / 2, minimum / 2);
    painter.drawEllipse(width() - minimum, 0, minimum - 2, minimum - 2);
    //painter.fillEll
}
