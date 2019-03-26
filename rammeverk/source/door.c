#include door.h
#include <unistd.h>

void open_door() {
  elev_set_door_open_lamp(1);
  sleep(3);
  elev_set_door_open_lamp(0);
}
