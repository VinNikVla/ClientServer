#ifndef CIRCLESTATE_H
#define CIRCLESTATE_H

#include <QWidget>
#include "global.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QPaintEvent>
#include <QColor>


//#define unknown QColor(128, 128, 128);
//#define green QColor(0, 255, 0)
//#define red QColor(255, 0, 0)
//#define blue QColor(0, 0, 255)

class CircleState : public QWidget
{
    Q_OBJECT
public:
    explicit CircleState(QWidget *parent = nullptr);

signals:

public slots:
    void changeState(const DeviceState& state);


    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);
    QMap<DeviceState, QColor> mapColor;

private:
        DeviceState m_state;
};

#endif // CIRCLESTATE_H
