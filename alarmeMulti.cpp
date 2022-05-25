const int LDR = 0;
const int LM35 = 1;
const int Buzzer = 2;
const int led[] = {5,6,7,8,9,10,11}; // leds 5, 6 e 7 são os de temperatura, (led[0-2])
int ValorLDR = 0;
int ADClido = 0;
float temperatura = 0;
float tempIni = 0;
int pwm = 0;
int controle[] = {0, 0, 0}; // variaveis de controle para saber se entra no if ou não

unsigned long tempoAnt;   // variavél para salvar o tempo da iteração anterior
unsigned long tempoImprime; // tempo da iteração atial
unsigned long periodo;    // comparação para o millis


void setup(){
  Serial.begin(9600);
  tempoAnt = millis();
  
for(int x = 0; x < 7 ; x++){
pinMode(led[x], OUTPUT);
}
pinMode(Buzzer,OUTPUT);

for(int i = 0; i < 3; i++){
  digitalWrite(led[i], HIGH);
}
  // PRIMEIRO VALOR DE TEMPERATURA MEDIDO
  tempIni = analogRead(LM35);
  tempIni = (tempIni * (500.0/1023)) - 50.0;
}

void loop(){
// VARIAVEIS PARA CONTROLE DO TEMPO
tempoAtual = millis();
periodo = tempoAtual - tempoAnt;
  
ValorLDR = analogRead(LDR);
ADClido = analogRead(LM35);
  float tempAtual;
temperatura = (ADClido * (500.0/1023)) - 50.0;
Serial.println(temperatura);
//////////////// APAGAR - TEMPERATURA ////////////////////////
  if(temperatura >= tempIni + 2 && controle[0] == 0){ // apaga o primeiro
    for(pwm = 255; pwm > 0; pwm--){
  		analogWrite(led[0], pwm);
  		delay(10);
  }
      	controle[0] = 1;
  }
  if(temperatura >= tempIni + 4 && controle[1] == 0){ // apaga o segundo
  	for(pwm = 255; pwm > 0; pwm--){
  		analogWrite(led[1], pwm);
  		delay(10);
  }
      	controle[1] = 1;
  }
  if(temperatura >= tempIni + 6 && controle[2] == 0){ // apaga o terceiro
    
    for(pwm = 255; pwm > 0; pwm--){
  		analogWrite(led[2], pwm);
  		delay(10);
  }
      	controle[2] = 1;  
  }
    
  //Apitar buzzer a cada 2 segundos
    if (temperatura >= tempIni + 6 && millis() >= (tempoAnt + 2000)) 
  {
    digitalWrite(Buzzer, HIGH);
    tempoAnt = millis();
  }
  else{
  	digitalWrite(Buzzer, LOW);
  }
  
  
  //////////////// ACENDER - TEMPERATURA ////////////////////////
  tempAtual = tempIni + 6;
  if(temperatura <= tempAtual - 2 && controle[2] == 1){ //acendendo todos
    for(pwm = 0; pwm < 255; pwm++){
  		analogWrite(led[2], pwm);
  		delay(10);
  }
    controle[2] = 0; //voltando para 0, para poder entrar no if novamente
  }
  if(temperatura <= tempAtual - 4 && controle[1] == 1){
  	for(pwm = 0; pwm < 255; pwm++){
  		analogWrite(led[1], pwm);
  		delay(10);
  }
    controle[1] = 0; //voltando para 0, para poder entrar no if novamente
  }
  if(temperatura <= tempAtual - 6 && controle[0] == 1){
  	for(pwm = 0; pwm < 255; pwm++){
  		analogWrite(led[0], pwm);
  		delay(10);
  }
    controle[0] = 0; //voltando para 0, para poder entrar no if novamente
  }
  // MOSTRAR A TEMPERATURA A CADA 1 SEGUNDO NO MONITOR SERIAL
   if (millis() >= (tempoImprime + 1000)) 
  {
    Serial.println(temperatura);
    tempoImprime = millis();
  }

///////////////////////////////////////////////  
}
