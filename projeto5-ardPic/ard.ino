const int ledPin = 13; // Pino ao qual o LED será conectado
int piscando = 0; // variável para armazenar taxa de “piscagem”
int Control = 1;  // +++++++ VARIAVEL DE CONTROLE DA COMUNICAÇÃO ++++++++
                  // LEMBRE DE ALTERAR ESSA VARIÁVEL TAMBEM NO PIC
                  
char incomingByte;

void setup() {
Serial.begin(9600);
Serial1.begin(9600);
pinMode(ledPin, OUTPUT); // Pino 13 será de saída de sinais
}
 
void loop()
{
      if(Serial.available()){
          incomingByte = Serial.read();
          Serial1.write(incomingByte);
      }  
     }
