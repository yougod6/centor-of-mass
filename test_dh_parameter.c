#include <stdio.h>
#include "com.h"
#include<math.h>
// // get Sensor Data , TBD 
// void get_angles(BodyAngle* pBodyAngle){
// 	pBodyAngle->left_leg.hip = 32.5;
// 	pBodyAngle->left_leg.knee = 32.4;
// 	pBodyAngle->left_leg.ankle = 32.4;

// 	pBodyAngle->right_leg.hip = 32.5;
// 	pBodyAngle->right_leg.knee = 32.4;
// 	pBodyAngle->right_leg.ankle = 32.4;
	
// 	pBodyAngle->back.roll = 4.3;
// }



// // // alpha, a, d, theta 
// // // let alpha = 0
// void dh_parameter(const double link_len, const double link_offset, const double joint_rad,double(*dh_mat)[4]){
//     dh_mat[0][0]=cos(joint_rad);
//     dh_mat[0][1]=-sin(joint_rad);
//     dh_mat[1][0]=sin(joint_rad);
//     dh_mat[1][1]=cos(joint_rad);
//     dh_mat[2][2]=1;
//     dh_mat[2][3]=link_offset;
//     dh_mat[3][3]=1; 
// }

//HW information
const double THIGH_LENGTH = 0.64;
const double SHANK_LENGTH = 0.35;
const double FOOT_LENGTH = 0.14;

int main(){
    BodyAngle bodyAngle;
    BodyAngle* pBodyAngle = &bodyAngle;
    get_angles(pBodyAngle);
    double dh_mat [4][4] = {0,};
    dh_parameter(THIGH_LENGTH,0,pBodyAngle->left_leg.hip,dh_mat);
    for (int row = 0; row < 4; row++) {
        for(int col = 0; col < 4; col++){
            printf("%f\t", dh_mat[row][col]);
        }
        printf("\n");
    }

    return 0;
}
