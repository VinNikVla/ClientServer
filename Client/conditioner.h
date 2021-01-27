#ifndef CONDITIONER_H
#define CONDITIONER_H

#include <QObject>
#include <QString>
#include <QMap>
#include <chrono>
#include "global.h"
#include "settings.h"

class Conditioner : public QObject
{
    Q_OBJECT
public:
    Conditioner(Settings* _set, const QString& _ip, const quint16& _port, QObject* parent=nullptr);

public slots:
    void changeValue(const ControlTypes::Conditioner& typeParameter, const double value);
    void changeTypeMeasurementsTemperature(const QString& type);
    void changeTypePressure(const QString& type);

signals:
    void signalChangesTypeMeasurement(double value);
    void signalTemperatureChanged(const QString value);
    void signalPressureChanged(const QString value);

private:
    Settings* m_set;
     double m_temperature;
     ControlTypes::TypeDisplayTemperature typeTemperature;

     double m_pressure;
     ControlTypes::TypeDisplayPressure typePressure;

     double m_humadity;

     QMap<ControlTypes::Conditioner, double*> m_map;
     QString m_ip;
     quint16 m_port;

     void unitConverter( const ControlTypes::TypeDisplayTemperature type);
     void convertPressure(const ControlTypes::TypeDisplayPressure type);
};

#endif // CONDITIONER_H
