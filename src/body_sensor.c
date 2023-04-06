#include"body_sensor.h"
#include<stdio.h>
#include<math.h>
#define _USE_MATH_DEFINES


void get_angles(BodyAngle* pBodyAngle){
	pBodyAngle->left_leg.hip = (M_PI/180)*12.5;
	pBodyAngle->left_leg.knee = (M_PI/180)*22.4;
	pBodyAngle->left_leg.ankle =(M_PI/180)* 4.4;

	pBodyAngle->right_leg.hip = (M_PI/180)*2.5;
	pBodyAngle->right_leg.knee = (M_PI/180)*2.4;
	pBodyAngle->right_leg.ankle = (M_PI/180)*3.4;
	
	pBodyAngle->back.roll = (M_PI/180)*4.3;
}

void test_get_angles(){
    BodyAngle bodyAngle;
    BodyAngle* pBodyAngle = &bodyAngle;
    get_angles(pBodyAngle);
    printf("left_leg.hip : %f \n",pBodyAngle->left_leg.hip);
    printf("left_leg.knee : %f \n",pBodyAngle->left_leg.knee);
    printf("left_leg.ankle : %f \n",pBodyAngle->left_leg.ankle);
    printf("right_leg.hip : %f \n",pBodyAngle->right_leg.hip);
    printf("right_leg.knee : %f \n",pBodyAngle->right_leg.knee);
    printf("right_leg.ankle : %f \n",pBodyAngle->right_leg.ankle);
    printf("back.roll : %f \n",pBodyAngle->back.roll);
}