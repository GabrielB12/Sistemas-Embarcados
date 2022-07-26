  char input;        // Variavel para armazenar o dado lido.
  unsigned int Control = 1;  // +++++++ VARIAVEL DE CONTROLE DA COMUNICAÇÃO ++++++++
                             // LEMBRE DE ALTERAR ESSA VARIAVE TAMBEM NO ARDUINO
  char string[20];
  int i = 0;
  int timeUnit = 100;

void ponto() // Emit sound for 100 milliseconds
{
    PORTC.RC1 = 0;
    //tone(buzzer, note, timeUnit);
    delay_ms(200);
    PORTC.RC1 = 1;
}

void barra() // Emit sound for 300 milliseconds
{
     PORTC.RC1 = 0;
    //tone(buzzer, note, timeUnit * 3);
    delay_ms(400);
    PORTC.RC1 = 1;
}

void letterPause() // Delay between letters for 300 milliseconds
{
    delay_ms(300);
}

void wordPause()
{
    delay_ms(700);
}

    // Funções das Letras
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

// FunÃ§Ãµes dos nÃºmeros
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

  void main(){
     TRISC.RC2 = 0;
     TRISC.RC1 = 0;
     TRISB =0;            // Define todos os pinos do PORTB como saída.
     PORTB = 0;           // Colocar todos os pinos em nível baixo.
     PORTD = 0;
     ADCON1 = 0x0f;       // Configura todos canais como Digital.
     PORTC.RC2 = 1;

     UART1_Init(9600);  // Utiliza bibliotecas do compilador para configuração o Baud rate.
     PWM1_Init(5000);
     PWM1_Start();

     while(1){
         if(UART1_Data_Ready()){  // Verifica se um dado foi recebido no buffer
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
        //  lcd.print(input);;
    }
     }
     }
     }
