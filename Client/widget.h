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
#include "global.h"

#include <QStatusBar>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    View* getView(ControlTypes::Conditioner key);
    Control* getControl(QString key);
    ~Widget();
signals:

public slots:
    void slotActivated(QAction* pAction);
    void slotShowMessage(const QString& msg);

private:
    Ui::Widget *ui;
    QStatusBar* statusBar;
    QMap<ControlTypes::Conditioner, View*> elementsOnGUI;
    QMap<QString, Control*> controlOnGUI;


};

#endif // WIDGET_H
