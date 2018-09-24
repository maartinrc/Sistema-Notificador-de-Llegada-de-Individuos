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
int btn=3;
void setup() {

  pinMode(reed, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(btn,INPUT);
  attachInterrupt(digitalPinToInterrupt(reed), prendeYSuena, RISING);//interrupcion por hardware para encender la alarma
  attachInterrupt(digitalPinToInterrupt(btn), escucha, RISING);//interrupcion por hardware para apagar la alarma
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
void prendeYSuena() {//prende y apaga un LED. Suena buzzer
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

void duerme() {//encender ahorro de energia
  sleep_enable();
  sleep_mode();
}

void escucha(){//regresa interrupcion al reed switch y apaga la alarma
    if(digitalRead(btn) == HIGH){
        attachInterrupt(digitalPinToInterrupt(reed), prendeYSuena, RISING);
     alarmaEncendida = false;

    }
}
