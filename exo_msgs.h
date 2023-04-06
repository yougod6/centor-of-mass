#pragma once

/**
 * SWING = 0 
 * HEEL_STRIKE=1 
 * MID_STANCE=2 
 * TOE_OFF=3 
 **/
typedef enum{
    SWING, 
    HEEL_STRIKE,
    MID_STANCE,
    TOE_OFF
}Stance;

/**
 * Transformation Arguments of DH-parameter
 * twist : alpha
 * link_length : a
 * link_offset : d
 * joint_angle : theta
*/
typedef struct {
	double twist;
	double link_length;
    double link_offset;
    double joint_angle;
}TransArgs;

typedef struct {
	double hip;
	double knee;
    double ankle;
}Leg;

typedef struct {
	double roll;
}Back;

//sensor data struct
typedef struct {
	Leg left_leg;
	Leg right_leg;
	Back back;
}BodyAngle;

typedef struct {
    double x;
    double y;
    double z;
}CoM;

//bos data struct
typedef struct {
	double left;
	double right;
}BOS;