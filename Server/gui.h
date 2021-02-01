#ifndef GUI_H
#define GUI_H

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

namespace Ui {
class GUI;
}

class GUI : public QWidget
{
    Q_OBJECT

public:
    explicit GUI(QWidget *parent = 0);
    ~GUI();

    Control* getControl(ControlTypes::Conditioner key);

private:
    Ui::GUI *ui;
    QMap<ControlTypes::Conditioner, Control*> controlOnGUI;
};

#endif // GUI_H
