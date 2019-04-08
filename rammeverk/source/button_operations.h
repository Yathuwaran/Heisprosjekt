#ifndef __INCLUDE_button_operations_H__
#define __INCLUDE_button_operations_H__

//Reads buttons and lights up necessary buttons
void read_set_button_lights();

//Resets all of the lights, except the stop-light
void reset_all_lights_but_stop();

//Resets the light when the floor is reached
void reset_current_floor_light(int flr);

#endif
