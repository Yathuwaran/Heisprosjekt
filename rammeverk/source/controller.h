
void stop_elevator();

//Stop function related to stop button
void stop_elevator_button();


struct controller {
  int queue[4][3] = {};
  elev_motor_direction_t dir;
  unsigned int current_floor;

}
