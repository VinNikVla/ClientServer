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
#include "ValueModel/valuemodel.h"

class Control : public QWidget
{
    Q_OBJECT
public:
    explicit Control(const ControlTypes::Conditioner& _typeDetector, const ControlTypes::TypeControl& _type, QWidget *parent = nullptr);
    QString getName() const;
    ControlTypes::Conditioner getTypeDetector() const;

signals:
    //void valueChanged
    void valueChanged(ControlTypes::Conditioner _type, const int);

public slots:
    //void response(QByteArray

private slots:
    void handlerSignal(const int value);

private:
    QWidget* controlWidget;
    QLabel* nameHandler;
    QLayout* layout;
    ControlTypes::TypeControl m_typeControl;

    QString m_name;
    ControlTypes::Conditioner m_typeDetector;
    QWidget* createControlWiget(const ControlTypes::TypeControl& type);
    void createSignalForWidget();

};

#endif // CONTROL_H
