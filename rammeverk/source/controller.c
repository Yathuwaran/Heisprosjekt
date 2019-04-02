#include "controller.h"
#include "door.h"
#include "button_operations.h"
#include <stdlib.h>



void stop_elevator_button(struct status* elevator){
  reset_all_lights_but_stop();
  elev_set_motor_direction(DIRN_STOP);

  for (int flr = 0; flr < N_FLOORS; flr++){
    for (elev_button_type_t button = BUTTON_CALL_UP; button <= BUTTON_COMMAND; button++){
      elevator->queue[flr][button] = 0;
    }
  }
}

void stop_elevator(struct status* elevator){
  while (elev_get_stop_signal()==1){
    //stop_elevator_button(&elevator);
    elev_set_motor_direction(DIRN_STOP);
    elevator->dir = DIRN_STOP;
  }
}

void add_to_queue(struct status* elevator){

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
