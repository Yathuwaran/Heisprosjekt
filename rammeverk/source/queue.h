#ifndef __INCLUDE_queue_H__
#define __INCLUDE_queue_H__
#include "elev.h"
#include "controller.h"
#include <stdbool.h>

/*Checks and returns next direction for elevator based on queue matrix from
controller.h. The function does not consider if the elevator shold stop or not
*/
elev_motor_direction_t determine_dir(status* elevator);


/*Checks if the queue is empty and returns true "1", and false if the queue
is not empty*/
bool is_queue_empty(status* elevator);

//Ordinary stop function
void stop_on_floor_if_ordered(status* elevator);

/*Checks what floor elevator is on. Resets buttos, queue and lights
belonging to that floor*/
void reset_floor(status* elevator);

//Resets all button calls in queue
void remove_current_floor_from_queue(status* elevator){
#endif
