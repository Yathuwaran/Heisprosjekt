
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "controller.h"
#include "door.h"
#include "button_operations.h"



void reset_elevator(status* elevator){

	reset_all_lights_but_stop();
	elev_set_stop_lamp(0);
	elevator->prev_stop = 1;
  	for (int flr = 0; flr < N_FLOORS; flr++){
    	for (elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
      		elevator->queue[flr][button] = 0;
    	}
  	}
}

void stop_elevator(status* elevator){

  	while (elev_get_stop_signal()==1){
	  	elev_set_stop_lamp(1);
	    elevator->dir = DIRN_STOP;
	    elev_set_motor_direction(DIRN_STOP);
	    reset_elevator(elevator);
	    elevator->state = STOP;
		if (elevator->current_floor != -1){
			open_close_door(elevator);
		}

  	}
}


void read_set_motor_dir(status* elevator){

  	elevator->dir = determine_dir(elevator);
  	if(elevator->dir != 0){
    	elevator->prev_dir = elevator->dir;
  	}
  	elev_set_motor_direction(elevator->dir);
  	if(elevator->dir != DIRN_STOP){
	  	elevator->state = ACTION;
  	}
}

void set_current_floor(status* elevator){

    elevator->current_floor = elev_get_floor_sensor_signal();
    if(elevator->current_floor != -1){
    	elevator->prev_floor = elevator->current_floor;
    }
}

void stop_on_floor_if_ordered(status* elevator){

  	if(elev_get_floor_sensor_signal() != -1){
    	for(elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
      		if(elevator->queue[elevator->current_floor][button] == 1){
        		elev_set_motor_direction(DIRN_STOP);
						elevator->dir = DIRN_STOP;
    				elevator->state = WAIT;
      		}
    	}
  	}
  	if(elevator->current_floor != -1){
  		elev_set_floor_indicator(elevator->current_floor);
  	}
}

void reset_floor(status* elevator){

	int flr = elevator->current_floor;
  	if (flr != -1){
    	for(elev_button_type_t button = BUTTON_CALL_UP; button<=BUTTON_COMMAND; button++){
      		elevator->queue[elevator->current_floor][button] = 0;
	  		if (!((button == BUTTON_CALL_UP && flr == N_FLOORS-1) || ( button == BUTTON_CALL_DOWN && flr == 0))){
		 	elev_set_button_lamp(button,flr,0);
   	  		}
    	}
  	}
}

void run_elevator(status* elevator){

	while(1){
    	add_to_queue(elevator);
		stop_elevator(elevator);
    	remove_current_floor_from_queue(elevator);

		switch (elevator->state) {
	    case WAIT:
	    	elevator->state = STANDBY;
	  		open_close_door(elevator);
     		break;

	   	case STANDBY:
	     	read_set_motor_dir(elevator);
	    	break;

	  	case STOP:
	     	elevator->state = STANDBY;
     		break;

	   	case ACTION:
	     	while(elevator->dir != DIRN_STOP){
	     			stop_elevator(elevator);
			  		set_current_floor(elevator);
	       		stop_on_floor_if_ordered(elevator);
          	reset_floor(elevator);
          	add_to_queue(elevator);
	     	}
	   		break;

	   	default:
	   		stop_elevator(elevator);
	   		break;
	  	}
  	}
}

void initialize_elevator(status* elevator){

  	if (!elev_init()) {
      printf("Unable to initialize elevator hardware!\n");
  	}

  	elev_set_motor_direction(DIRN_DOWN);
  	while(elev_get_floor_sensor_signal() != 0){}
  	elev_set_motor_direction(DIRN_STOP);

  	elevator->dir = DIRN_STOP;
  	elevator->prev_dir = DIRN_DOWN;
  	elevator->current_floor = 0;
  	elevator->state = STANDBY;
  	for (int flr = 0; flr < N_FLOORS; flr++){
    	for (elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
			elevator->queue[flr][button]=0;
	 	}
  	}
}
