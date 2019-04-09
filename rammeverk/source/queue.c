#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "button_operations.h"
#include "controller.h"

int stop_dir(status* elevator){

	for(int flr = elevator->current_floor; flr < N_FLOORS; flr++ ){
		for(elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
		    if(elevator->queue[flr][button] !=0){

		        if(elevator->prev_floor<flr){

		            return DIRN_UP;
		        }
		        else if (elevator->prev_floor == flr){
		        	if(elevator->dir_before_stop == DIRN_UP){
		        		return DIRN_DOWN;
		        	}
		        	else if (elevator->dir_before_stop == DIRN_DOWN){
		        		return DIRN_UP;
		        	}
		        }
		        else {
		            return DIRN_DOWN;
		        }
		    }
		}
	}

	return 1;
}

elev_motor_direction_t determine_dir(status* elevator){

	int current_floor = elevator->current_floor;
	if(elevator->state == STANDBY && !(is_queue_empty(elevator))){


		if(elevator->current_floor == -1){
			return stop_dir(elevator);
		}

		if(current_floor == 3){
			return DIRN_DOWN;
	  	}

	  	else if(current_floor == 0){
	    	return DIRN_UP;
	  	}

		else if(elevator->prev_dir == DIRN_UP){
		    for(int flr = current_floor; flr < N_FLOORS; flr++ ){
		        for(elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
		            if(elevator->queue[flr][button] !=0){
		                return DIRN_UP;
		            }
		        }
		    }
		    return DIRN_DOWN;
		}

	 	else if(elevator->prev_dir == DIRN_DOWN){
		    for(int flr = current_floor; flr >= 0; flr-- ){
		        for (elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
		            if(elevator->queue[flr][button] !=0){
		            	return DIRN_DOWN;
		            }
		        }
		    }
			return DIRN_UP;
	  	}

  	}

  return DIRN_STOP;
}

void add_to_queue(status* elevator){

    for(int i = 0; i<N_FLOORS ;i++){
        for(elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
            if(!((button == BUTTON_CALL_UP && i == N_FLOORS-1) || ( button == BUTTON_CALL_DOWN && i == 0))){
                if(elevator->queue[i][button]!=1){
                    elevator->queue[i][button] = elev_get_button_signal(button,i);
                }
                 read_set_button_lights();
            }
        }
    }
}

bool is_queue_empty(status* elevator){

  	for (int flr = 0; flr < N_FLOORS; flr++){
    	for (int button = 0; button< 3; button++){
     		if (elevator ->queue[flr][button]==1){
        		return false;
    		}
    	}
  	}
  	return true;
}



void remove_current_floor_from_queue(status* elevator){

    for(elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND;button++){
        elevator->queue[elevator->current_floor][button] = 0;
        if(elevator->current_floor != -1){
        	reset_current_floor_light(elevator->current_floor);
        }
    }
}
