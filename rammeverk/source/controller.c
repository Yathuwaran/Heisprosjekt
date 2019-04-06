#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "controller.h"
#include "door.h"
#include "button_operations.h"



void reset_elevator(status* elevator){
  reset_all_lights_but_stop();
  elev_set_motor_direction(DIRN_STOP);
  for (int flr = 0; flr < N_FLOORS; flr++){
    for (elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
      elevator->queue[flr][button] = 0;
    }
  }
}

void stop_elevator(status* elevator){
  while (elev_get_stop_signal()==1){
    elevator->dir = DIRN_STOP;
    reset_elevator(elevator);

  }
}

void check_stop_state(status* elevator){
  if (elev_get_stop_signal()){
    elev_set_stop_lamp(1);
    elevator->state = STOP;
  }
}

void read_set_motor_dir(status* elevator){
  elevator->dir = determine_dir(elevator);
  elev_set_motor_direction(elevator->dir);
  if(elevator->dir != DIRN_STOP){
	  elevator->state = ACTION;
  }
}

void set_current_floor(status* elevator){
    elevator->current_floor = elev_get_floor_sensor_signal();
}

void stop_on_floor_if_ordered(status* elevator){
  if(elev_get_floor_sensor_signal() != -1){
    for(elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
      if(elevator->queue[elevator->current_floor][button] == 1){
        elev_set_motor_direction(DIRN_STOP);
		elevator->dir = DIRN_STOP;
      }
    }
  }
}

void reset_floor(status* elevator){
	int flr = elevator->current_floor;
    for(elev_button_type_t button = BUTTON_CALL_UP; button<=BUTTON_COMMAND; button++){
      elevator->queue[elevator->current_floor][button] = 0;
	  if (!((button == BUTTON_CALL_UP && flr == N_FLOORS-1) || ( button == BUTTON_CALL_DOWN && flr == 0))){
		 elev_set_button_lamp(button,flr,0);
   	  }
    }

}

void run_elevator(status* elevator){
	while(1){
		check_stop_state(elevator);
		add_to_queue(elevator);
		printf("%d",elevator->current_floor );

		switch (elevator->state) {
	    	case WAIT:
	      		printf("Wait\n");
		  		open_close_door(elevator);
		  		elevator->state = STANDBY;
	      	break;

	    	case STANDBY:
				printf("Standby\n");
				printq(elevator);
	        	read_set_motor_dir(elevator);
	        	 //sett inn i elevator->queue[0][0] = 0; 
	      	break;

	    	case STOP:
	      	printf("Stop\n");
	      	stop_elevator(elevator);
	      	elev_set_stop_lamp(0);
	      	elevator->state = STANDBY;
	      	break;

	    	case ACTION:
	      	printf("Action\n");
	      	while(elevator->dir != DIRN_STOP){
	          	add_to_queue(elevator);
			  	set_current_floor(elevator);
	          	stop_on_floor_if_ordered(elevator);

	      	}
	      	elevator->state = STANDBY ;
	      	break;
	  }
   }
}

void initialize_elevator(status* elevator){
  // Initialize hardware
  if (!elev_init()) {
      printf("Unable to initialize elevator hardware!\n");
  }

  elev_set_motor_direction(DIRN_DOWN);
  while(elev_get_floor_sensor_signal() != 0){ printf("t\n");}
  printf("out\n");
  //elev_set_motor_direction(DIRN_STOP);

  /*elevator->dir = DIRN_STOP;
  elevator->current_floor = 0;
  elevator->state = STANDBY;
  for (int flr = 0; flr < N_FLOORS; flr++){
    for (elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
		elevator->queue[flr][button]=0;
	}
  }

*/
}
