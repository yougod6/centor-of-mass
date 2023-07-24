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


/**
 * transform vector w.r.t base frame 
*/
void transform_to_base(const double (*matrix)[4], double *vector) {
    static double result[4];
    int i, j;

    for (i = 0; i < 4; i++) {
        result[i] = 0.0;
        for (j = 0; j < 4; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
    // Update the vector's value with the result
    for (i = 0; i < 4; i++) {
        vector[i] = result[i];
    }
}

/**
 * vector scalar multiplication
*/
void vector_scalar_multiple(const double scalar, double* vector){
    for (int i = 0; i < 3; i++) {
        vector[i] = vector[i] * scalar;
    }
}
