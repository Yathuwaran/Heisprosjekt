#include <stdlib.h>
#include "queue.h"
#include "button_operations.h"
#include "controller.h"


elev_motor_direction_t determine_dir(status* elevator){
  elev_motor_direction_t dir = elevator->dir;
  unsigned int current_floor = elevator->current_floor;

  if (dir == DIRN_UP){
    int state = 0;
    while (state == 0){
      for (int flr = current_floor; flr < N_FLOORS; flr++ ){
        for (int button_type = 0; button_type<3; button_type++){
            if (state !=1){
                state =  elevator->queue[flr][button_type];
            }
        }
      }
    }
    if (state == 0){
        dir = DIRN_DOWN;
    }
}

  else if (dir == DIRN_DOWN){
    int state = 0;
    while (state == 0){
      for (int flr = current_floor; flr <= 0; flr-- ){
        for (int button_type = 0; button_type< 3; button_type++){
            if (state !=1){
                state =  elevator->queue[flr][button_type];
            }
        }
      }
    }
    if (state == 0){
      dir = DIRN_UP;
    }
  }

  if (current_floor == 3){

    dir = DIRN_DOWN;
  }
  else if (current_floor == 0){
    dir = DIRN_UP;
  }
  return dir;
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

void stop_on_floor_if_ordered(status* elevator){
  if(elev_get_floor_sensor_signal() != -1){
    for(elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
      if(elevator->queue[elevator->current_floor][button] == 1){
        elevator->dir = DIRN_STOP;
        elev_set_motor_direction(DIRN_STOP);
      }
    }
  }
}

void reset_floor(status* elevator){
    for(elev_button_type_t button = BUTTON_CALL_UP; button<=BUTTON_COMMAND; button++){
      elevator->queue[elevator->current_floor][button] = 0;
    }
    reset_this_floor_light(elevator->current_floor);
}

void remove_current_floor_from_queue(status* elevator){
    for(elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND;button++){
        elevator->queue[elevator->current_floor][button] = 0;
        reset_this_floor_light(elevator->current_floor);
    }
}


//array floors x buttons opp,ned, etg
// func bestemmer retning for neste ordre
// stop or not
