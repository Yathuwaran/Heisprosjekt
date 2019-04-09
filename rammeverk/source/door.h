/**
* @file
* @brief The door file includes functions for opening and closing the door. There is
* also implemented a three second time delay for holding the door open.
*/

#ifndef __INCLUDE_door_H__
#define __INCLUDE_door_H__
#include <stdbool.h>
#include "controller.h"

/**
* @brief Opens the door and sets the door lamp. The door stays open for three seconds and then closes and resets door lamp.
* Stop button can be pressed and orders can be added to queue even though obstruction is detected.
*
* @param[in,out] status* elevator Struct for elevator status.
*/
void open_close_door(status* elevator);

//Checks time in seconds since 1970

/**
* @brief The timer function checks if the current time is three seconds or more from the initial time.
* The current time is rested if an obstruction is detected.
* Stop button can be pressed and orders can be added to queue even when timer is running.
*
* @param[in,out] status* elevator Struct for elevator status.
*/
void check_time(status* elevator);

#endif
