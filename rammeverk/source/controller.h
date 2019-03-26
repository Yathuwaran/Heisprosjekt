void stop_elevator();


struct controller {
  int queue[4][3] = {};
  elev_motor_direction_t dir;
  unsigned int current_floor;

}
