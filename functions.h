/* Functions implementation for LedArrayInterrupt.ino
 * @author: Gregorio Alvarez <allgrego14@gmail.com>
 * @last-modification: 15/09/2020
 */


int next_state(int current_state){
  /*Retorna estado siguiente al actual
   * @params: INT estado actual
   * @return: INT siguiente estado
   */
  switch(current_state){
    case 0: return 1;
    case 1: return 2;
    case 2: return 3;
    case 3: return 0;
    default: return 0;
  }
}

void initialize_leds(int ar_leds[],int num_leds){
/* Inicializa los leds como OUTPUT y los prenda y apaga momentaneaménte
 * @params: INT ARRAY arreglo de leds, y INT número de leds en array (tamaño de array)
 * @return: none
 */
  for(int i=0;i<num_leds;i++){
    pinMode(ar_leds[i],OUTPUT);
    digitalWrite(ar_leds[i],HIGH);
    delay(10);
    digitalWrite(ar_leds[i],LOW);
    delay(90);
  }
}


/*
 ************** ESTADOS *********************
 */

/*
 * IDAS
 * Primera mitad de cada "viaje" de leds en cada estado que realiza durante cada loop
 */

void ida0(int ar_leds[],int num_leds){
  /* Ida de leds de estado 0 se enciende solo uno a la vez progresivamente
   * @params: arreglo de ints con números de GPIO correspondiente a los leds, y número de leds
   * @return: none
   */
  for(int i=0; i<num_leds; i++){
    for(int j=0; j<num_leds;j++){
      //apaga todos
      digitalWrite(ar_leds[j],LOW);
    }
   //enciende el indicado
   digitalWrite(ar_leds[i],HIGH);
  
  delay(250);
  }
}


void ida1(int ar_leds[],int num_leds){
  /* Ida de leds de estado 1 se encienden uno por uno progresivamente
   * @params: arreglo de ints con números de GPIO correspondiente a los leds, y número de leds
   * @return: none
   */
  //apaga todos
  for(int j=0; j<num_leds;j++){
      digitalWrite(ar_leds[j],LOW);
    }
  
  //enciende uno por uno
  for(int i=0; i<num_leds; i++){
   digitalWrite(ar_leds[i],HIGH);
  delay(250);
  }
}

void ida2(int ar_leds[],int num_leds){
  /* Ida de leds de estado 2 se encienden uno por uno progresivamente en una sola dirección
   * @params: arreglo de ints con números de GPIO correspondiente a los leds, y número de leds
   * @return: none
   */
  //apaga todos
  for(int j=0; j<num_leds;j++){
      digitalWrite(ar_leds[j],LOW);
    }
  
  //enciende uno por uno
  for(int i=num_leds-1; i>=0; i--){
   digitalWrite(ar_leds[i],HIGH);
  delay(250);
  }
}

void ida3(int ar_leds[],int num_leds){
  /* Ida de leds de estado 3 se apaga solo uno a la vez progresivamente
   * @params: arreglo de ints con números de GPIO correspondiente a los leds, y número de leds
   * @return: none
   */
  for(int i=0; i<num_leds; i++){
    for(int j=0; j<num_leds;j++){
      //Enciende todos
      digitalWrite(ar_leds[j],HIGH);
    }
   //Apaga el indicado
   digitalWrite(ar_leds[i],LOW);
  
  delay(250);
  }
}



/****Modos Handler Ida****/
void ida_controller(int current_state,int ar_leds[],int num_leds){
  switch(current_state){
    case 0: ida0(ar_leds,num_leds); return;
    case 1: ida1(ar_leds,num_leds); return;
    case 2: ida2(ar_leds,num_leds); return;
    case 3: ida3(ar_leds,num_leds); return;
    default: return;
  }
}


/*
 * RETORNOS 
 * Segunda mitad de cada "viaje" de leds en cada estado que realiza durante cada loop
 */

void retorno0(int ar_leds[],int num_leds){
  /* Retorno de leds de estado 0 se enciende solo uno a la vez progresivamente (Es igual a ida0)
   * @params: arreglo de ints con números de GPIO correspondiente a los leds, y número de leds
   * @return: none
   */
  for(int i=0; i<num_leds; i++){
    for(int j=0; j<num_leds;j++){
      //apaga todos
      digitalWrite(ar_leds[j],LOW);
    }
   //enciende el indicado
   digitalWrite(ar_leds[i],HIGH);
  
  delay(250);
  }    
}

void retorno1(int ar_leds[],int num_leds){
  /* Retorno de leds de estado 1 se apagan uno por uno progresivamente
   * @params: arreglo de ints con números de GPIO correspondiente a los leds, y número de leds
   * @return: none
   */
  //Enciende todos
  for(int j=0; j<num_leds;j++){
      digitalWrite(ar_leds[j],HIGH);
    }
  
  //Apaga uno por uno
  for(int i=num_leds-1; i>=0; i--){
   digitalWrite(ar_leds[i],LOW);
  delay(250);
  }
}

void retorno2(int ar_leds[],int num_leds){
  /* Retorno de leds de estado 2 se apagan uno por uno progresivamente en una sola dirección
   * @params: arreglo de ints con números de GPIO correspondiente a los leds, y número de leds
   * @return: none
   */
  //Enciende todos
  for(int j=0; j<num_leds;j++){
      digitalWrite(ar_leds[j],HIGH);
    }
  
  //Apaga uno por uno
  for(int i=num_leds-1; i>=0; i--){
   digitalWrite(ar_leds[i],LOW);
  delay(250);
  }
}

void retorno3(int ar_leds[],int num_leds){
  /* Retorno de leds de estado 3 se apaga solo uno a la vez progresivamente (igual a ida3)
   * @params: arreglo de ints con números de GPIO correspondiente a los leds, y número de leds
   * @return: none
   */
  for(int i=0; i<num_leds; i++){
    for(int j=0; j<num_leds;j++){
      //Enciende todos
      digitalWrite(ar_leds[j],HIGH);
    }
   //Apaga el indicado
   digitalWrite(ar_leds[i],LOW);
  
  delay(250);
  }
}


/****Modos Handler Retorno****/
void retorno_controller(int current_state,int ar_leds[],int num_leds){
  switch(current_state){
    case 0: retorno0(ar_leds,num_leds); return;
    case 1: retorno1(ar_leds,num_leds); return;
    case 2: retorno2(ar_leds,num_leds); return;
    case 3: retorno3(ar_leds,num_leds); return;
    default: return;
  }
}

void mostrarEstadoActual(int current_state){
  /*
   * Muestra en Serial ("pantalla") el estado actual luego de cada transición
   */
  Serial.print("Estado Actual: ");
  Serial.println(current_state);
   
}
