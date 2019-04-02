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
elev_motor_direction_t stop_on_floor(status* elevator);
