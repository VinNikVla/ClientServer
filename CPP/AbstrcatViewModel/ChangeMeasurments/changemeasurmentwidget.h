#ifndef CHANGEMEASURMENTWIDGET_H
#define CHANGEMEASURMENTWIDGET_H

#include "AbstrcatViewModel/abstractgui.h"

typedef QVector<QPair<QString, QPair<double, double>>> Measurments;

class ChangeMeasurmentWidget:public AbstractGUI
{
    Q_OBJECT
public:
    ChangeMeasurmentWidget(const bool _flat, const bool _menu, const Measurments* _measurments, const ControlTypes::Conditioner& _typeDetector, QWidget* parent = nullptr);

public slots:
    void slotChangeValue(const QString& value);
    void slotActivated(QAction* pAction);

private:
    bool m_flat;
    bool m_menu;
    const Measurments* m_measurments;

    void createMenu();

signals:
    void signalChangeTypeMeasurements(const QString& type);
protected:
    virtual QWidget* createControlWidget() override;

};

#endif // CHANGEMEASURMENTWIDGET_H
