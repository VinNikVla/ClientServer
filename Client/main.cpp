#include "widget.h"
#include <QApplication>
#include "global.h"
#include "Settings/settings.h"
#include "AbstractConditioner/ClientConditioner/clientconditioner.h"
#include "AbstrcatViewModel/ChangeMeasurments/changemeasurmentwidget.h"
#include "AbstrcatViewModel/HandlerState/handlerstate.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //AbstractConditioner* conditioner = new AbstractConditioner(&a);

    ;

    Settings* set = new Settings(&a);

    ClientConditioner* conditioner = new ClientConditioner(set, &a);

    Widget w;


    //подключение гуи и логики где может меняться значение`
    for(auto itb = ControlTypes::command.begin(), ite = ControlTypes::command.end(); itb != ite; ++itb)
    {
        if((dynamic_cast<ChangeMeasurment*>(conditioner->getDetector(*itb))) && (dynamic_cast<ChangeMeasurmentWidget*>(w.getElementOnGUI(*itb))))
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

        if((dynamic_cast<AbstractControl*>(w.getElementOnGUI(*itb))))//подключение управляющих элементов неповторяющихся
        {
            QObject::connect(static_cast<AbstractControl*>(w.getElementOnGUI(*itb)),
                             &AbstractControl::signalValueChanged,
                             conditioner,
                             &ClientConditioner::slotRequest);
        }

        if(dynamic_cast<ControlButton*>(w.getElementOnGUI(*itb)))
        {
                QObject::connect(static_cast<ControlButton*>(w.getElementOnGUI(*itb)),
                                                  &ControlButton::signalValueChanged,
                                 conditioner,
                                 &ClientConditioner::slotRequest
                                                  );

                QObject::connect(conditioner->getDetector(*itb),
                                 &AbstractValueModel::signalChangeValue,
                                 static_cast<ControlButton*>(w.getElementOnGUI(*itb)),
                                 &ControlButton::slotSetValue
                                 );
            }

    }

    //велосипед неверно выбрал контейнер для хранения объектов
    QObject::connect(w.getControlTemperature(),
                     &SliderControl::signalValueChanged,
                     conditioner,
                     &ClientConditioner::slotRequest);



    QObject::connect(conditioner->getDetector(ControlTypes::Conditioner::OnOff), //разрешающий сигнал для управления параметрами кондиционера
                     &AbstractValueModel::signalChangeValue,
                     &w,
                     &Widget::slotEnabledControl);

    QObject::connect(conditioner,                                               //отображение общего состояния
                     &ClientConditioner::signalChangeComplexState,
                     static_cast<HandlerState*>(w.getElementOnGUI(ControlTypes::Conditioner::ComplexState)),
                     &HandlerState::slotChangeState);


    w.show();

    return a.exec();
}
