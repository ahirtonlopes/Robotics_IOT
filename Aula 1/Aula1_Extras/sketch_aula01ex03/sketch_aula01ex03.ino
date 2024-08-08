//Aula 1 - FIAP - Atividade II Completa - Introdução a Robótica e IOT - Experimento sensor de ré (três faixas de sensoriamento)

int distanceThreshold = 0;

int cm = 0;

int inches = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); // "Limpando" o estado do pino trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Setando o pino para o estado HIGH por 10 microsegundos
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Lendo o pino echo e retornando o tempo percorrido pela onda em microsegundos
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  // definindo a distância limite para ativação dos leds
  distanceThreshold = 300;
  // mede o tempo do ping em cm
  cm = 0.01723 * readUltrasonicDistance(7, 6);
  // convertendo em polegadas dividindo por 2,5
  inches = (cm / 2.54);
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.print(inches);
  Serial.println("in");
  
  if (cm > distanceThreshold) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  if (cm <= distanceThreshold && cm > distanceThreshold - 100) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  if (cm <= distanceThreshold - 100 && cm > distanceThreshold - 250) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  if (cm <= distanceThreshold - 250 && cm > distanceThreshold - 300) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  if (cm <= distanceThreshold - 300) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(100); // Delay de 100 milisegundos
}
