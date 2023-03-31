#include "com.h"
#define _USE_MATH_DEFINES

// get Sensor Data , TBD 
void get_angles(BodyAngle* pBodyAngle){
	pBodyAngle->left_leg.hip = (M_PI/180)*32.5;
	pBodyAngle->left_leg.knee = (M_PI/180)*32.4;
	pBodyAngle->left_leg.ankle =(M_PI/180)* 32.4;

	pBodyAngle->right_leg.hip = (M_PI/180)*32.5;
	pBodyAngle->right_leg.knee = (M_PI/180)*32.4;
	pBodyAngle->right_leg.ankle = (M_PI/180)*32.4;
	
	pBodyAngle->back.roll = (M_PI/180)*4.3;
}
// alpha, a, d, theta 
// let alpha = 0
void dh_parameter(const double link_len, const double link_offset, const double joint_rad,double(*dh_mat)[4]){
    dh_mat[0][0]=cos(joint_rad);
    dh_mat[0][1]=-sin(joint_rad);
    dh_mat[1][0]=sin(joint_rad);
    dh_mat[1][1]=cos(joint_rad);
    dh_mat[2][2]=1;
    dh_mat[2][3]=link_offset;
    dh_mat[3][3]=1; 
}

// double* dh_matrices(const Stance* stance,const BodyAngle* angle){
//     // if(stance==SWING){
//         double* T01 = (double*)malloc(sizeof(double)*16);
//         double* T12 = (double*)malloc(sizeof(double)*16);
//         double* T23 = (double*)malloc(sizeof(double)*16);
//         dh_parameter(0,0,angle->left_leg.hip,T01);
//         dh_parameter(0,0,angle->left_leg.hip,T12);
//         dh_parameter(0,0,angle->left_leg.hip,T23);
//         double* dh_matrices[3] = {T01,T12,T23};
//         return dh_matrices;
//     // }
//     // else if(stance==HEEL_STRIKE || stance==MID_STANCE){

//     // }
//     // //stace == TOE-OFF
//     // else{
        
//     // }
        
// }


