#include "elev.h"


//Status on the elevator
struct status {
  int queue[4][3];
  elev_motor_direction_t dir;
  int current_floor;
};

void add_to_queue(struct status* elevator);
//Stop function related to stop button
void stop_elevator_button(struct status* elevator);

//Executes stop prosedure as long as stop button is pressed

void stop_elevator(struct status* elevator);
