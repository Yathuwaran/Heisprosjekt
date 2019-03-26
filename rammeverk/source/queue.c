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

elev_motor_direction_t stop_or_not(status* elevator){
    if(elev_get_floor_sensor_signal() != -1){
      int floor = elevator->current_floor;
        for(int i = 0; i< 3; i++){
          if(elevator->queue[floor][i] == 1){
            return DIRN_STOP;
          }
      }
}
//array floors x buttons opp,ned, etg
// func bestemmer retning for neste ordre
// stop or not
