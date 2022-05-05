// FAROL A
const int vermelhoA = 13;
const int amareloA = 12;
const int verdeA = 11;

// FAROL B
const int vermelhoB = 7;
const int amareloB = 6;
const int verdeB = 5;

// BOTÃO
const int botao = 8;
int counter = 0; // contador para ver o numero de vezes que o botão foi acionado
int apertado = 0;

// TEMPO DE FAROL ACESO
int verde = 1000;
int amarelo = 500;

// PARA DEBOUNCE
unsigned long int lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long int debounceDelay = 50;   // the debounce time; increase if the output flickers
int buttonState;                        // the current reading from the input pin
int lastButtonState = LOW;              // the previous reading from the input pin

unsigned long tempoAnt;   // variavél para salvar o tempo da iteração anterior
unsigned long tempoAtual; // tempo da iteração atial
unsigned long periodo;    // comparação para o millis

int etapa = 1; // parte da execução que está

void setup()
{
    tempoAnt = millis();

    pinMode(vermelhoA, OUTPUT);
    pinMode(amareloA, OUTPUT);
    pinMode(verdeA, OUTPUT);
    pinMode(vermelhoB, OUTPUT);
    pinMode(amareloB, OUTPUT);
    pinMode(verdeB, OUTPUT);

    pinMode(botao, INPUT);

    // estados iniciais A
    digitalWrite(vermelhoA, LOW);
    digitalWrite(amareloA, LOW);
    digitalWrite(verdeA, HIGH);

    // estados iniciais B
    digitalWrite(vermelhoB, HIGH);
    digitalWrite(amareloB, LOW);
    digitalWrite(verdeB, LOW);

    // Debug
    Serial.begin(9600);
}

// função para esperar 10 segundos para o voltar o funcionamento normal
void espera()
{
    unsigned long int esp = millis();
    while (millis() - esp < 2 * verde)
    {
        int reading = digitalRead(botao);
        if (reading != lastButtonState)
        {
            // reset the debouncing timer
            lastDebounceTime = millis();
        }

        if ((millis() - lastDebounceTime) > debounceDelay)
        {
            // whatever the reading is at, it's been there for longer than the debounce
            // delay, so take it as the actual current state:

            // if the button state has changed:
            if (reading != buttonState)
            {
                buttonState = reading;

                // only toggle the LED if the new button state is HIGH
                if (buttonState == HIGH)
                {
                    counter++;
                    Serial.println(counter);
                }
            }
        }

        lastButtonState = reading;
    }
    //apertado = 0; // volta ao estado inicial
}

