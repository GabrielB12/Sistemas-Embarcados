#include <Wire.h>
#include <string.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int buzzer = 8;     // buzzer no pino 8
int note = 1000;    // Set the pitch for the buzzer tone
const int led = 12; // numero do led
const int bot = 11; // botão no 11

int pwm = 0;
unsigned long periodo; // comparação para o millis

int buttonState;
int lastButtonState = LOW;
unsigned long int lastDebounceTime = 0;
unsigned long int debounceDelay = 50;
int estadoBot = 0;
int estadoBotAnt = 0;

int timeUnit = 100; // This variable will be used to measure pontos, barraes, breaks, and pauses
char input;         // entrada
int controleLCD = 0;

String str;

void setup()
{
    Serial.begin(9600); // for the connect with the boared
    lcd.init();         // inicia o lcd

    pinMode(led, OUTPUT);
    pinMode(buzzer, OUTPUT);

    pinMode(bot, INPUT);
}

void loop()
{
    int reading = digitalRead(bot);
    if (reading != lastButtonState)
    {
        lastDebounceTime = millis();
    }
    if ((millis() - lastDebounceTime) > debounceDelay)
    {
        if (reading != buttonState)
        {
            buttonState = reading;
            if (buttonState == HIGH)
            {
                for (pwm = 0; pwm < 255; pwm++)
                {
                    analogWrite(led, pwm);
                    periodo = millis();
                    while (millis() < periodo + 1)
                    {
                    }
                }
                estadoBot++; // apertou o 1
            }
            else
            {
                estadoBot = 0; // soltou o 1, o valor do botão volta pra zero, para a mensagem só aparecer quando apertado
                for (pwm = 255; pwm > 0; pwm--)
                {
                    analogWrite(led, pwm);
                    periodo = millis();
                    while (millis() < periodo + 1)
                    {
                    }
                }
            }
        }
    }
    lastButtonState = reading;

    if (Serial.available() && (estadoBot > 0)) // se tiver mensagem espera o botão ser apertado
    {
        estadoBotAnt = estadoBot; // troca o anterior
        input = Serial.read();    // read the input
        str.concat(input);
        if (input == 'a' || input == 'A')
        {
            lA();
        }
        if (input == 'a' || input == 'A')
        {
            lA();
        }
        if (input == 'b' || input == 'B')
        {
            lB();
        }
        if (input == 'c' || input == 'C')
        {
            lC();
        }
        if (input == 'd' || input == 'D')
        {
            lD();
        }
        if (input == 'e' || input == 'E')
        {
            lE();
        }
        if (input == 'f' || input == 'F')
        {
            lF();
        }
        if (input == 'g' || input == 'G')
        {
            lG();
        }
        if (input == 'h' || input == 'H')
        {
            lH();
        }
        if (input == 'i' || input == 'I')
        {
            lI();
        }
        if (input == 'j' || input == 'J')
        {
            lJ();
        }
        if (input == 'k' || input == 'K')
        {
            lK();
        }
        if (input == 'l' || input == 'L')
        {
            lL();
        }
        if (input == 'm' || input == 'M')
        {
            lM();
        }
        if (input == 'n' || input == 'N')
        {
            lN();
        }
        if (input == 'o' || input == 'O')
        {
            lO();
        }
        if (input == 'p' || input == 'P')
        {
            lP();
        }
        if (input == 'q' || input == 'Q')
        {
            lQ();
        }
        if (input == 'r' || input == 'R')
        {
            lR();
        }
        if (input == 's' || input == 'S')
        {
            lS();
        }
        if (input == 't' || input == 'T')
        {
            lT();
        }
        if (input == 'u' || input == 'U')
        {
            lU();
        }
        if (input == 'v' || input == 'V')
        {
            lV();
        }
        if (input == 'w' || input == 'W')
        {
            lW();
        }
        if (input == 'x' || input == 'X')
        {
            lX();
        }
        if (input == 'y' || input == 'Y')
        {
            lY();
        }
        if (input == 'z' || input == 'Z')
        {
            lZ();
        }
        if (input == '0')
        {
            l0();
        }
        if (input == '1')
        {
            l1();
        }
        if (input == '2')
        {
            l2();
        }
        if (input == '3')
        {
            l3();
        }
        if (input == '4')
        {
            l4();
        }
        if (input == '5')
        {
            l5();
        }
        if (input == '6')
        {
            l6();
        }
        if (input == '7')
        {
            l7();
        }
        if (input == '8')
        {
            l8();
        }
        if (input == '9')
        {
            l9();
        }
        if (input == ' ')
        {
            wordPause();
        }
        // Serial.println(input);
        //  lcd.clear();
        //  lcd.setBacklight(HIGH);
        //  lcd.print(input);
        controleLCD = 1;
    }
    // printaLcd();
    if (controleLCD == 1)
    {
        if (!Serial.available())
        { // quando acabou de ler
            Serial.println(str);
            lcd.clear();
            lcd.setBacklight(HIGH);
            lcd.setCursor(0, 0);
            lcd.print(str);
            // Serial.println("Mensagem alterada");
            controleLCD = 0;
            str = "";
        }
    }
}

