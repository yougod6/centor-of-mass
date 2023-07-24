#include "body_sensor.h"
#include "dh_parameter.h"
#include "exo_msgs.h"
#include <stdio.h>
void test_matrix_mul(){
    double mat1[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    double mat2[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    double result[4][4] = {0,};
    printf("\n######## test matrix mul ########\n");
    printf("<mat1>\n");
    print_matrix(mat1);
    printf("<mat2>\n");
    print_matrix(mat2);

    matrix_mul(mat1,mat2,result);
    printf("<result>\n");
    print_matrix(result);
}

void test_chain_rule(){
    double mat1[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    double mat2[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    printf("\n######## test chain rule ########\n");
    printf("<mat1>\n");
    print_matrix(mat1);
    printf("<mat2>\n");
    print_matrix(mat2);

    chain_rule(mat1,mat2);
    printf("<result : mat1>\n");
    print_matrix(mat1);
    printf("<result : mat2>\n");
    print_matrix(mat2);
}

void test_dh_parameter(){
    TransArgs args1 = {0,0,0,(M_PI/180)*12.5};
    TransArgs args2 = {0,0,THIGH_LENGTH,(M_PI/180)*22.4};
    TransArgs args3 = {0,0,SHANK_LENGTH,(M_PI/180)* 4.4};
    double T01 [4][4] = {0,};
    double T12 [4][4] = {0,};
    double T23 [4][4] = {0,};
    dh_parameter(&args1,T01);
    dh_parameter(&args2,T12);
    dh_parameter(&args3,T23);
    printf("######## test_dh_paramter ########\n");
    printf("<T01>\n");
    print_matrix(T01);
    printf("<T12>\n");
    print_matrix(T12);
    printf("<T23>\n");
    print_matrix(T23);

    chain_rule(T01,T12);
    chain_rule(T12,T23);
    printf("######## after chain rule ########\n");
    printf("<T01>\n");
    print_matrix(T01);
    printf("<T02>\n");
    print_matrix(T12);
    printf("<T03>\n");
    print_matrix(T23);

}
int main(){
    //test_matrix_multiplication
    test_matrix_mul();

    //test_chain_rule 
    test_chain_rule();

    //test_dh_parameter
    test_dh_parameter(); 
    return 0;
}
