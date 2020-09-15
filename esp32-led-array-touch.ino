/* Unidimensional LED array controller with touch 
 * @author: Gregorio Alvarez <allgrego14@gmail.com>
 * Last modification: 15/09/2020
 */


#define LED_0 26
#define LED_1 25
#define LED_2 33
#define LED_3 32

#include "functions.h"

/*for Interrupt using*/
int threshold = 30;
bool touchdetected = false;
void gotTouch(){
 touchdetected = true;
}


int current_state=0;
const int num_leds=4;
int ar_leds[num_leds]={LED_0,LED_1,LED_2,LED_3};

void setup()
{
  Serial.begin(115200);
  Serial.println("Inicializando Leds ...");
  initialize_leds(ar_leds,num_leds);//Inicializa todos los leds
  Serial.println("Iniciando Sistemas ...");
  delay(1000); // give me time to bring up serial monitor
  touchAttachInterrupt(T0,gotTouch, threshold);
  Serial.println("");
  Serial.println("ESTADO: 0");
}

void loop()
{
  //Primera revisión de touch
  if(touchdetected){
    current_state=next_state(current_state);
    mostrarEstadoActual(current_state);
    touchdetected = false;
  }
  
  //Se realiza la "ida" correspondiente al estado actual
  ida_controller(current_state,ar_leds,num_leds);

  //Segunda revisión de touch
  if(touchdetected){
    current_state=next_state(current_state);
    muestraEstadoActual(current_state);
    touchdetected = false;
  }
  
  //Se realiza el "retorno" correspondiente al estado actual
  retorno_controller(current_state,ar_leds,num_leds);
}