void printaLcd()
{
    if (controleLCD == 1)
    {
        Serial.println(input);
        lcd.clear();
        lcd.setBacklight(HIGH);
        lcd.setCursor(0, 0);
        lcd.print(str);
        str = "";
        controleLCD = 0;
    }
}

// Letter functions
void lA()
{
    ponto(); // letter A in morse code!
    barra();
    letterPause();
}
void lB()
{
    barra(); // same for B
    ponto();
    ponto();
    ponto();
    letterPause();
}
void lC()
{
    barra();
    ponto();
    barra();
    ponto();
    letterPause();
}
void lD()
{
    barra();
    ponto();
    ponto();
    letterPause();
}
void lE()
{
    ponto();
    letterPause();
}
void lF()
{
    ponto();
    ponto();
    barra();
    ponto();
    letterPause();
}
void lG()
{
    barra();
    barra();
    ponto();
    letterPause();
}
void lH()
{
    ponto();
    ponto();
    ponto();
    ponto();
    letterPause();
}
void lI()
{
    ponto();
    ponto();
    letterPause();
}
void lJ()
{
    ponto();
    barra();
    barra();
    barra();
    letterPause();
}
void lK()
{
    barra();
    ponto();
    barra();
    letterPause();
}
void lL()
{
    ponto();
    barra();
    ponto();
    ponto();
    letterPause();
}
void lM()
{
    barra();
    barra();
    letterPause();
}
void lN()
{
    barra();
    ponto();
    letterPause();
}
void lO()
{
    barra();
    barra();
    barra();
    letterPause();
}
void lP()
{
    ponto();
    barra();
    barra();
    ponto();
    letterPause();
}
void lQ()
{
    barra();
    barra();
    ponto();
    barra();
    letterPause();
}
void lR()
{
    ponto();
    barra();
    ponto();
    letterPause();
}
void lS()
{
    ponto();
    ponto();
    ponto();
    letterPause();
}
void lT()
{
    barra();
    letterPause();
}
void lU()
{
    ponto();
    ponto();
    barra();
    letterPause();
}
void lV()
{
    ponto();
    ponto();
    ponto();
    barra();
    letterPause();
}
void lW()
{
    ponto();
    barra();
    barra();
    letterPause();
}
void lX()
{
    barra();
    ponto();
    ponto();
    barra();
    letterPause();
}
void lY()
{
    barra();
    ponto();
    barra();
    barra();
    letterPause();
}
void lZ()
{
    barra();
    barra();
    ponto();
    ponto();
    letterPause();
}

// Funções dos números
void l0()
{
    barra();
    barra();
    barra();
    barra();
    barra();
    letterPause();
}

void l1()
{
    ponto();
    barra();
    barra();
    barra();
    barra();
    letterPause();
}

void l2()
{
    ponto();
    ponto();
    barra();
    barra();
    barra();
    letterPause();
}

void l3()
{
    ponto();
    ponto();
    ponto();
    barra();
    barra();
    letterPause();
}

void l4()
{
    ponto();
    ponto();
    ponto();
    ponto();
    barra();
    letterPause();
}

void l5()
{
    ponto();
    ponto();
    ponto();
    ponto();
    ponto();
    letterPause();
}

void l6()
{
    barra();
    ponto();
    ponto();
    ponto();
    ponto();
    letterPause();
}

void l7()
{
    barra();
    barra();
    ponto();
    ponto();
    ponto();
    letterPause();
}

void l8()
{
    barra();
    barra();
    barra();
    ponto();
    ponto();
    letterPause();
}

void l9()
{
    barra();
    barra();
    barra();
    barra();
    ponto();
    letterPause();
}

void ponto() // Emit sound for 100 milliseconds
{
    tone(buzzer, note, timeUnit);
    delay(timeUnit * 2);
}

void barra() // Emit sound for 300 milliseconds
{
    tone(buzzer, note, timeUnit * 3);
    delay(timeUnit * 4);
}

void letterPause() // Delay between letters for 300 milliseconds
{
    delay(timeUnit * 3);
}

void wordPause()
{
    delay(timeUnit * 7);
}
