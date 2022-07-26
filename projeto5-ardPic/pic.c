  char ucRead;        // Variavel para armazenar o dado lido.
  unsigned int Control = 1;  // +++++++ VARIAVEL DE CONTROLE DA COMUNICAÇÃO ++++++++
                             // LEMBRE DE ALTERAR ESSA VARIAVE TAMBEM NO ARDUINO
  char string[20];
  int i = 0;

  void main(){
     TRISC.RC1 = 0;
     TRISB =0;            // Define todos os pinos do PORTB como saída.
     PORTB = 0;           // Colocar todos os pinos em nível baixo.
     PORTD = 0;
     ADCON1 = 0x0f;       // Configura todos canais como Digital.

     UART1_Init(9600);  // Utiliza bibliotecas do compilador para configuração o Baud rate.

     while(1){  // SELECIONE A VARIAVEL DE CONTROLE (CONTROL) DECLARADA ACIMA.
         memset(string, 0, sizeof string);
         while(UART1_Data_Ready()){  // Verifica se um dado foi recebido no buffer

           ucRead = UART1_Read(); // Lê o dado recebido do buffer.
           //LED
           if (strcmp(ucRead, 1) == 0){
            PORTB.RB7=1;
            }
           else if(strcmp(ucRead, 2) == 0){
            PORTB.RB7=0;
            }
           //BUZZER
           else if(strcmp(ucRead, 3) == 0){
            PORTC.RC1 = 1;   //inversão de estado
            }
           else if(strcmp(ucRead, 4) == 0){
            PORTC.RC1 = 1;   //inversão de estado
            }
           //VENTOINHA
           else if(strcmp(ucRead, 4) == 0){
            PORTC.RC1 = 1;   //inversão de estado
            }
           else if(strcmp(ucRead, 4) == 0){
            PORTC.RC1 = 1;   //inversão de estado
            }
           
           }
     }
     }
