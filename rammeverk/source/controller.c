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
