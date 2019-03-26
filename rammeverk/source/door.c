#include door.h
#include <unistd.h>

void open_close_door() {
  elev_set_door_open_lamp(1);
  sleep(3);
  while (elev_get_obstruction_signal(1)){
    sleep(3);
  }
  
  elev_set_door_open_lamp(0);

}
