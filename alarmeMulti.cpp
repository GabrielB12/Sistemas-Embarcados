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




void setup(){
  Serial.begin(9600);
  
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
ValorLDR = analogRead(LDR);
ADClido = analogRead(LM35);
  float tempAtual;
temperatura = (ADClido * (500.0/1023)) - 50.0;
Serial.println(temperatura);
////////////////////////////////////////////
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
    
    //Apitar buzzer a cada 2 segundos
    digitalWrite(Buzzer, HIGH);
    digitalWrite(Buzzer, LOW);
    delay(2000); //esperar 2 segundos - fazer com millis()
    
  }
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
  Serial.println(temperatura); // colocar o millis()
  
/*
for(int i = 255; i > 0; i--){
  analogWrite(led[0], i);
  delay(10);
  }
  */
///////////////////////////////////////////////  
/*
if (temperatura > 20.00){
digitalWrite(led[0], HIGH);
}
else{
digitalWrite(led[0], LOW);
}
if (temperatura > 22.00){
digitalWrite(led[1], HIGH);
}
else{
digitalWrite(led[1], LOW);
}
if (temperatura > 24.00){
digitalWrite(led[2], HIGH);
}
else{
digitalWrite(led[2], LOW);
}
if (ValorLDR > 500){
digitalWrite(led[5], HIGH);
}
else{
digitalWrite(led[5], LOW);
}

if (ValorLDR > 400){
digitalWrite(led[4], HIGH);
}
else{
digitalWrite(led[4], LOW);
}
if (ValorLDR > 350){
digitalWrite(led[3], HIGH);
digitalWrite(led[6], LOW);
digitalWrite(Buzzer, LOW);
}
else{
digitalWrite(led[3], LOW);
digitalWrite(led[6], HIGH);
digitalWrite(Buzzer, HIGH);
}*/
}
