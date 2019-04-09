/**
* @file
* @brief The queue file includes funtions used to manipulate the queue for the elevator, determine direction
* based on elements in queue and check if the queue is empty.
*/

#ifndef __INCLUDE_queue_H__
#define __INCLUDE_queue_H__
#include "elev.h"
#include "controller.h"
#include <stdbool.h>

/**
* @brief Determines the next direction for the elevator, given that the previous state was stop.
* The variables elevator-prev_dir and elevator->prev_floor from status* elevator are used to determine the direction
* based on the orders in the queue.
*
* @param[in] status* elevator Struct for elevator status.
*/
int stop_dir(status*elevator);

/**
* @brief Determines the next direction for the elevator. The previuos state is not taken into considerantion.
* The variable elevator->current_floor and elevator->prev_dir are used together with the stop_dir(status* elevator)
* funtion to determine the direction
*
* @param[in] status* elevator Struct for elevator status.
*/
elev_motor_direction_t determine_dir(status* elevator);

/**
* @brief Adds orders to the 4x3 matrix called queue in status* elevator.
* The orders are added by setting the value "1" in the array if an order button is pressed.
*
* @param[in,out] status* elevator Struct for elevator status.
*/
void add_to_queue(status* elevator);

/**
* @brief Goes through the 4x3 matrix and checks if every value is 0.
*
* @param[in] status* elevator Struct for elevator status.
* @return TRUE if the array is empty, FALSE if not empty
*/
bool is_queue_empty(status* elevator);

/**
* @brief Goes through the 4x3 matrix and removes every order on the current floor.
*
* @param[in,out] status* elevator Struct for elevator status.
*/
void remove_current_floor_from_queue(status* elevator);

#endif
