#ifndef __INCLUDE_controller_H__
#define __INCLUDE_controller_H__
#include "elev.h"


typedef enum states_stat{
  IDLE_STATE
  STANDBY_STATE,
  WAIT_STATE,
  STOP_STATE,
  MOVE_STATE,
} states;

//Status on the elevator
typedef struct status_struct {
  int queue[4][3];
  elev_motor_direction_t dir;
  int current_floor;
} status;

void add_to_queue(status* elevator);
//Stop function related to stop button
void stop_elevator_button(status* elevator);

//Executes stop prosedure as long as stop button is pressed

void stop_elevator(status* elevator);
#endif
