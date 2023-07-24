#include "forward_kinematics.h"
#include "exo_msgs.h"
#include "body_sensor.h"
#include <stdio.h>
int main(){
    BodyAngle bodyAngle;
    BodyAngle* pBodyAngle = &bodyAngle;
    get_angles(pBodyAngle);

    GaitPhase gait = TOE_OFF;
    if(gait==TOE_OFF){
        double result_arr[12];
        forward_kinematics(&gait,pBodyAngle,result_arr);
        for(int i=0; i<12; i++){
            printf("%f ", result_arr[i]);
            if ((i + 1) % 3 == 0){
                printf("\n");
            }
        }
    }

    else{
        double result_arr[9];
        forward_kinematics(&gait,pBodyAngle,result_arr);
        for(int i=0; i<9; i++){
            printf("%f ", result_arr[i]);
            if ((i + 1) % 3 == 0){
                printf("\n");
            }
        }
    }
    
    return 0;
}
