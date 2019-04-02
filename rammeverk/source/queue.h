#include "elev.h"
/*Checks and returns next direction for elevator based on queue matrix from
controller.h. The function does not consider if the elevator shold stop or not
*/
elev_motor_direction_t determine_dir(struct status* elevator);


/*Checks if the queue is empty and returns true "1", and false if the queue
is not empty*/
bool is_queue_empty();

//Ordinary stop function
elev_motor_direction_t stop_on_floor(struct status* elevator);
