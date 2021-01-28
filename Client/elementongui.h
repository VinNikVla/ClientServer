#ifndef ELEMENTONGUI_H
#define ELEMENTONGUI_H

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

#include "global.h"

class ElementOnGUI : public QWidget
{
    Q_OBJECT
public:
    explicit ElementOnGUI(QWidget *parent = nullptr);

    QString getName() const;

    enum class TypeControl:quint8
    {
        HorizontalSlider,
        VerticalSlider,
        Button,
        SpinBox,
        Dial
    };

    enum class TypeElement:quint8
    {
        View,
        Control
    };

signals:
    void signalChangeTypeMeasurements(const QString& type);
    void valueChanged(ControlTypes::Conditioner _type, const int);

protected slots:

protected:
    QString m_name;
    ControlTypes::Conditioner m_typeHandler;
    QWidget* m_controlWidget;
    QLayout* m_layout;




};

#endif // ELEMENTONGUI_H
