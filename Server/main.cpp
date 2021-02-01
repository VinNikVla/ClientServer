#include "widget.h"
#include <QApplication>

#include "AbstractConditioner/ServerConditioner/serverconditioner.h"
#include "global.h"
#include "AbstractConditioner/ClientConditioner/clientconditioner.h"
#include "AbstrcatViewModel/ChangeMeasurments/changemeasurmentwidget.h"
#include "AbstrcatViewModel/HandlerState/handlerstate.h"
#include "AbstractValueModel/ChangeStateModel/ChangeMeasurmentsModel/changemeasurment.h"
#include "AbstrcatViewModel/CustomSlider/Slider/slidercontrol.h"
#include "AbstrcatViewModel/CustomSlider/Slider/slidersetvalue.h"
#include "AbstrcatViewModel/CustomSlider/ControlButton/controlbutton.h"

#include "AbstrcatViewModel/CustomSlider/abstractcontrol.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ServerConditioner* conditioner = new ServerConditioner(&a);
    Widget w;

    //const auto itb = w.getVectorElementsOnGUI()->begin();



    for(auto itb = ControlTypes::_server.begin(), ite = ControlTypes::_server.end(); itb != ite; ++itb)
    {

        if(dynamic_cast<SliderSetValue*>(w.getElementOnGUI(*itb)))
        {
            QObject::connect(conditioner->getDetector(*itb),
                             &AbstractValueModel::signalChangeValue,
                             static_cast<SliderSetValue*>(w.getElementOnGUI(*itb)),
                             &SliderSetValue::setValue
                             );

            QObject::connect(static_cast<SliderSetValue*>(w.getElementOnGUI(*itb)),
                             &SliderSetValue::signalValueChanged,
                             conditioner->getDetector(*itb),
                             &AbstractValueModel::slotSetGUI
                             );

        }

        if((dynamic_cast<ChangeMeasurment*>(conditioner->getDetector(*itb))) && dynamic_cast<ChangeMeasurmentWidget*>(w.getElementOnGUI(*itb)))
        {
            QObject::connect(static_cast<ChangeMeasurmentWidget*>(w.getElementOnGUI(*itb)),
                             &ChangeMeasurmentWidget::signalChangeTypeMeasurements,
                             static_cast<ChangeMeasurment*>(conditioner->getDetector(*itb)),
                             &ChangeMeasurment::slotChangeTypeMeasurments);

            QObject::connect(static_cast<ChangeMeasurment*>(conditioner->getDetector(*itb)),
                             &ChangeMeasurment::signalChangeValueMeasurments,
                             static_cast<ChangeMeasurmentWidget*>(w.getElementOnGUI(*itb)),
                             &ChangeMeasurmentWidget::slotChangeValue);
        }

        if(dynamic_cast<ControlButton*>(w.getElementOnGUI(*itb)))
        {
                QObject::connect(static_cast<ControlButton*>(w.getElementOnGUI(*itb)),
                                                  &ControlButton::signalValueChanged,
                                                  conditioner->getDetector(*itb),
                                                  &AbstractValueModel::slotSetGUI
                                                  );

                QObject::connect(conditioner->getDetector(*itb),
                                 &AbstractValueModel::signalChangeValue,
                                 static_cast<ControlButton*>(w.getElementOnGUI(*itb)),
                                 &ControlButton::slotSetValue
                                 );
            }

    }

    QObject::connect(conditioner->getDetector(ControlTypes::Conditioner::OnOff),
                     &AbstractValueModel::signalChangeValue,
                     &w,
                     &Widget::slotEnabledControl
                     );

    w.show();

    return a.exec();
}
