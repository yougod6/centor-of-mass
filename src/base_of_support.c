#include <math.h>
#include "body_sensor.h"
#include "base_of_support.h"
#include <stdio.h>
BOS calculate_bos(BodyAngle* pBodyAngle){
    get_angles(pBodyAngle);

    double left_leg_length = sqrt(pow(THIGH_LENGTH, 2) + pow(SHANK_LENGTH, 2) - 2 * THIGH_LENGTH * SHANK_LENGTH * cos(pBodyAngle->left_leg.knee));
	double right_leg_length = sqrt(pow(THIGH_LENGTH, 2) + pow(SHANK_LENGTH, 2) - 2 * THIGH_LENGTH * SHANK_LENGTH * cos(pBodyAngle->right_leg.knee));
    
    // printf("left_leg_length : %f \n",left_leg_length);
    // printf("right_leg_length : %f \n",right_leg_length);

	double left_leg_hip_angle = asin((SHANK_LENGTH / left_leg_length) * sin(pBodyAngle->left_leg.knee));
	double right_leg_hip_angle = asin((SHANK_LENGTH / right_leg_length) * sin(pBodyAngle->right_leg.knee));
	
    // printf("left_leg_hip_angle : %f \n",left_leg_hip_angle);
    // printf("right_leg_hip_angle : %f \n",right_leg_hip_angle);

    double left_leg_angle = fabs(pBodyAngle->left_leg.hip - left_leg_hip_angle);
	double right_leg_angle = fabs(pBodyAngle->right_leg.hip - right_leg_hip_angle);

    // printf("left_leg_angle : %f \n",left_leg_angle);
    // printf("right_leg_angle : %f \n",right_leg_angle);

	BOS bos;
    bos.left = left_leg_length * sin(left_leg_angle);
	bos.right = right_leg_length * sin(right_leg_angle);

    return bos;
}

// 어떤 frame을 기준으로 비교 ?
bool check_stability(const BOS* bos, const COM* com){
    return true;
}