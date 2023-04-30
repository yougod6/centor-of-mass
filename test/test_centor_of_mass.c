#include "centor_of_mass.h"
#include "body_sensor.h"
#include <stdio.h>
int main(){

    Stance stance = SWING;  
    
    BodyAngle bodyAngle;
    get_angles(&bodyAngle);
    
    //HW information
    const double THIGH_LENGTH = 0.64;
    const double SHANK_LENGTH = 0.35;

    TransArgs args1 = {0,0,0,bodyAngle.left_leg.hip};
    TransArgs args2 = {0,0,THIGH_LENGTH,bodyAngle.left_leg.knee};
    TransArgs args3 = {0,0,SHANK_LENGTH,bodyAngle.left_leg.ankle};
    double T01 [4][4] = {0,};
    double T02 [4][4] = {0,};
    double T03 [4][4] = {0,};

    dh_parameter(&args1,T01);
    dh_parameter(&args2,T02);
    dh_parameter(&args3,T03);

    chain_rule(T01,T02);
    chain_rule(T02,T03);

    double (*transformations[3])[4] = {T01, T02, T03};

    COM com;
    
    calculate_COM(&stance,transformations,&com);

    printf("centor-of-mass-x : %f\n",com.x);
    printf("centor-of-mass-y : %f\n",com.y);
    printf("centor-of-mass-z : %f\n",com.z);

    test_COM(&com,transformations);
    return 0;
}