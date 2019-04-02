#include "elev.h"
#include <stdio.h>
#include "controller.h"
//#include <unistd.h>
//#include "queue.h"
#include "button_operations.h"



/*int main() {
    // Initialize hardware
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }

    printf("Press STOP button to stop elevator and exit program.\n");

    elev_set_motor_direction(DIRN_UP);

    while (1) {
        // Change direction when we reach top/bottom floor
        if (elev_get_floor_sensor_signal() == N_FLOORS - 1) {
            elev_set_motor_direction(DIRN_DOWN);s
        } else if (elev_get_floor_sensor_signal() == 0) {
            elev_set_motor_direction(DIRN_UP);
        }

        // Stop elevator and exit program if the stop button is pressed
        if (elev_get_stop_signal()) {
            elev_set_motor_direction(DIRN_STOP);
            break;
        }
    }

    return 0;
}*/

int main() {
    // Initialize hardware
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }


    struct status heis1;
    heis1.queue[0][0] = 0;
    while (1) {
      add_to_queue(&heis1);
      read_set_button_lights();
      for (int i = 0; i<4; i++){
        for (int j = 0; j<3; j++){
          printf("%d", heis1.queue[i][j]);
          printf("\t");
        }
        printf("\n");


      }
      //sleep(5);

      //printf("%B", is_queue_empty());
    }

    return 0;
}
