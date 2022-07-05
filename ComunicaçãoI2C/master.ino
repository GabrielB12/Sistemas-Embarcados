#include<Wire.h>
char incomingByte;
String str;
void setup() {
  Wire.begin(8); 
  Serial.begin(9600);
  Wire.onReceive(receiveEvent);
}
int i = 0;
void loop() {
  Wire.beginTransmission(9);
  if(Serial.available()){
  incomingByte = Serial.read();
  str.concat(incomingByte);
  Wire.write(incomingByte);
  Wire.endTransmission(); 
  }
  if(str == "LigarLed"){
  	Serial.println("Led Ligado");
    str = "";
  }
  if(str == "DesligarLed"){
  	Serial.println("Led Desligado");
    str = "";
  }
  if(str == "LigarBuzzer"){
  	Serial.println("Buzzer Ligado");
    str = "";
  }
  if(str == "DesligarBuzzer"){
  	Serial.println("Buzzer Desligado");
    str = "";
  }
  delay(1);
}

void receiveEvent(int bytes) {
  if (Wire.available()) {
    int est = Wire.read();

    if (est == 1) {
        Serial.println("Chave 1 ON");
      } 
    else if (est == 2) {
        Serial.println("Chave 1 OFF");
      }
    else if (est == 3) {
        Serial.println("Chave 2 ON");
      }
    else if (est == 4) {
        Serial.println("Chave 2 OFF");
      }
      est = 0;
    }
  }
