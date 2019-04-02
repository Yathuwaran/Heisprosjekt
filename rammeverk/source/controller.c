#include "controller.h"
#include "door.h"
#include "button_operations.h"
#include <stdlib.h>



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
    reset_elevator(&elevator);
    elevator->dir = DIRN_STOP;
  }
}

void add_to_queue(status* elevator){

    for(int i = 0; i<N_FLOORS ;i++){
        for (elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
            if (!((button == BUTTON_CALL_UP && i == N_FLOORS-1) || ( button == BUTTON_CALL_DOWN && i == 0))){
                if(elevator->queue[i][button]!=1){
                    elevator->queue[i][button] = elev_get_button_signal(button,i);
                }
            }
        }
    }
}

void check_stop_state(status* elevator){
  if (elev_get_stop_signal()){
    elevator->state = STOP;
  }
}

void read_set_motor_dir(status* elevator){
  elev_set_motor_direction(determine_dir(&elevator));
  elevator->dir = determine_dir(&elevator);
}


void run_elevator(status* elevator){
  switch (states) {
    case WAIT:
      open_close_door();
      check_stop_state(&elevator);
      elevator->state = STANDBY
      break;
    case STANDBY:
      determine_dir(&elevator);
      check_stop_state(&elevator);
      elevator->state = ACTION;
      break;
    case STOP:
      stop_elevator(&elevator)
      elevator->state = STANDBY;
      break;
    case ACTION:
      read_set_motor_dir(&elevator);
      check_stop_state(&elevator);
      elevator->state = WAIT;
      break;
  }
}

void initialize_elevator(status* elevator){
  
}
