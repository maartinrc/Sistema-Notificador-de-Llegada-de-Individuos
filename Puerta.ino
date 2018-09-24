/*
Instituto Tecnologico de Leon
Jose Martin Ruiz Coss
Sistemas Programables
*/
/*int reed = 1;
boolean alarmaEncendida = false;*/
//asignamos pines
int led = 5;
int buzzer = 4;
void setup() {
//pinMode(reed,INPUT);
pinMode(led,OUTPUT);
pinMode(buzzer,OUTPUT);

}

void loop() {
noTone(buzzer);
//prendeYSuena(); // metodo que ejecuta el funcionamiento de la alarma con un led
}

void prendeYSuena(){
for(int contador = 0; contador <= 255; contador +=5){
    analogWrite(led, contador);
    tone(buzzer,252);
    delay(15);
  }
  
   for(int contador = 255; contador >=0 ; contador -=5){
    analogWrite(led, contador);
    tone(buzzer,128);
    delay(30);
  }
  
}
