#include controller.h
#include door.h
#include button_operations.h

void stop_elevator(){
        reset_all_lights_but_stop();
        elev_set_motor_direction(DIRN_STOP);
/*---------------------------------------------
        Delete queue here:
----------------------------------------------*/

}

struct controller {
  int queue[4][3] = {};
  elev_motor_direction_t dir;
  unsigned int current_floor;
  
}
