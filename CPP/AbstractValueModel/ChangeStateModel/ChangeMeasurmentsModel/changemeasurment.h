#ifndef CHANGEMEASURMENTMODEL_H
#define CHANGEMEASURMENTMODEL_H

#include "AbstractValueModel/ChangeStateModel/changestate.h"
typedef QVector<QPair<QString, QPair<double, double>>> Measurments;

class ChangeMeasurment:public ChangeState
{
     Q_OBJECT
public:
    ChangeMeasurment(const Measurments* _vecMeasurments, const QVector<int>* _borderState, const ControlTypes::Conditioner& _typeDetector, QObject *parent = nullptr);



private:
    const Measurments* m_vecMeasurments;
    QString m_typeMeasurments;

    bool m_checkAvailabilityMeasurments(const QString &type);

public slots:
    void slotChangeTypeMeasurments(const QString& type);

private slots:
    void m_slotHandlerInsade(const ControlTypes::Conditioner& type, const int value);

signals:
    void signalChangeValueMeasurments(const QString type);
    void signalChangeTypeMeasurments(const QString type);

};

#endif // CHANGEMEASURMENTMODEL_H
