/*******************************************************************************
* calibrate_gyro.c
* James Strawson - 2016
*
* This program exists as an interface to the calibrate_gyro_routine which
* manages collecting gyroscope data for averaging to find the steady state
* offsets.
*******************************************************************************/

#include <bb_blue_api.h>

int main(){
	if(initialize_board()<0){
		printf("Failed to initialize cape, exiting\n");
		return -1;
	}
	
	printf("\nThis program will generate a new gyro calibration file\n");
	printf("keep your beaglebone very still for this procedure.\n");
	printf("Press ENTER to continue or anything else to quit\n");
	if(continue_or_quit()<0){
		cleanup_board();
		return -1;
	}
	
	printf("Starting calibration routine\n");
	if(calibrate_gyro_routine()<0){
		printf("Failed to complete gyro calibration\n");
		return -1;
	}
	
	printf("\ngyro calibration file written\n");
	printf("run test_imu to check performance\n");
		
	cleanup_board();
	return 0;
}
