#ifndef __INCLUDE_door_H__
#define __INCLUDE_door_H__
#include <stdbool.h>
#include "controller.h"
//Opens door, sleeps for 3 seconds and then closes the door again. Also toggles door lamp
void open_close_door(status* elevator);

//Checks timein seconds since 1970
bool check_time(status* elevator);

#endif
