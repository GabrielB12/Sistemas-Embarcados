const int ledPin = 13; // Pino ao qual o LED será conectado
int Control = 1;  // +++++++ VARIAVEL DE CONTROLE DA COMUNICAÇÃO ++++++++
                  // LEMBRE DE ALTERAR ESSA VARIÁVEL TAMBEM NO PIC
                  
char incomingByte;
String str;

void setup() {
Serial.begin(9600);
Serial1.begin(9600);
pinMode(ledPin, OUTPUT); // Pino 13 será de saída de sinais
}
 
void loop()
{
      if(Serial.available()){
          incomingByte = Serial.read();
          str.concat(incomingByte);
          //Serial1.write(incomingByte);
      }
      if(str == "LigarLed B7"){
          Serial1.write(1);
      }
      else if(str == "DesligarLed B7"){
          Serial1.write(2);
      }
      else if(str == "AcionarBuzzer"){
          Serial1.write(3);
      } 
     else if(str == "DesligarBuzzer"){
          Serial1.write(4);
      }
     else if(str == "LigarVento"){
          Serial1.write(5);
      }
     else if(str == "DesligarVento"){
          Serial1.write(6);
      }
     }
