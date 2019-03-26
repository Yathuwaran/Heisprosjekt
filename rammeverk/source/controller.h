
void stop_elevator();

//Stop function related to stop button
void stop_elevator_button();


//Status on the elevator
struct status {
  int queue[4][3] = {};
  elev_motor_direction_t dir;
  int current_floor = elev_get_floor_sensor_signal();
}

void add_to_queue(status* elevator){
    for(int i = 0; i<)N_FLOORS<i++){
      queue[i][BUTTON_CALL_UP] = elev_get_button_signal(BUTTON_CALL_UP,i);
      queue[i][BUTTON_CALL_DOWN] = elev_get_button_signal(BUTTON_CALL_DOWN,i);
      queue[i][BUTTON_COMMAND] = elev_get_button_signal(BUTTON_COMMAND,i);
    }
}
