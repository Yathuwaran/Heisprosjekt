#include <stdlib.h>
#include "button_operations.h"
#include "elev.h"


void read_set_button_lights(){

	for (int flr = 0; flr< N_FLOORS; flr++ ){
		for (elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
  		if (!((button == BUTTON_CALL_UP && flr == N_FLOORS-1) || ( button == BUTTON_CALL_DOWN && flr == 0))){
    		if (elev_get_button_signal(button,flr)){
      		elev_set_button_lamp(button, flr, 1);
      	}
  		}
  	}
	}
}

void reset_all_lights_but_stop(){

	for (int flr = 0; flr< N_FLOORS; flr++ ){
  	for (elev_button_type_t button = BUTTON_CALL_UP; button <=BUTTON_COMMAND; button++){
    	if (!((button == BUTTON_CALL_UP && flr == N_FLOORS-1) || ( button == BUTTON_CALL_DOWN && flr == 0))){
      	elev_set_button_lamp(button,flr,0);
    	}
  	}
	}
}

void reset_current_floor_light(int flr){

	for (elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
  	if (!((button == BUTTON_CALL_UP && flr == N_FLOORS-1) || ( button == BUTTON_CALL_DOWN && flr == 0))){
			elev_set_button_lamp(button,flr,0);
		}
  }
}
