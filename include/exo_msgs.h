#pragma once

//HW information
#define TORSO_LENGTH 0.71
#define THIGH_LENGTH 0.64
#define SHANK_LENGTH 0.35
#define FOOT_LENGTH 0.28

#define TORSO_MASS 32.8
#define THIGH_MASS 23.1
#define SHANK_MASS 11.4
#define FOOT_MASS 1.6

// extern const double TORSO_MASS __attribute__((section("__DATA, .rom_data"))) = 32.8;
// extern const double THIGH_MASS __attribute__((section("__DATA, .rom_data"))) = 23.1;
// extern const double SHANK_MASS __attribute__((section("__DATA, .rom_data"))) = 11.4;
// extern const double FOOT_MASS __attribute__((section("__DATA, .rom_data"))) = 1.6;

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
}GaitPhase;

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
}COM;

//bos data struct
typedef struct {
	double left;
	double right;
}BOS;