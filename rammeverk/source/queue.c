#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "button_operations.h"
#include "controller.h"


elev_motor_direction_t determine_dir(status* elevator){
	elev_motor_direction_t dir = elevator->dir;
	unsigned int current_floor = elevator->current_floor;
	if(elevator->state == STANDBY && !(is_queue_empty(elevator))){
	  if (dir == DIRN_UP){
	    int move = 0;
	    while (move == 0){
	      for (int flr = current_floor+1; flr < N_FLOORS; flr++ ){
	        for (int button_type = 0; button_type<3; button_type++){
	            if (move !=1){
	                move =  elevator->queue[flr][button_type];
	            }
	        }
	      }
	    }
	    if (move == 0){
	        dir = DIRN_DOWN;
	    }
	}

	  else if (dir == DIRN_DOWN){
	    int move = 0;
	    while (move == 0){
	      for (int flr = current_floor-1; flr <= 0; flr-- ){
	        for (int button_type = 0; button_type< 3; button_type++){
	            if (move !=1){
	                move =  elevator->queue[flr][button_type];
	            }
	        }
	      }
	    }
	    if (move == 0){
	      dir = DIRN_UP;
	    }
	  }

	  if (current_floor == 3){

	    dir = DIRN_DOWN;
	  }
	  else if (current_floor == 0){
	    dir = DIRN_UP;
	  }

  }
  return dir;
}

void add_to_queue(status* elevator){

    for(int i = 0; i<N_FLOORS ;i++){
        for (elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
            if (!((button == BUTTON_CALL_UP && i == N_FLOORS-1) || ( button == BUTTON_CALL_DOWN && i == 0))){
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
        reset_this_floor_light(elevator->current_floor);
    }
}

void printq(status* elevator){
	for (int flr = 0; flr < N_FLOORS; flr++){
      for (elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
		  printf("%d",elevator->queue[flr][button]);
	  }
	  printf("\n");
  }
}


//array floors x buttons opp,ned, etg
// func bestemmer retning for neste ordre
// stop or not
