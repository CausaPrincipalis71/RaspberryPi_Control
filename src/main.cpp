#include <Arduino.h>
#include "digitalPinClassInput.h"
#include "digitalPinClassOutput.h"
#include "IRremote.h"


digitalPinClassOutput relay(5);
digitalPinClassInput button(6);
IRrecv Reciever(A0);

void setup() 
{
    Reciever.enableIRIn();
    Serial.begin(115200);
}

void loop() {
  if(Reciever.available())
  {
      Reciever.decode();
      delay(10);
      auto IRvalue = Reciever.results.value & 0xFF;
      if (IRvalue == 0xC)
      {
          relay.toggle_Status();
          delay(1000);
      }
      /*
      ОБОЗНАЧЕНИЕ КОМАНД
      1 - МЫШЬ ВВЕРХ
      2 - МЫШЬ ВНИЗ
      3 - МЫШЬ ВПРАВО
      4 - МЫШЬ ВЛЕВО
      5 - ЛКМ
      */
      else if(IRvalue == 0x20)
        Serial.print(1);
      else if(IRvalue == 0x21)
        Serial.print(2);
      else if(IRvalue == 0x10)
        Serial.print(3);
      else if(IRvalue == 0x11)
        Serial.print(4);
      else if(IRvalue == 0x3B)
      {
        Serial.print(5);
        delay(200);
        }
      

      Reciever.resume();
  }

  
}