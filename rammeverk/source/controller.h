#ifndef __INCLUDE_controller_H__
#define __INCLUDE_controller_H__
#include "elev.h"


typedef enum states_stat{
  STANDBY,
  WAIT,
  STOP,
  ACTION,
} states;

//Status on the elevator
typedef struct status_stat{
  int queue[4][3];
  elev_motor_direction_t dir;
  int current_floor;
  states state;
} status;



//Stop function related to stop button
void reset_elevator(status* elevator);

//Executes stop prosedure as long as stop button is pressed
void stop_elevator(status* elevator);

// Main program for running the elevator thourgh a switch
void run_elevator(status* elevator);

// Sets the motor direction using the determined diraction
void read_set_motor_dir(status* elevator);

//Checks if the the stop button is pressed
void check_stop_state(status* elevator);

void initialize_elevator(status* elevator);

void set_current_floor(status* elevator);

//Ordinary stop function
void stop_on_floor_if_ordered(status* elevator);

/*Checks what floor elevator is on. Resets buttos, queue and lights
belonging to that floor*/
void reset_floor(status* elevator);


#endif
