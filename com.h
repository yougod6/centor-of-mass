#pragma once
#include<math.h>

/*
0. Stance recognition
1. Transformation matrix (alpha, a, d, theta)
    a. HW informaiton
        i. Twist
        ii. link lenght
        iii. link offset 
        iv. joint angle 
    : return 'n' Transformation matrices address array
        (n : # of links)

2. Chain rule -> w.r.t base frame 
    : return 'n' Transformation matrices address array
      w.r.t base Frame (n : # of links)  

3. calculate Centor of Mass 
    a. Chain rule data
    b. CoM of each link (x,y,z)
    c. mass of each link
    d. calculate CoM 
    return : CoM of total mass (x,y,z) 

4. calculate Base of Support 
*/




/**
 * for the STANCE, DOF and BASE_FRAME is changed
 * 1. DOF -> change # of transformation matrix 
 * 2. BASE_FRAME -> change direction of transformation  
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
}CoM;

//bos data struct
typedef struct {
	double left;
	double right;
}BOS;

void get_angles(BodyAngle* pBodyAngle);

void dh_parameter(const double link_len, const double link_offset, const double joint_rad,double(*dh_mat)[4]);

// double* dh_matrices(const Stance* stance,const BodyAngle* angle);

