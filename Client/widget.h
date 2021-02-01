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

#include "ViewModel/control.h"
#include "ViewModel/view.h"
#include "global.h"

#include <QStatusBar>
#include <QToolBar>
#include "circlestate.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    View* getView(ControlTypes::Conditioner key);
    Control* getControl(ControlTypes::Conditioner key);
    CircleState* getState() const;

    ~Widget();
signals:

public slots:
    void slotActivated(QAction* pAction);
    void slotShowMessage(const QString& msg);
    void slotEnabledControl();
    void slotDisableControl();

private:
    Ui::Widget *ui;
    QStatusBar* statusBar;
    CircleState* stateCircle;
    QMap<ControlTypes::Conditioner, View*> elementsOnGUI;
    QMap<ControlTypes::Conditioner, Control*> controlOnGUI;


};

#endif // WIDGET_H
