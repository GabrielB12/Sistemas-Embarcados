const int LDR = 0;
const int LM35 = 1;
const int Buzzer = 2;
const int led[] = {5,6,7,8,9,10,11}; // leds 5, 6 e 7 são os de temperatura, (led[0-2])
int ValorLDR = 0;
int ADClido = 0;
float temperatura = 0;
float tempAnt = 0;
int pwm = 0;




void setup(){
  Serial.begin(9600);
  
for(int x = 0; x < 7 ; x++){
pinMode(led[x], OUTPUT);
}
pinMode(Buzzer,OUTPUT);

for(int i = 0; i < 3; i++){
  digitalWrite(led[i], HIGH);
}
}
void loop(){
ValorLDR = analogRead(LDR);
ADClido = analogRead(LM35);
temperatura = (ADClido * (500.0/1023)) - 50.0;
Serial.println(temperatura);
tempAnt = temperatura;
////////////////////////////////////////////
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
