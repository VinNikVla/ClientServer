#ifndef ABSTRACTGUI_H
#define ABSTRACTGUI_H

#include <QWidget>
#include "global.h"
#include <QVector>
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

class AbstractGUI : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractGUI(const ControlTypes::Conditioner& _typeDetector, QWidget *parent = nullptr);

    ControlTypes::Conditioner getTypeDetector() const;

signals:

public slots:
protected:
    QWidget* m_widget;
    QLayout* layout;
    virtual QWidget* createControlWidget() = 0;
    ControlTypes::Conditioner m_typeDetector;
};

#endif // ABSTRACTGUI_H
