// Atividade 1 - Aula 1 - DECLARACAO DE PINAGEM E LOOP ON/OFF DE LED ("BLINK")

//DECLARACAO DE VARIAVEIS

int LEDpin = 10;

void setup()
{

  pinMode(LEDpin, OUTPUT);
}

//LOOP ON/OFF DE NOSSO LED EXEMPLO

void loop()
{

  digitalWrite(LEDpin, HIGH);
  delay(200);
  digitalWrite(LEDpin, LOW);
  delay(200);
}
