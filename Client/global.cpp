#include "global.h"

ControlTypes::TypeDisplayTemperature toTypeDisplayTemperature(const QString& type)
{
    if(type == " K")
    {
        return ControlTypes::TypeDisplayTemperature::Kelvin;
    }

    if(type == "°C")
    {
        return ControlTypes::TypeDisplayTemperature::Celsius;
    }

    if(type == "°F")
    {
        return ControlTypes::TypeDisplayTemperature::Fahrenheit;
    }
}
