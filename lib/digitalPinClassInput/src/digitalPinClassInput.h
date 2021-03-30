#ifndef DIGITALPINCLASSINPUT_H
#define DIGITALPINCLASSINPUT_H

#include "Arduino.h"

class digitalPinClassInput
{
    public:
        digitalPinClassInput(int, bool conterbounced = true, bool reversed = true);          // Конструктор

        bool read_data();                   // Чтение данных
        bool is_changed();                  // Если состояние изменилось

        int get_pin();
    private:
        int pin;                            // Номер пина
        bool lastState;                     // Последнее известное состояние
        bool conterBounce;                  // Антидребезг
        bool reverse;                       // Инвертировать значение, или нет.
};

#endif //DIGITALPINCLASSINPUT_H