void loop()
{
    int reading = digitalRead(botao);
    if (reading != lastButtonState)
    {
        // reset the debouncing timer
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay)
    {
        // whatever the reading is at, it's been there for longer than the debounce
        // delay, so take it as the actual current state:

        // if the button state has changed:
        if (reading != buttonState)
        {
            buttonState = reading;

            // only toggle the LED if the new button state is HIGH
            if (buttonState == HIGH)
            {
                apertado = 1;
                counter++;
                Serial.println(counter);
            }
        }
    }
    lastButtonState = reading;

    tempoAtual = millis();
    periodo = tempoAtual - tempoAnt;
    // verifica se 10 segundos se passaram
    if (periodo > verde && etapa == 1)
    {
        if (apertado == 0)
        {
            // APAGA O VERDE E ACENDE O AMARELO
            digitalWrite(vermelhoA, LOW);
            digitalWrite(amareloA, HIGH);
            digitalWrite(verdeA, LOW);

            // FAROL B
            digitalWrite(vermelhoB, HIGH);
            digitalWrite(amareloB, LOW);
            digitalWrite(verdeB, LOW);
            etapa = 2;
        }
        else if (apertado == 1)
        {
            digitalWrite(vermelhoA, LOW);
            digitalWrite(amareloA, HIGH);
            digitalWrite(verdeA, LOW);

            // FAROL B
            digitalWrite(vermelhoB, HIGH);
            digitalWrite(amareloB, LOW);
            digitalWrite(verdeB, LOW);
            etapa = 2;
        }
    }
    // VERIFICA SE SE PASSARAM +5 SEGUNDOS
    if (periodo > verde + amarelo && etapa == 2)
    {
        if (apertado == 0)
        {
            // APAGA O AMARELO E ACENDE O VERMELHO
            // FAROL A
            digitalWrite(vermelhoA, HIGH);
            digitalWrite(amareloA, LOW);
            digitalWrite(verdeA, LOW);
            // APAGA O VERMELHO E ACENDE O VERDE
            // FAROL B
            digitalWrite(vermelhoB, LOW);
            digitalWrite(amareloB, LOW);
            digitalWrite(verdeB, HIGH);

            etapa = 3;
        }
        else if (apertado == 1)
        {
            digitalWrite(amareloA, LOW);
            digitalWrite(vermelhoA, HIGH);
            digitalWrite(verdeA, LOW);

            digitalWrite(vermelhoB, HIGH);
            digitalWrite(amareloB, LOW);
            digitalWrite(verdeB, LOW);
            espera();
            // APAGA O AMARELO E ACENDE O VERMELHO
            // FAROL A
            digitalWrite(vermelhoA, HIGH);
            digitalWrite(amareloA, LOW);
            digitalWrite(verdeA, LOW);
            // APAGA O VERMELHO E ACENDE O VERDE
            // FAROL B
            digitalWrite(vermelhoB, LOW);
            digitalWrite(amareloB, LOW);
            digitalWrite(verdeB, HIGH);
			espera();
          
          	apertado = 0;
          	verde = verde + 2000; //soma 20 segundos por conta das funções "espera"
            etapa = 3;
        }
    }

    // verifica se +10 segundos se passaram
    if (periodo > verde + amarelo + verde && etapa == 3)
    {
        // FAROL A
        digitalWrite(vermelhoA, HIGH);
        digitalWrite(amareloA, LOW);
        digitalWrite(verdeA, LOW);

        // APAGA O VERDE E ACENDE O AMARELO
        // FAROL B
        digitalWrite(vermelhoB, LOW);
        digitalWrite(amareloB, HIGH);
        digitalWrite(verdeB, LOW);

        etapa = 4;
    }
    // VERIFICA SE SE PASSARAM +5 SEGUNDOS
    if (periodo > 2 * verde + 2 * amarelo && etapa == 4)
    {
        if (apertado == 0)
        {
            // APAGA O VERMELHO E ACENDE O VERDE
            digitalWrite(vermelhoA, LOW);
            digitalWrite(verdeA, HIGH);
            digitalWrite(amareloA, LOW);
            // APAGA O AMARELO E ACENDE O VERMELHO
            digitalWrite(amareloB, LOW);
            digitalWrite(vermelhoB, HIGH);
            digitalWrite(verdeB, LOW);

            etapa = 1;
          	verde = verde - 2000; 
            tempoAnt = millis();
          	
        }
        else if (apertado == 1)
        {
            digitalWrite(verdeB, LOW);
            digitalWrite(vermelhoB, HIGH);
            digitalWrite(amareloB, LOW);

            digitalWrite(vermelhoA, HIGH);
            digitalWrite(verdeA, LOW);
            digitalWrite(amareloA, LOW);
            espera();
            // APAGA O VERMELHO E ACENDE O VERDE
            digitalWrite(vermelhoA, LOW);
            digitalWrite(verdeA, HIGH);
            digitalWrite(amareloA, LOW);
            // APAGA O AMARELO E ACENDE O VERMELHO
            digitalWrite(amareloB, LOW);
            digitalWrite(vermelhoB, HIGH);
            digitalWrite(verdeB, LOW);
          	apertado = 0;
            etapa = 1;
          	verde = verde - 2000; 
            tempoAnt = millis();
        }
    }
}
