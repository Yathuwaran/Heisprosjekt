#include "button_operations.h"
#include "elev.h"


void read_set_button_lights(){
  for (int flr = 0; flr< N_FLOORS; flr++ ){
    for (elev_button_type_t button = BUTTON_CALL_UP; button < 3; button++){
      if (elev_get_button_signal(button,flr)){
        elev_set_button_lamp(button, flr, 1);
      }
    }
  }
}

void reset_all_lights_but_stop(){
  for (int flr = 0; flr< N_FLOORS; flr++ ){
    for (elev_button_type_t button = BUTTON_CALL_UP; button < 3; button++){
      elev_set_button_lamp(button,flr,0);
    }
  }
}

void reset_this_floor_light( unsigned int flr){
  for (elev_button_type_t button = BUTTON_CALL_UP; button < 3; button++){
    elev_set_button_lamp(button,flr,0);
  }
}

//array floors x buttons opp,ned, etg
// func bestemmer retning for neste ordre
// stop or not
