#include "digitalPinClassInput.h"

digitalPinClassInput::digitalPinClassInput(int pinNum, bool conterbounced = true, bool reversed = true)  // Конструктор, выполняется при запуске
{
    this->pin = pinNum;                                 // Сохраняется номер пина
    this->conterBounce = conterbounced;                 // Сохранение настроек антидребезга
    this->reverse = reversed;                           // И настроек инвертирования


    pinMode(pin, INPUT_PULLUP);                         // Ставится режим чтения

    this->lastState = !bool(digitalRead(pin));          // Запись текущего состояния
}

bool digitalPinClassInput::read_data()                  // Чтение данных
{
    bool state;

    if(digitalRead(pin) == HIGH)                               
        lastState = true;                               
    else
        lastState = false;

    if(this->conterBounce == true)
    {
        delay(15);
        if(digitalRead(pin) == HIGH)                               
            state = true;                               
        else
            state = false;
        
        lastState &= state;
    }   
    
    if(this->reverse == true)
        return !lastState;                                  // Возврат прочтённого состояния, инверсированного для нормальной работы режима input_pullup
    else
        return lastState;                                   // Или не инвертированного, если reverse == false 
    
}

bool digitalPinClassInput::is_changed()                 // Изменилось ли состояние        
{
    bool cur_state = !(bool(digitalRead(pin)));         // Чтение данных о состоянии пина

    if(lastState != cur_state)                          // Если состояние изменилось           
    {
        lastState = cur_state;                          // Сохраняется состояние
        return true;                                    // Возвращается true
    }
    else                                                // В ином случае
    {
        return false;                                   // Возвращается false
    }
    
}

int digitalPinClassInput::get_pin()
{
    return pin;
}