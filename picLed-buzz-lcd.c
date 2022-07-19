//********************************************************************************
//
//                      PROGRAMA EXEMPLO: Display LCD 16x2.
//             OBJETIVO: Aprender a utilizar o LCD com o PIC18F4520.
//
//********************************************************************************

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

// --- Protótipo das Funções Auxiliares ---
void helloWorldPIC18();                        //Declara a função da mensagem no LCD, caractere por caractere


// --- Função Principal ---
void main()
{
     unsigned char ucStatus_inc; // Variavel de travamento do incremento.
   unsigned char ucStatus_dec; // Variavel de travamento do decremento.
   unsigned int  uiContador;   // Variavel de armazenamento do contador.
   unsigned int  uiValor;      // Variavel auxiliar para exibido do contador.
   unsigned char vet[5];

   ADCON1 = 0x0f;       // Configura todos canais como Digital.

   TRISB.RB2=1;         // Define o pino RB0 do PORTB como entrada.
   TRISB.RB1=1;         // Define o pino RB1 Do PORTB como entrada.
   TRISB.RB7=0;
   TRISC.RC1 = 0;

   TRISA.RA2=0;         // Define o pino RA2 do PORTA como saida(Sele??o Display 1).
   TRISA.RA3=0;         // Define o pino RA3 do PORTA como saida(Sele??o Display 2).
   TRISA.RA4=0;         // Define o pino RA4 do PORTA como saida(Sele??o Display 3).
   TRISA.RA5=0;         // Define o pino RA5 do PORTA como saida(Sele??o Display 4).

   TRISD = 0;           // Define todos os pinos Do PORTD como saida.

   ucStatus_inc=0;      // Inicializa a variavel com o valor 0.
   ucStatus_dec=0;      // Inicializa a variavel com o valor 0.
   uiContador=0;        // Inicializa a variavel com o valor 0.

     ADCON1  = 0x0F;                           //Configura os pinos como digitais


     Lcd_Init();                               //Inicializa módulo LCD
     Lcd_Cmd(_LCD_CURSOR_OFF);                 //Apaga cursor
     Lcd_Cmd(_LCD_CLEAR);                      //Limpa display

     while(1)
     {
        // Le Tecla E Incrementa Contador.
      if((PORTB.RB2==0)&&(ucStatus_inc==0)){   // Incrementa somente uma vez quando a tecla for pressionada.
         ucStatus_inc=1;                       // Variavel de travamento do incremento.
         uiContador++;                         // Esse operador aritmetico(++) realiza o mesmo que variavel = variavel + 1.
         if(uiContador>9999){ // Define o valor maximo a ser mostrado no displays como 9999.
            uiContador=9999;
         }
      }
      if((PORTB.RB2==1)&&(ucStatus_inc==1)){   // Volta a disponibilizar a op??o de incremento quando a tecla for solta.
         ucStatus_inc=0;
      }
      // Le tecla e decrementa contador.
      if((PORTB.RB1==0)&&(ucStatus_dec==0)){   // Decrementa somente uma vez quando a tecla for pressionada.
         ucStatus_dec=1;                       // Variavel de travamento do decremento.
         uiContador--;                         // Esse operador aritmetico(--) realiza o mesmo que variavel = variavel - 1.
         if(uiContador>9999){  // Define o valor maximo quando ocorrer a transicao (decremento) de 0 para 9999.
            uiContador=9999;
         }
      }
      if((PORTB.RB1==1)&&(ucStatus_dec==1)){   // Volta a disponibilizar a op??o de incremento quando a tecla for solta.
         ucStatus_dec=0;
      }

      uiValor = uiContador;                   // Coloca o conteudo da variavel do contador na varaivel auxiliar.
        //PORTB.RB7=0;         // Todos os pinos do PORTB em 0.
        if(uiContador % 2 == 0){
                PORTB.RB7=1;
        }
        else{
              PORTB.RB7=0;
        }
        if(uiContador % 3 == 0 && uiContador != 0){
                PORTC.RC1 = 0;
                //delay_ms(1000);
        }
        else{
              PORTC.RC1=1;
        }
        sprintf(vet, "%d", uiContador);
        lcd_out(1,1,vet);    // descomente essa função
        //delay_ms(1000);
     }
}
