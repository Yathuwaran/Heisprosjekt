
void stop_elevator();

//Stop function related to stop button
void stop_elevator_button();


//Status on the elevator
struct status {
  int queue[4][3] = {};
  elev_motor_direction_t dir;
  int current_floor = elev_get_floor_sensor_signal();

}
