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
