#ifndef VIEW_H
#define VIEW_H

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
#include "global.h"

enum class TypeElement:quint8
{
    View,
    Control
};

class View : public QWidget
{
    Q_OBJECT
public:
    explicit View(const ControlTypes::Conditioner& _type,const QString& _name, const bool createMenu, QWidget *parent = nullptr);

signals:
    void signalChangeTypeMeasurements(const ControlTypes::Conditioner _type, const QString& type);

public slots:
    void slotActivated(QAction* pAction);
    void slotChangeValue(const QString& value);


private:
    QPushButton* button;
    QLabel* type;
    QMenu* menu;
    QLayout* layout;

    ControlTypes::Conditioner valueType;

    void createButton();
    void createMenu();

    bool mustPushed;
};

#endif // VIEW_H
