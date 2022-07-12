int buzzer = 8; // Assign buzzer to pin 8
int note = 1000; // Set the pitch for the buzzer tone

int timeUnit = 100; // This variable will be used to measure pontos, barraes, breaks, and pauses
char input; // Variable to save the input to

void setup () {
  Serial.begin(9600);//for the connect with the boared
}

void loop () {
  if (Serial.available()) {
    input = Serial.read();//read the input
    if(input == 'a' || input == 'A'){
      lA();
    }
    if(input == 'a' || input == 'A'){
      lA();
    }
    if(input == 'b' || input == 'B'){
      lB();
    }
    if(input == 'c' || input == 'C'){
      lC();
    }
    if(input == 'd' || input == 'D'){
      lD();
    }
    if(input == 'e' || input == 'E'){
      lE();
    }
    if(input == 'f' || input == 'F'){
      lF();
    }
    if(input == 'g' || input == 'G'){
      lG();
    }
    if(input == 'h' || input == 'H'){
      lH();
    }
    if(input == 'i' || input == 'I'){
      lI();
    }
    if(input == 'j' || input == 'J'){
      lJ();
    }
    if(input == 'k' || input == 'K'){
      lK();
    }
    if(input == 'l' || input == 'L'){
      lL();
    }
    if(input == 'm' || input == 'M'){
      lM();
    }
    if(input == 'n' || input == 'N'){
      lN();
    }
    if(input == 'o' || input == 'O'){
      lO();
    }
    if(input == 'p' || input == 'P'){
      lP();
    }
    if(input == 'q' || input == 'Q'){
      lQ();
    }
    if(input == 'r' || input == 'R'){
      lR();
    }
    if(input == 's' || input == 'S'){
      lS();
    }
    if(input == 't' || input == 'T'){
      lT();
    }
    if(input == 'u' || input == 'U'){
      lU();
    }
    if(input == 'v' || input == 'V'){
      lV();
    }
    if(input == 'w' || input == 'W'){
      lW();
    }
    if(input == 'x' || input == 'X'){
      lX();
    }
    if(input == 'y' || input == 'Y'){
      lY();
    }
    if(input == 'z' || input == 'Z'){
      lZ();
    }
    if(input == ' '){
      wordPause();
    }
    Serial.println (input);

  }
}
//Letter functions
void lA () {
  ponto();  //letter A in morse code!
  barra();
  letterPause();
}
void lB () {
  barra();  //same for B
  ponto();
  ponto();
  ponto();
  letterPause();
}
void lC () {
  barra();
  ponto();
  barra();
  ponto();
  letterPause();
}
void lD () {
  barra();
  ponto();
  ponto();
  letterPause();
}
void lE () {
  ponto();
  letterPause();
}
void lF () {
  ponto();
  ponto();
  barra();
  ponto();
  letterPause();
}
void lG () {
  barra();
  barra();
  ponto();
  letterPause();
}
void lH () {
  ponto();
  ponto();
  ponto();
  ponto();
  letterPause();
}
void lI () {
  ponto();
  ponto();
  letterPause();
}
void lJ () {
  ponto();
  barra();
  barra();
  barra();
  letterPause();
}
void lK () {
  barra();
  ponto();
  barra();
  letterPause();
}
void lL () {
  ponto();
  barra();
  ponto();
  ponto();
  letterPause();
}
void lM () {
  barra();
  barra();
  letterPause();
}
void lN () {
  barra();
  ponto();
  letterPause();
}
void lO () {
  barra();
  barra();
  barra();
  letterPause();
}
void lP () {
  ponto();
  barra();
  barra();
  ponto();
  letterPause();
}
void lQ () {
  barra();
  barra();
  ponto();
  barra();
  letterPause();
}
void lR () {
  ponto();
  barra();
  ponto();
  letterPause();
}
void lS () {
  ponto();
  ponto();
  ponto();
  letterPause();
}
void lT () {
  barra();
  letterPause();
}
void lU () {
  ponto();
  ponto();
  barra();
  letterPause();
}
void lV () {
  ponto();
  ponto();
  ponto();
  barra();
  letterPause();
}
void lW () {
  ponto();
  barra();
  barra();
  letterPause();
}
void lX () {
  barra();
  ponto();
  ponto();
  barra();
  letterPause();
}
void lY () {
  barra();
  ponto();
  barra();
  barra();
  letterPause();
}
void lZ () {
  barra();
  barra();
  ponto();
  ponto();
  letterPause();
}

void ponto() //Emit sound for 100 milliseconds
{
  tone(buzzer, note, timeUnit);
  delay(timeUnit * 2);
}

void barra() //Emit sound for 300 milliseconds
{
  tone(buzzer, note, timeUnit * 3);
  delay(timeUnit * 4);
}

void letterPause() //Delay between letters for 300 milliseconds
{
  delay(timeUnit * 3);
}

void wordPause()
{
  delay (timeUnit * 7);
}
