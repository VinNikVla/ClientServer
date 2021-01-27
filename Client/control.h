#ifndef CONTROL_H
#define CONTROL_H

#include <QVector>
#include <QWidget>
#include <QSlider>
#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QMenu>
#include <QMenuBar>
#include <QSpinBox>

#include <QDebug>
#include <QAction>
#include <QDial>

#include <global.h>

class Control : public QWidget
{
    Q_OBJECT
public:
    explicit Control(const QString& _name,const ControlTypes::TypeControl& _type, QWidget *parent = nullptr);

signals:
    //void valueChanged
public slots:
    //void response(QByteArray

private:
    QWidget* controlWidget;
    QLabel* type;
    QLayout* layout;

    QWidget* createControlWiget(const ControlTypes::TypeControl& type);

};

#endif // CONTROL_H
