#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>
#include <QDebug>
#include <QVariant>
#include "global.h"



class Settings: public QObject
{
    Q_OBJECT
public:
    Settings(QObject * parent = nullptr);
    ~Settings();

    QString getTypePressure() const;
    QString getTypeTemperature() const;

    void setTypePressure(const QString& pressure);
    void setTypeTemperature(const QString& temperature);

    //void setType(ControlTypes::Conditioner, QStri)


private:
    QString typeTemperature;
    QString typePressure;
    QSettings* set = nullptr;

    void readMe();
    void writeMe();
};

#endif // SETTINGS_H
