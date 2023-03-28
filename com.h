#pragma once
#include <math.h>
#include <stdbool.h>

/**
 SWING = 0,
 HEEL_STRIKE=1,
 MID_STANCE=2,
 TOE_OFF=3
 **/
typedef enum{
    SWING, 
    HEEL_STRIKE,
    MID_STANCE,
    TOE_OFF
}Stance;

//sensor data struct
typedef struct {
	double hip;
	double knee;
    double ankle;
}Leg;

typedef struct {
	double roll;
}Back;

typedef struct {
	Leg left_leg;
	Leg right_leg;
	Back back;
}BodyAngle;

typedef struct {
    double x;
    double y;
    double z;
}LinkCOM;

//bos data struct
typedef struct {
	double left;
	double right;
}BOS;

// get Sensor Data , TBD 
BodyAngle* get_angles();

// compute Base Of Step
void calculate_BOS(BOS *pBOS);
	
// compute Centor Of Mass 
void calculate_COM(double* pCOM);

// check COM is stable , TBD
bool check_stability(BOS *pBOS, double* pCOM);

void transformation(transformated_position);

void dh_parameter(const BodyAngle* angle);
