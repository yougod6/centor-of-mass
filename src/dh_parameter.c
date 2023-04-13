#include "dh_parameter.h"
#include<stdio.h>
#define _USE_MATH_DEFINES


// void base_trans_matrices (Bodydouble* dh_paramters){
//     // number of matrcies in dh_paramters array 
//     int iter = sizeof(dh_paramters)/sizeof(dh_paramters[0]);
//     for(int i=0; i<iter; i++){
//         chain_rule(dh_parameters[i],dh_parameters[i+1]);
//     }
// }



/**
 * Transformation Matrix from i-1 to i
 * @param TransArgs : alpha, a, d, theta
 * @param dh_mat : Address of Transformation matrix  (4x4)
*/
void dh_parameter(TransArgs* args,double(*dh_mat)[4]){
    
    dh_mat[0][0]=cos(args->joint_angle);
    dh_mat[0][1]=-sin(args->joint_angle);
    dh_mat[1][0]=sin(args->joint_angle);
    dh_mat[1][1]=cos(args->joint_angle);
    dh_mat[2][2]=1;
    dh_mat[2][3]=args->link_offset;
    dh_mat[3][3]=1; 
}

void test_dh_parameter(){
    //HW information
    const double THIGH_LENGTH = 0.64;
    const double SHANK_LENGTH = 0.35;

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

// n*n matrix muliplication function 
// args : two matrix address, result matrix address
void matrix_mul(double(*mat1)[4],double(*mat2)[4],double(*result)[4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                result[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
}

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
    printf("######## test matrix mul ########\n");
    printf("<mat1>\n");
    print_matrix(mat1);
    printf("<mat2>\n");
    print_matrix(mat2);

    matrix_mul(mat1,mat2,result);
    printf("<result>\n");
    print_matrix(result);
}


// 4x4 행렬의 곱을 구하는 함수
// 두 행렬의 주소(이름)를 인자로 받음
// 결과를 두번째 행렬에 저장
void chain_rule(double(*mat1)[4],double(*mat2)[4]){
    double temp[4][4] = {0,};
    matrix_mul(mat1,mat2,temp);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            mat2[i][j] = temp[i][j];
        }
    }
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
    printf("######## test chain rule ########\n");
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


/**
 * Print 4x4 matrix
 * @param mat : Address of matrix
*/
void print_matrix(double(*mat)[4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%f\t",mat[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------------------------------\n");
}
