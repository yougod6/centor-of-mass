#include"body_sensor.h"
#include<stdio.h>
#include<math.h>
#define _USE_MATH_DEFINES

//radians
void get_angles(BodyAngle* pBodyAngle){
	pBodyAngle->left_leg.hip = (M_PI/180)*12.5;
	pBodyAngle->left_leg.knee = (M_PI/180)*22.4;
	pBodyAngle->left_leg.ankle =(M_PI/180)* 4.4;

	pBodyAngle->right_leg.hip = (M_PI/180)*2.5;
	pBodyAngle->right_leg.knee = (M_PI/180)*2.4;
	pBodyAngle->right_leg.ankle = (M_PI/180)*3.4;
	
	pBodyAngle->back.roll = (M_PI/180)*4.3;
}

