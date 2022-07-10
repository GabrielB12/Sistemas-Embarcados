#include<Wire.h>
#include <string.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

char x;
int z, y;
const int led = 12;
const int Buzzer = 11;
const int bot1 = 10; 
const int bot2 = 9; 
int apertado1 = 0;
int apertado2 = 0;

int flagLCD;
String lcd_str;

unsigned long int lastDebounceTime1 = 0; 
unsigned long int lastDebounceTime2 = 0;
unsigned long int debounceDelay = 50;
int buttonState1; 
int buttonState2;
int lastButtonState1 = LOW; 
int lastButtonState2 = LOW;  
int estadoBot = 0;
int estadoBotAnt = 0;

void setup() {
  Wire.begin(9);
  Serial.begin(9600);
  Wire.onReceive(receiveEvent);
  
  // Saídas
  pinMode(led, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  
  // Entradas
  pinMode(bot1, INPUT);
  pinMode(bot2, INPUT);
  
  lcd.init();
  
  flagLCD = 0;
  lcd_str = "";
}


const int max = 20;
String str; // String que recebe os comandos
String aux;
int teste = 0;



void receiveEvent(int bytes) {
  String aux;

  while(Wire.available())
{
        char n = Wire.read();
        str.concat(n);
    }
  
  if(str == "LigarLed"){
    digitalWrite(led, HIGH); // acende o led
    str = ""; // limpar a string para próximo comando
  }
  else if(str == "DesligarLed"){
    digitalWrite(led, LOW);  // apaga o led
    str = ""; // limpar a string para próximo comando
  }
  else if(str == "LigarBuzzer"){
    digitalWrite(Buzzer, HIGH); // liga o buzzer
    str = ""; // limpar a string para próximo comando
  }
  else if(str == "DesligarBuzzer"){
    digitalWrite(Buzzer, LOW); // desliga o buzzer
    str = ""; // limpar a string para próximo comando
  }
  else if(str == "Display LCD"){
    str = "";
    teste = 1;
  }
  else if(teste == 1){
  	flagLCD = 1;
    teste = 0;
  }
}


void loop() {
  int reading1 = digitalRead(bot1);
  int reading2 = digitalRead(bot2);

    if (flagLCD == 1) {
    lcd.clear();
     lcd.setBacklight(HIGH);
    lcd.setCursor(0, 0);
    lcd.print(str);
    flagLCD = 0;
    str = "";
  }
    
  
    if (reading1 != lastButtonState1)
    {
        lastDebounceTime1 = millis();
    }
    if (reading2 != lastButtonState2)
    {
        lastDebounceTime2 = millis();
    }

    if ((millis() - lastDebounceTime1) > debounceDelay)
    {
        if (reading1 != buttonState1)
        {
            buttonState1 = reading1;
            if (buttonState1 == HIGH)
            {
                estadoBot = 1; //apertou o 1
            }
          else{
              estadoBot = 2; //soltou o 1
          }
        }
    }
    if ((millis() - lastDebounceTime2) > debounceDelay)
    {
        if (reading2 != buttonState2)
        {
            buttonState2 = reading2;
            if (buttonState2 == HIGH)
            {
                estadoBot = 3; //apertou o 2
            }
          else{
              estadoBot = 4; //soltou o 2
          }
        }
    }
    lastButtonState1 = reading1;
    lastButtonState2 = reading2;
  
  
  if(estadoBot != estadoBotAnt){ // se houver mudança
    estadoBotAnt = estadoBot; // troca o anterior
    Wire.beginTransmission(8);
    Wire.write(estadoBot); // manda o valor pro mestre
    Wire.endTransmission();
  }
  
    delay(2);
}
