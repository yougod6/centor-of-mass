#include "body_sensor.h"
#include "dh_parameter.h"

//HW information
const double THIGH_LENGTH = 0.64;
const double SHANK_LENGTH = 0.35;

int main(){
    //test_matrix_multiplication
    test_matrix_mul();

    //test_chain_rule 
    test_chain_rule();

    //test_dh_parameter
    test_dh_parameter(); 
    return 0;
}
