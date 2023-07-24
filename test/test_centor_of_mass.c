#include "centor_of_mass.h"
#include "body_sensor.h"
#include <stdio.h>
int main(){

    GaitPhase gait = SWING;  
    printf("***** SWING Phase (Left) *****\n\n");
    BodyAngle bodyAngle;
    get_angles(&bodyAngle);
    
    
    printf("THIGH_LENGTH : %4.2f \n",THIGH_LENGTH);
    printf("SHANK_LENGTH : %4.2f \n",SHANK_LENGTH);
    printf("HIP ANGLE    : %4.2f deg\n",bodyAngle.left_leg.hip*(180/M_PI));
    printf("KNEE ANGLE   : %4.2f deg\n",bodyAngle.left_leg.knee*(180/M_PI));
    printf("ANKLE ANGLE  : %4.2f deg\n",bodyAngle.left_leg.ankle*(180/M_PI));

    TransArgs args1 = {0,0,0,bodyAngle.left_leg.hip};
    TransArgs args2 = {0,0,THIGH_LENGTH,bodyAngle.left_leg.knee};
    TransArgs args3 = {0,0,SHANK_LENGTH,bodyAngle.left_leg.ankle};
    double T01 [4][4] = {0,};
    double T12 [4][4] = {0,};
    double T23 [4][4] = {0,};

    double T02 [4][4] = {0,};
    double T03 [4][4] = {0,};

    dh_parameter(&args1,T01); // T01
    dh_parameter(&args2,T12); // T12
    dh_parameter(&args3,T23); // T23

    matrix_mul(T01,T12,T02);
    matrix_mul(T02,T23,T03);

    // chain_rule(T01,T02); // T01*T12 = T02
    // chain_rule(T02,T03); // T02*T23 = T03
    printf("\n#### T01 ####\n");
    print_matrix(T01);
    printf("\n#### T02 ####\n");
    print_matrix(T02);
    printf("\n#### T03 ####\n");
    print_matrix(T03);
    double (*transformations[3])[4] = {T01, T02, T03};

    COM com = calculate_COM(&gait,transformations);

    printf("centor-of-mass-x : %f\n",com.x);
    printf("centor-of-mass-y : %f\n",com.y);
    printf("centor-of-mass-z : %f\n",com.z);

    check_COM(&com,transformations);
    return 0;
}