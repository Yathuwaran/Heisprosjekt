#include queue.h
#include controller.h
#include elev.h



elev_motor_direction_t determine_dir(status* t){
  elev_motor_direction_t dir = t->dir;
  unsigned int current_floor = t->current_floor;

  if (dir = DIRN_UP){
    int state = 0;
    while (state == 0){
      for (int floor = current_floor-1, floor < N_FLOORS-1, floor++ ){
        for (int bottun_type = 0, button_type<3, button_type++){
          state =  queue[floor][button_type];
        }
      }
    }
    if (state == 0){
      dir = DIRN_DOWN;
    }
  }
  else if (dir = DIRN_DOWN){
    int state = 0;
    while (state == 0){
      for (int floor = current_floor-1, floor < N_FLOORS-1, floor-- ){
        for (int bottun_type = 0, button_type<3, button_type++){
          state =  queue[floor][button_type];
        }
      }
    }
    if (state == 0){
      dir = DIRN_UP;
    }
  }

  if (current_floor == 4){

    dir = DIRN_DOWN;
  }
  else if (current_floor = 1){
    dir = DIRN_UP;
  }
  return dir;
}

bool is_queue_empty(){
  bool empty = true;
  for (int floor = 0, floor < N_FLOORS-1, floor++){
    for (int button_type = 0, button_type < 3, button_type++){
      if (queue[floor][button_type]==1){
        empty = false;
      }
    }
  }
  return empty;
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
