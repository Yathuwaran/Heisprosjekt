
//Stop function related to stop button
void stop_elevator_button(status* elevator);

//Executes stop prosedure as long as stop button is pressed
void stop_elevator(status* elevator)

//Status on the elevator
struct status {
  int queue[4][3] = {};
  elev_motor_direction_t dir;
  int current_floor = elev_get_floor_sensor_signal();
}
