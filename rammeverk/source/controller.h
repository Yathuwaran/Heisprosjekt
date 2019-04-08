/**
* @file
* @brief The controller file constists of two global structs for keeping track of the elevator
* status and the state of the elevator. Funtions for reseting, stopping, running, executing
* and initializing the elevator as well as functions for updtating the status and state are
* also included. The main logic of the elvator lies within the run_elevator() function.
*/

#ifndef __INCLUDE_controller_H__
#define __INCLUDE_controller_H__
#include "elev.h"


/**
 * @brief Holds all the states included within the state- machine
 */
typedef enum states_stat{
  STANDBY,    /**< The state where the motor direction is determined */
  WAIT,       /**< Here the door stays open for three seconds */
  STOP,       /**< Sets the state to STANDBY */
  ACTION,     /**< Looks for orders and act upon it. Upates queue and status */
} states;


/**
 * @brief Keeps track of the elevator status
 */
typedef struct status_stat{
  int queue[4][3];                          /**< A 4x3 matrix which to keep track of floor orders from the different types of buttons */
  elev_motor_direction_t dir;               /**< The current direction which is uptated regularly */
  elev_motor_direction_t prev_dir;           /**< Stores the previous direction different from the current direction */
  elev_motor_direction_t dir_before_stop;   /**< Used to determine direction when elevator stop button is pressed several times between floors*/
  int current_floor;                        /**< Stores the current floor, and is -1 when the elevator is between floors*/
  int prev_floor;                            /**< Stores current floor. Only updated when the elevatro passes or stops on a floor */
  int prev_stop;                            /**< Holds the last floor where the elevator stopped*/
  states state;                             /**< Keeps track on the state the elevator is in */
} status;



/**
* @brief Resets all elements in queue, and resets all enabled lamps.
* Updates prev_dir within status struct.
*
* @param[in, out] status* elevator Struct for elevator status.
*/
void reset_elevator(status* elevator);


/**
* @brief Sets and updates status of motor direction, resets the elevator and
* opens the door for three seconds if the elevator is not between floors.
* @param[in, out] status* elevator Struct for elevator status.
*/
void stop_elevator(status* elevator);

/**
* @brief Contains the complete state machine of the elevator.
* @param[in, out] status* elevator Struct for elevator status.
*/
void run_elevator(status* elevator);

/**
* @brief Determines a new direction based on the elevator orders and the elevator status.
* @param[in, out] status* elevator Struct for elevator status.
*/
void read_set_motor_dir(status* elevator);

/**
* @brief Initializes the the start state and status of the elvator.
* Forces the elevator to the first floor, and keeps the door closed.
* @param[in, out] status* elevator Struct for elevator status.
*/
void initialize_elevator(status* elevator);

/**
* @brief Sets current floor in the status struct based on floor sensor activity.
* @param[in, out] status* elevator Struct for elevator status.
*/
void set_current_floor(status* elevator);

/**
* @brief Makes the elevator stop, when it passes a floor with an avtive order.
* Updates status and state
* @param[in, out] status* elevator Struct for elevator status.
*/
void stop_on_floor_if_ordered(status* elevator);

/**
* @brief Resets lamps and orders assosiated with the floor where the elevator stops.
* @param[in, out] status* elevator Struct for elevator status.
*/
void reset_floor(status* elevator);





#endif
