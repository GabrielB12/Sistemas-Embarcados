#include<Wire.h>
char incomingByte;
String str;
void setup() {
  Wire.begin(8); 
  Serial.begin(9600);
  Wire.onReceive(receiveEvent);
}
int i = 0;
int teste = 0;

void loop() {
  String aux;
  
  if(Serial.available()){
  	Wire.beginTransmission(9);
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
  if(str == "Display LCD"){
    Serial.println("Digite a mensagem desejada");
    teste = 1;
    str = "";
  }
  if(teste == 1){
    Wire.beginTransmission(9);
    	while(!Serial.available()){
      		continue;
    	}
      while(Serial.available()){
    	//incomingByte = Serial.read();
        //aux.concat(incomingByte);
  		//Wire.write(incomingByte);
        
      	aux = Serial.readString();
      	Wire.write(aux.c_str());
      }
    if(!Serial.available()){ // quando acabou de ler
      Serial.println(aux);
      Serial.println("Mensagem alterada");
      teste = 0;
      aux = "";
    }
    Wire.endTransmission();
    }
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
