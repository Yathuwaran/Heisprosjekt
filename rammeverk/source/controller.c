#include controller.h
#include door.h
#include button_operations.h

void stop_elevator_button(status* elevator){
  reset_all_lights_but_stop();
  elev_set_motor_direction(DIRN_STOP);

  for (int floor = 0, floor < N_FLOORS-1, floor++){
    for (int button_type = 0, button_type < 3, button_type++){
      t->queue[floor][button_type] = 0;
    }
  }
}

void stop_elevator(status* elevator){
  while (elev_get_stop_signal()==1){
    stop_elevator_button();
    elev_set_motor_direction(DIRN_STOP);
    elevator->dir = DIRN_STOP;
  }
}

void add_to_queue(status* elevator){
    for(int i = 0; i<N_FLOORS<i++){
      elevator->queue[i][BUTTON_CALL_UP] = elev_get_button_signal(BUTTON_CALL_UP,i);
      elevator->queue[i][BUTTON_CALL_DOWN] = elev_get_button_signal(BUTTON_CALL_DOWN,i);
      elevator->queue[i][BUTTON_COMMAND] = elev_get_button_signal(BUTTON_COMMAND,i);
    }
}
