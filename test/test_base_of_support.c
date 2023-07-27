#include <stdio.h>
#include "base_of_support.h"

int main(){
    BodyAngle bodyAngle;
    BodyAngle* pBodyAngle = &bodyAngle;
    BOS bos = calculate_bos(pBodyAngle);
    
    printf("BOS (LEFT) : %f \n",bos.left);
    printf("BOS (RIGHT) : %f \n",bos.right);


    return 0;
}