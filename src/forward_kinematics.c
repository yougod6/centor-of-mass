#include "forward_kinematics.h"


void forward_kinematics(GaitPhase* gait,BodyAngle* pBodyAngle, double* result){
    if(*gait==SWING){
        double thigh_vector[4] = {THIGH_LENGTH,0,0,1}; // P12
        double shank_vector[4] = {SHANK_LENGTH,0,0,1}; // P23
        double foot_vector[4] = {FOOT_LENGTH,0,0,1}; //P34
        TransArgs args1 = {0,0,0,pBodyAngle->left_leg.hip};
        TransArgs args2 = {0,THIGH_LENGTH,0,pBodyAngle->left_leg.knee};
        TransArgs args3 = {0,SHANK_LENGTH,0,(M_PI/2)-pBodyAngle->left_leg.ankle};

        double T01 [4][4] = {0,};
        double T12 [4][4] = {0,};
        double T23 [4][4] = {0,};
        dh_parameter(&args1,T01);
        dh_parameter(&args2,T12);
        dh_parameter(&args3,T23);
        transform_to_base(T01,thigh_vector); //P02
        double T02 [4][4] = {0,};
        matrix_mul(T01,T12,T02);
        transform_to_base(T02,shank_vector); //P03
        double T03 [4][4] = {0,};
        matrix_mul(T02,T23,T03);
        transform_to_base(T03,foot_vector); //P04

        for (int i = 0; i < 3; i++) {
            result[i] = thigh_vector[i];
            result[3 + i] = shank_vector[i];
            result[6 + i] = foot_vector[i];
        }
    }
    else if(*gait==HEEL_STRIKE || *gait==MID_STANCE){
        double shank_vector[4] = {SHANK_LENGTH,0,0,1}; // P12
        double thigh_vector[4] = {THIGH_LENGTH,0,0,1}; // P23
        double torso_vector[4] = {TORSO_LENGTH,0,0,1}; // P34

        TransArgs args1 = {0,0,0,pBodyAngle->left_leg.ankle};
        TransArgs args2 = {0,SHANK_LENGTH,0,pBodyAngle->left_leg.knee};
        TransArgs args3 = {0,THIGH_LENGTH,0,pBodyAngle->left_leg.hip};

        double T01 [4][4] = {0,};
        double T12 [4][4] = {0,};
        double T23 [4][4] = {0,};
        dh_parameter(&args1,T01);
        dh_parameter(&args2,T12);
        dh_parameter(&args3,T23);
        transform_to_base(T01,shank_vector); //P02
        double T02 [4][4] = {0,};
        matrix_mul(T01,T12,T02);
        transform_to_base(T02,thigh_vector); //P03
        double T03 [4][4] = {0,};
        matrix_mul(T02,T23,T03);
        transform_to_base(T03,torso_vector); //P04

        for (int i = 0; i < 3; i++) {
            result[i] = shank_vector[i];
            result[3 + i] = thigh_vector[i];
            result[6 + i] = torso_vector[i];
        }
    }
    //TOE-OFF
    else{
        double foot_vector[4] = {FOOT_LENGTH,0,0,1};    // P12 
        double shank_vector[4] = {SHANK_LENGTH,0,0,1};  // P23
        double thigh_vector[4] = {THIGH_LENGTH,0,0,1};  // P34
        double torso_vector[4] = {TORSO_LENGTH,0,0,1};  // P45

        TransArgs args1 = {0,0,0,0.610865}; //toe angle (35 deg)
        TransArgs args2 = {0,FOOT_LENGTH,0,pBodyAngle->left_leg.ankle};
        TransArgs args3 = {0,SHANK_LENGTH,0,pBodyAngle->left_leg.knee};
        TransArgs args4 = {0,THIGH_LENGTH,0,pBodyAngle->left_leg.hip};

        double T01 [4][4] = {0,};
        double T12 [4][4] = {0,};
        double T23 [4][4] = {0,};
        double T34 [4][4] = {0,};

        double T02 [4][4] = {0,};
        double T03 [4][4] = {0,};
        double T04 [4][4] = {0,};

        dh_parameter(&args1,T01);
        dh_parameter(&args2,T12);
        dh_parameter(&args3,T23);
        dh_parameter(&args4,T34);
        matrix_mul(T01,T12,T02);
        matrix_mul(T02,T23,T03);
        matrix_mul(T03,T34,T04);

        transform_to_base(T01,foot_vector);  //P02
        transform_to_base(T02,shank_vector); //P03
        transform_to_base(T03,thigh_vector); //P04
        transform_to_base(T04,torso_vector); //P05

        for (int i = 0; i < 3; i++) {
            result[i] = foot_vector[i];
            result[3 + i] = shank_vector[i];
            result[6 + i] = thigh_vector[i];
            result[9 + i] = torso_vector[i];
        }
    }
}