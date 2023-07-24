
/*
0. Stance recognition
1. Transformation matrix (alpha, a, d, theta)
    a. HW informaiton
        i. Twist
        ii. link lenght
        iii. link offset 
        iv. joint angle 
    : return 'n' Transformation matrices address array
        (n : # of links)

2. Chain rule -> w.r.t base frame 
    : return 'n' Transformation matrices address array
      w.r.t base Frame (n : # of links)  

3. calculate Centor of Mass 
    a. Chain rule data
    b. CoM of each link (x,y,z)
    c. mass of each link
    d. calculate CoM 
    return : CoM of total mass (x,y,z) 

4. calculate Base of Support 
*/

#pragma once
#include"exo_msgs.h"
#include<math.h>

void base_trans_matrices (double* dh_paramters);
void dh_parameter(TransArgs* args, double(*dh_mat)[4]);
void chain_rule(double(*mat1)[4],double(*mat2)[4]);
void matrix_mul(double(*mat1)[4],double(*mat2)[4],double(*result)[4]);
void print_matrix(double(*mat)[4]);
void transform_to_base(const double (*matrix)[4], double *vector);
void vector_scalar_multiple(const double scalar, double* vector);

