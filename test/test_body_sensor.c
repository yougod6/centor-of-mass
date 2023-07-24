#include "body_sensor.h"
#include <stdio.h>
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

int main(){
    test_get_angles();
    return 0;
}
