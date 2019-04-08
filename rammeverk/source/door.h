/**
* @file
* @brief The door file includes functions for opening and closing the door. There is
* also implemented a three second time delay for holding the door open.
*/

#ifndef __INCLUDE_door_H__
#define __INCLUDE_door_H__
#include <stdbool.h>
#include "controller.h"

//Opens door, sleeps for 3 seconds and then closes the door again. Also toggles door lamp

/**
* @brief Opens the door and sets the door lamp. The door stays open for three seconds and then closes and resets door lamp.
* If an obstruction is detected, the timer resets.
* Stop button can be pressed inside fuction, which causes break.
* Orders can be added to queue.
*
* @param[out] status* elevator Struct for elevator status.

*/
void open_close_door(status* elevator);

//Checks time in seconds since 1970
void check_time(status* elevator);

#endif
