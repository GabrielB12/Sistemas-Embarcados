// --- Ligações entre PIC e LCD ---
sbit LCD_RS at RE2_bit;   // PINO 2 DO PORTD LIGADO AO RS DO DISPLAY
sbit LCD_EN at RE1_bit;   // PINO 3 DO PORTD LIGADO AO EN DO DISPLAY
sbit LCD_D7 at RD7_bit;  // PINO 7 DO PORTD LIGADO AO D7 DO DISPLAY
sbit LCD_D6 at RD6_bit;  // PINO 6 DO PORTD LIGADO AO D6 DO DISPLAY
sbit LCD_D5 at RD5_bit;  // PINO 5 DO PORTD LIGADO AO D5 DO DISPLAY
sbit LCD_D4 at RD4_bit;  // PINO 4 DO PORTD LIGADO AO D4 DO DISPLAY

// Selecionando direção de fluxo de dados dos pinos utilizados para a comunicação com display LCD
sbit LCD_RS_Direction at TRISE2_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 2 DO PORTD
sbit LCD_EN_Direction at TRISE1_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 3 DO PORTD
sbit LCD_D7_Direction at TRISD7_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 7 DO PORTD
sbit LCD_D6_Direction at TRISD6_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 6 DO PORTD
sbit LCD_D5_Direction at TRISD5_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 5 DO PORTD
sbit LCD_D4_Direction at TRISD4_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 4 DO PORTD  

char input;        // Variavel para armazenar o dado lido.
  unsigned int Control = 1;  // +++++++ VARIAVEL DE CONTROLE DA COMUNICAÇÃO ++++++++
                             // LEMBRE DE ALTERAR ESSA VARIAVE TAMBEM NO ARDUINO
  char string[20];
  int i = 0;
  int timeUnit = 100;

void ImprimePonto(){
    lcd_chr_cp(".");
}

void ImprimeBarra(){
    lcd_chr_cp("-");
}

void ponto() // 100ms
{
    PORTC.RC1 = 0;
    delay_ms(100);
    PORTC.RC1 = 1;
}

void barra() // 300ms
{
     PORTC.RC1 = 0;
    delay_ms(300);
    PORTC.RC1 = 1;
}

void letterPause() // espera entre letras 400ms
{
    delay_ms(400);
}

void wordPause() // espera entre palavras 600ms
{
    delay_ms(600);
}

    // Funções das Letras em código morse
void lA()
{
    ponto();
    ImprimePonto();
    barra();
  ImprimeBarra();
    ImprimeBarra();
    letterPause();
}
void lB()
{
    barra();
  ImprimeBarra();
    ponto();
    ImprimePonto();
    ponto();
    ImprimePonto();
    ponto();
    ImprimePonto();
    letterPause();
}
void lC()
{
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    letterPause();
}
void lD()
{
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    letterPause();
}
void lE()
{
    ponto();
  ImprimePonto();
    letterPause();
}
void leF()
{
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    letterPause();
}
void lG()
{
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    letterPause();
}
void lH()
{
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    letterPause();
}
void lI()
{
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    letterPause();
}
void lJ()
{
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    letterPause();
}
void lK()
{
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    letterPause();
}
void lL()
{
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    letterPause();
}
void lM()
{
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    letterPause();
}
void lN()
{
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    letterPause();
}
void lO()
{
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    letterPause();
}
void lP()
{
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    letterPause();
}
void lQ()
{
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    letterPause();
}
void lR()
{
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    letterPause();
}
void lS()
{
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    letterPause();
}
void lT()
{
    barra();
  ImprimeBarra();
    letterPause();
}
void lU()
{
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    letterPause();
}
void lV()
{
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    letterPause();
}
void lW()
{
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    letterPause();
}
void lX()
{
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    letterPause();
}
void lY()
{
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    letterPause();
}
void lZ()
{
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    letterPause();
}

// FunÃ§Ãµes dos nÃºmeros
void l0()
{
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    letterPause();
}

void l1()
{
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    letterPause();
}

void l2()
{
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    letterPause();
}

void l3()
{
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    letterPause();
}

void l4()
{
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    barra();
  ImprimeBarra();
    letterPause();
}

void l5()
{
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    letterPause();
}

void l6()
{
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    letterPause();
}

void l7()
{
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    letterPause();
}

void l8()
{
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    ponto();
  ImprimePonto();
    letterPause();
}

void l9()
{
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    barra();
  ImprimeBarra();
    ponto();
  ImprimePonto();
    letterPause();
}

  void main(){
     TRISC.RC2 = 0;
     TRISC.RC1 = 0;
     TRISB =0;            // Define todos os pinos do PORTB como saída.
     TRISD = 0;
     PORTB = 0;           // Colocar todos os pinos em nível baixo.
     PORTD = 0;
     ADCON1 = 0x0f;       // Configura todos canais como Digital.
     PORTC.RC2 = 1;
    
    TRISA.RA2=0;         // Define o pino RA2 do PORTA como saida(Sele??o Display 1).
    TRISA.RA3=0;         // Define o pino RA3 do PORTA como saida(Sele??o Display 2).
    TRISA.RA4=0;         // Define o pino RA4 do PORTA como saida(Sele??o Display 3).
    TRISA.RA5=0;         // Define o pino RA5 do PORTA como saida(Sele??o Display 4).

     UART1_Init(9600);  // Utiliza bibliotecas do compilador para configuração o Baud rate.
     PWM1_Init(5000);
     PWM1_Start();
    
     Lcd_Init();                               //Inicializa módulo LCD
     Lcd_Cmd(_LCD_CURSOR_OFF);                 //Apaga cursor
     Lcd_Cmd(_LCD_CLEAR);                      //Limpa display

     while(1){
         if(UART1_Data_Ready()){  // Verifica se um dado foi recebido no buffer
         input = UART1_Read();
         if(input == 101){
                  for(i = 0; i < 100; i++){
                        PORTB=0x00;         // Todos os pinos do PORTB em 0.
                        PORTD=0x00;
                        Delay_ms(100);  // Esta função é interna do compilador, portanto o tempo é de 1000ms ou 1 segundo.
                        PORTD=0xff;
                        PORTB=0xff;       // Todos os pinos do PORTB em 1.
                        Delay_ms(100);  // Aguarda novamente 1 segundo.
                        }
         }
         if(strcmp(input, 'a') == 0 || strcmp(input, 'a')){
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
            leF();
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
    }
       Lcd_Cmd(_LCD_CURSOR_OFF);                 //Apaga cursor
        Lcd_Cmd(_LCD_CLEAR);                      //Limpa display
     }
     }
