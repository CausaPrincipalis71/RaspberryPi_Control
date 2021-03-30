#include <Arduino.h>
#include "digitalPinClassInput.h"
#include "digitalPinClassOutput.h"
#include "IRremote.h"

digitalPinClassOutput relay(5);
digitalPinClassInput button(6);
IRrecv Reciever(A0);
IRsend Sender;

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
      Serial.println(Reciever.results.value, HEX);
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

      else if(IRvalue == 0x38)
      {
        Sender.sendLG(0x20DF10EF, 32);
        delay(200);
      }
      else if(IRvalue == 0xE)
      {
        Sender.sendLG(0x20DFD02F, 32);
        delay(200);
      }
      else if(IRvalue == 0x2)
      {
        Sender.sendLG(0x20DF02FD, 32);
        delay(200);
      }
      else if(IRvalue == 0x5)
      {
        Sender.sendLG(0x20DFE01F, 32);
        delay(200);
      }
      else if(IRvalue == 0x7)
      {
        Sender.sendLG(0x20DF609F, 32);
        delay(200);
      }
      else if(IRvalue == 0x0)
      {
        Sender.sendLG(0x20DF827D, 32);
        delay(200);
      }
      else if(IRvalue == 0x6)
      {
        Sender.sendLG(0x20DF22DD, 32);
        delay(200);
      }
      else if(IRvalue == 0x3F)
      {
        Sender.sendLG(0x20DFDA25, 32);
        delay(200);
      }
      
      Reciever.enableIRIn();
      Reciever.resume();
  }

  
}