#include "door.h"
#include <unistd.h>
#include "elev.h"
#include <time.h>
#include <stdbool.h>
#include <stdio.h>


void open_close_door() {
  elev_set_door_open_lamp(1);
  printf("%s", "Door open\n");
  
  check_time();
  while(elev_get_obstruction_signal()){
    printf("%s", "Obstruksjon\n");
  }
  elev_set_door_open_lamp(0);
printf("%s", "Door closed\n");
}

bool check_time(){
  time_t start_time;
  start_time = time(NULL);
  while(time(NULL) <= start_time +3){}
  return true;

}
