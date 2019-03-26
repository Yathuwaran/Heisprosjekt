#include botton_operations.h
#include elev.h


void read_set_button_lights(){
  for (int floor = 0, floor< N_FLOORS, floor++ ){
    for (elev_button_type_t button = BUTTON_CALL_UP, button < 3, button++){
      if (elev_get_button_signal(button,floor)){
        elev_set_button_lamp(button, floor, 1);
      }
    }
  }
}

void reset_all_lights_but_stop(){
  for (int floor = 0, floor< N_FLOORS, floor++ ){
    for (elev_button_type_t button = BUTTON_CALL_UP, button < 3, button++){
      elev_set_button_lamp(button,floor,0))
    }
  }
}

void reset_this_floor_light( unsigned int floor){
  for (elev_button_type_t button = BUTTON_CALL_UP, button < 3, button++){
    elev_set_button_lamp(button,floor,0))
  }
}

//array floors x buttons opp,ned, etg
// func bestemmer retning for neste ordre
// stop or not 
