#pragma once

#include <QObject>
#include "global.h"
#include <typeinfo>


class ValueModel :public QObject
{
    Q_OBJECT
public:
    ValueModel(const QVector<QString> *_listMeasurments, const ControlTypes::Conditioner& _typeDetector, const QVector<int>* _border, QObject* parent = nullptr);

    DeviceState getState() const;
    ControlTypes::Conditioner getTypeDetector() const;
    QString getTypeMeasurments() const;

public slots:
    void slotSetValue(int value);
    virtual void slotChangeTypeValue(const QString& type) = 0;

signals:
    void signalStateChanged();
    void signalValueChanged(const QString& value);

protected:
    QString m_typeMeasurments;
    ControlTypes::Conditioner m_typeDetector;
    int m_value;
    const QVector<int>* m_border;

    bool checkAvailabilityMeasurments(const QString &type);

private slots:
    void slotSetState();

private:
    DeviceState m_state = DeviceState::Red;

    const QVector<QString>* m_listMesurments;



    DeviceState m_changeState();



};
