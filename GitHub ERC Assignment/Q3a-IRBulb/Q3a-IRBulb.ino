int sensor=A0;  //Analog 0 pin named as sensor
int output=9;   //Pin-9 is declared as output
#include <IRremote.h>
int max=255;
int min=0;
int RECV_PIN = 2;
int lite=0;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()                                                          
{
pinMode(output, OUTPUT); //Pin-9 is declared as output 
//We dont need to declare the A0 pin as input since it is predefined as input                                                
Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{ 
  if(irrecv.decode(&results)){             //1 is turn led on
  
    switch(results.value){
    case 0xFD50AF:
      lite=lite+5;
      
      if(lite<255)
      {
      analogWrite(output, lite);
        Serial.println(lite);
      break;
      }
      if(lite>=255)
      {
        lite=255;
        analogWrite(output,max);
        Serial.println(lite);
        break;
      }
         
    case 0xFD10EF:
      lite=lite-5;
      
      if(lite>0)
      {
        analogWrite(output,lite);
        Serial.println(lite);
        break;
      }
      if(lite<=0)
      { 
        lite=0;
        analogWrite(output,min);
        Serial.println(lite);
      break;
      }
    }
    irrecv.resume();
  
  }
  delay(100);
}

