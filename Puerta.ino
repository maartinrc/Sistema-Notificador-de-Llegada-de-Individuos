/*
  Instituto Tecnologico de Leon
  Jose Martin Ruiz Coss
  Sistemas Programables
*/

#include <avr/sleep.h>
int reed = 2;
boolean alarmaEncendida = false;
//asignamos pines
int led = 5;
int buzzer = 4;
void setup() {
  pinMode(reed, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(reed), prendeYSuena, RISING);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);

}

void loop() {
  if (!alarmaEncendida) {
    duerme();
  }
  if (digitalRead(reed) == HIGH) { //if que cuando entra, activa una bandera  y se desactiva el modo de bajo consumo
    sleep_disable();// Despertamos el arduino
    detachInterrupt(reed);// quitamos la interupcion del reed switch para que no se active varias veces
    alarmaEncendida = true;
  }

  if (alarmaEncendida) { // si la bandera se activa, entra a este if
    prendeYSuena(); // metodo que ejecuta el funcionamiento de la alarma con un led
  }

}

void prendeYSuena() {
  for (int contador = 0; contador <= 255; contador += 5) {
    analogWrite(led, contador);
    tone(buzzer, 252);
    delay(15);
  }

  for (int contador = 255; contador >= 0 ; contador -= 5) {
    analogWrite(led, contador);
    tone(buzzer, 128);
    delay(30);
  }

}

void duerme() {
  sleep_enable();
  sleep_mode();
}
