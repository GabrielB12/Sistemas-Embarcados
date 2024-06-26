const int LDR = 0;
const int LM35 = 1;
const int Buzzer = 2;
const int led[] = {5, 6, 7, 8, 9, 10, 11}; // leds 5, 6 e 7 são os de temperatura, (led[0-2])
int ValorLDR = 0;
int ADClido = 0;
float temperatura = 0;
float tempIni = 0;
int pwm = 0;
int controle[] = {0, 0, 0}; // variaveis de controle para saber se entra no if ou não
int controle1[] = {0, 0, 0, 0};
int controleBuzz = 0;

unsigned long tempoAnt;     // variavél para salvar o tempo da iteração anterior
unsigned long tempoImprime; // tempo da iteração atial
unsigned long periodo;      // comparação para o millis

void setup()
{
    Serial.begin(9600);
    tempoAnt = millis();

    for (int x = 0; x < 7; x++)
    {
        pinMode(led[x], OUTPUT);
    }
    pinMode(Buzzer, OUTPUT);

    // LEDS DE TEMPERATURA ACESOS
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(led[i], HIGH);
    }
    // LEDS DE LUMINOSIDADE APAGADOS
    for (int i = 3; i < 7; i++)
    {
        digitalWrite(led[i], LOW);
    }
    // PRIMEIRO VALOR DE TEMPERATURA MEDIDO
    tempIni = analogRead(LM35);
    tempIni = tempIni * 0.4887585532;
}

void loop()
{

    ValorLDR = analogRead(LDR);
    ADClido = analogRead(LM35);
    float tempAtual;
    temperatura = ADClido * 0.4887585532;
     // MOSTRAR A TEMPERATURA A CADA 1 SEGUNDO NO MONITOR SERIAL
    if (millis() >= (tempoImprime + 1000))
    {
      Serial.println(temperatura);
      //Serial.println(ValorLDR);
      tempoImprime = millis();
    }
    //////////////// APAGAR - TEMPERATURA ////////////////////////
    if (temperatura >= tempIni + 2 && controle[0] == 0)
    { // apaga o primeiro
        for (pwm = 255; pwm > 0; pwm--)
        {
            analogWrite(led[0], pwm);
            // delay(10);
            periodo = millis();
            while (millis() < periodo + 1)
            {
            }
        }
        controle[0] = 1;
    }
    if (temperatura >= tempIni + 4 && controle[1] == 0)
    { // apaga o segundo
        for (pwm = 255; pwm > 0; pwm--)
        {
            analogWrite(led[1], pwm);
            // delay(10);
            periodo = millis();
            while (millis() < periodo + 1)
            {
            }
        }
        controle[1] = 1;
    }
    if (temperatura >= tempIni + 6 && controle[2] == 0)
    { // apaga o terceiro

        for (pwm = 255; pwm > 0; pwm--)
        {
            analogWrite(led[2], pwm);
            // delay(10);
            periodo = millis();
            while (millis() < periodo + 1)
            {
            }
        }
        controle[2] = 1;
    }

    // Apitar buzzer a cada 2 segundos
    if (temperatura >= tempIni + 6 && millis() >= (tempoAnt + 2000))
    {
        digitalWrite(Buzzer, HIGH);
        tempoAnt = millis();
    }
    else
    {
        digitalWrite(Buzzer, LOW);
    }

    //////////////// ACENDER - TEMPERATURA ////////////////////////
    tempAtual = tempIni + 6;
    if (temperatura <= tempAtual - 2 && controle[2] == 1)
    { // acendendo todos
        for (pwm = 0; pwm < 255; pwm++)
        {
            analogWrite(led[2], pwm);
            // delay(10);
            periodo = millis();
            while (millis() < periodo + 1)
            {
            }
        }
        controle[2] = 0; // voltando para 0, para poder entrar no if novamente
    }
    if (temperatura <= tempAtual - 4 && controle[1] == 1)
    {
        for (pwm = 0; pwm < 255; pwm++)
        {
            analogWrite(led[1], pwm);
            // delay(10);
            periodo = millis();
            while (millis() < periodo + 1)
            {
            }
        }
        controle[1] = 0; // voltando para 0, para poder entrar no if novamente
    }
    if (temperatura <= tempAtual - 6 && controle[0] == 1)
    {
        for (pwm = 0; pwm < 255; pwm++)
        {
            analogWrite(led[0], pwm);
            // delay(10);
            periodo = millis();
            while (millis() < periodo + 1)
            {
            }
        }
        controle[0] = 0; // voltando para 0, para poder entrar no if novamente
    }

    ////////////////// PARTE DE LUMINOSIDADE ////////////////////////
    // ValorLDR

    if (ValorLDR > 10 && controle1[0] == 0)
    {
        for (pwm = 0; pwm < 255; pwm++)
        {
            analogWrite(led[3], pwm);
            periodo = millis();
            while (millis() < periodo + 1)
            {
            }
        }
        controle1[0] = 1;
    }
    if (ValorLDR > 30 && controle1[1] == 0)
    {
        for (pwm = 0; pwm < 255; pwm++)
        {
            analogWrite(led[4], pwm);
            periodo = millis();
            while (millis() < periodo + 1)
            {
            }
        }
        controle1[1] = 1;
    }
    if (ValorLDR > 55 && controle1[2] == 0)
    {
        for (pwm = 0; pwm < 255; pwm++)
        {
            analogWrite(led[5], pwm);
            periodo = millis();
            while (millis() < periodo + 1)
            {
            }
        }
        controle1[2] = 1;
    }
    if (ValorLDR > 130 && controle1[3] == 0)
    {
        for (pwm = 0; pwm < 255; pwm++)
        {
            analogWrite(led[6], pwm);
            periodo = millis();
            while (millis() < periodo + 1)
            {
            }
        }
        controle1[3] = 1;
    }
    if (ValorLDR > 150 && controleBuzz == 0)
    {
        digitalWrite(Buzzer, HIGH);
        controleBuzz = 1;
        unsigned long int esp = millis();
        while (millis() - esp < 3000) // apita por 3 segundos
        {
        }
        digitalWrite(Buzzer, LOW);
    }
  if (ValorLDR < 130 && controle1[3] == 1)
    {
        for (pwm = 255; pwm > 0; pwm--)
        {
            analogWrite(led[6], pwm);
            periodo = millis();
            while (millis() < periodo + 16) // vai apagando por 4 segundos (16*255)
            {
            }
        }
        controle1[3] = 0;
    }
    if (ValorLDR < 55 && controle1[2] == 1)
    {
        for (pwm = 255; pwm > 0; pwm--)
        {
            analogWrite(led[5], pwm);
            periodo = millis();
            while (millis() < periodo + 16) // vai apagando por 4 segundos (16*255)
            {
            }
        }
        controle1[2] = 0;
    }

    if (ValorLDR < 30 && controle1[1] == 1)
    {
        for (pwm = 255; pwm > 0; pwm--)
        {
            analogWrite(led[4], pwm);
            periodo = millis();
            while (millis() < periodo + 16) // vai apagando por 4 segundos (16*255)
            {
            }
        }
        controle1[1] = 0;
    }

    if (ValorLDR < 10 && controle1[0] == 1)
    {
        for (pwm = 255; pwm > 0; pwm--)
        {
            analogWrite(led[3], pwm);
            periodo = millis();
            while (millis() < periodo + 16) // vai apagando por 4 segundos (16*255)
            {
            }
        }
        controle1[0] = 0;
    }
}
