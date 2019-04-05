#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "door.h"
#include "elev.h"
#include "controller.h"
#include "queue.h"



void open_close_door(status* elevator) {
  elev_set_door_open_lamp(1);
  printf("%s", "Door open\n");

  check_time(elevator);
  while(elev_get_obstruction_signal()){
    printf("%s", "Obstruksjon\n");
  }
  elev_set_door_open_lamp(0);
printf("%s", "Door closed\n");
}

bool check_time(status* elevator){
  time_t start_time;
  start_time = time(NULL);
  while(time(NULL) <= start_time +3){
      add_to_queue(elevator);
      check_stop_state(elevator);
  }
  return true;

}
