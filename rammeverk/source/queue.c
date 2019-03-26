#include queue.h
#include controller.h


elev_motor_direction_t determine_dir(controller* t){
  elev_motor_direction_t dir = controller->dir;
  unsigned int current_floor = controller->current_floor;
  if (current_floor == 4){

    dir = DIRN_DOWN;
  }
  if (current_floor = 1){
    dir = DIRN_UP;
  }


}
