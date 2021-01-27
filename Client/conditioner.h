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
    Conditioner(Settings* set, const QString& _ip, const quint16& _port, QObject* parent=nullptr);

public slots:
    void changeValue(const ControlTypes::Conditioner& typeParameter, const double value);
    void changeChangeTypeMeasurements(const ControlTypes::Conditioner& _type, const QString &type);

signals:
    void signalChangesTypeMeasurement(double value);
    void signalValueChanged(const QString& value);
private:
     double m_temperature;
     ControlTypes::TypeDisplayTemperature typeTemperature;

     double m_pressure;
     ControlTypes::TypeDisplayPressure typePressure;

     double m_humadity;

     QMap<ControlTypes::Conditioner, double*> m_map;
     QString m_ip;
     quint16 m_port;

     void unitConverter( const ControlTypes::TypeDisplayTemperature type);


     //void newCommand(
};

#endif // CONDITIONER_H
