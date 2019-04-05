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

void check_stop_state(status* elevator){
  if (elev_get_stop_signal()){
    elev_set_stop_lamp(1);
    elevator->state = STOP;

  }
}

void read_set_motor_dir(status* elevator){
  elev_motor_direction_t dir = determine_dir(elevator);
  elev_set_motor_direction(dir);
  elevator->dir = determine_dir(elevator);
}

void set_current_floor(status* elevator){
    elevator->current_floor = elev_get_floor_sensor_signal();
}


void run_elevator(status* elevator){
  switch (elevator->state) {
    case WAIT:
      printf("Wait\n");
      check_stop_state(elevator);
      remove_current_floor_from_queue(elevator);
      open_close_door(elevator);
      if(elevator->state != STOP){
          elevator->state = STANDBY;
      }

      break;
    case STANDBY:
        while(is_queue_empty(elevator)){
            printf("Standby\n");
            check_stop_state(elevator);
            add_to_queue(elevator);


        }
        check_stop_state(elevator);
        read_set_motor_dir(elevator);
        if(elevator->state != STOP){
            elevator->state = ACTION;
        }

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
          check_stop_state(elevator);
          add_to_queue(elevator);
          set_current_floor(elevator);
          stop_on_floor_if_ordered(elevator);
          check_stop_state(elevator);
      }
      check_stop_state(elevator);
      if(elevator->state != STOP){
          elevator->state = WAIT;
      }
      break;
  }
}

void initialize_elevator(status* elevator){
  // Initialize hardware
  if (!elev_init()) {
      printf("Unable to initialize elevator hardware!\n");
  }
  elevator->queue[0][0] = 0;
  reset_all_lights_but_stop();
  elev_set_stop_lamp(0);
  elev_set_motor_direction(DIRN_DOWN);
  while(elev_get_floor_sensor_signal() != 0){}
  elev_set_motor_direction(DIRN_STOP);
  elevator->dir = DIRN_STOP;
  elevator->current_floor = 0;
  elevator->state = STANDBY;


}
