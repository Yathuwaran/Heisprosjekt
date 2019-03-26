#include queue.h


elev_motor_direction_t determine_dir(unsigned int floor){

}

elev_motor_direction_t stop_or_not(){
    if(elev_get_floor_sensor_signal()){
        return DIRN_STOP;
    }
}
//array floors x buttons opp,ned, etg
// func bestemmer retning for neste ordre
// stop or not
