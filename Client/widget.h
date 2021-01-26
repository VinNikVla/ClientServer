#ifndef WIDGET_H
#define WIDGET_H

#include <QVector>
#include <QWidget>
#include <QSlider>
#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include <QLCDNumber>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QVector<QWidget*> elementsOnGUI;
    //QHBoxLayout* createElement(QWidget*...);

};

#endif // WIDGET_H
