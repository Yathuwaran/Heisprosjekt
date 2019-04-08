/**
* @file
* @brief Includes funtions for setting and resetting the button lamps on the elevator panel.
*/
#ifndef __INCLUDE_button_operations_H__
#define __INCLUDE_button_operations_H__

//Reads buttons and lights up necessary buttons

/**
* @brief Reads the button the button signals by going through the queue and sets the light
* if the value in the array is 1.
*/
void read_set_button_lights();

//Resets all of the lights, except the stop-light
/**
* @brief Goes through the queue and resets all of the button lights
* Only the stop button light is still set.
*/
void reset_all_lights_but_stop();

//Resets all of the lights, except the stop-light
/**
* @brief Goes through the queue and resets all of the button lights
* on the floor which is taken in as an argument in the function.
*
*@param[in] flr - The value of the relevant floor. 
*/
void reset_current_floor_light(int flr);

#endif
