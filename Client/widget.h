#ifndef WIDGET_H
#define WIDGET_H

#include <QVector>
#include <QWidget>
#include <QSlider>
#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QMenu>
#include <QMenuBar>

#include <QDebug>
#include <QAction>

#include "view.h"
#include "control.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
signals:

public slots:
    void slotActivated(QAction* pAction);

private:
    Ui::Widget *ui;
    QVector<QWidget*> elementsOnGUI;
    void customMenuRequested(QWidget* button);
    //QHBoxLayout* createElement(QWidget*...);

};

#endif // WIDGET_H
