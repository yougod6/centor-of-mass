#include "dh_parameter.h"
#include "exo_msgs.h"
#include <stdio.h>
const double THIGH_MASS __attribute__((section("__DATA, .rom_data"))) = 3.1;
const double SHANK_MASS __attribute__((section("__DATA, .rom_data"))) = 1.4;
const double FOOT_MASS __attribute__((section("__DATA, .rom_data"))) = 0.6;


void transform_to_base(double (*matrix)[4], double *vector) {
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

void vector_scalar_multiple(double scalar, double* vector){
    for (int i = 0; i < 3; i++) {
        vector[i] = vector[i] * scalar;
    }
}


void calculate_COM(const Stance* stance,double(*dh[])[4],COM* com){
    if(*stance==SWING){
        double thigh_vector[4] = {0.6,0.23,0.0012,1};
        double shank_vector[4] = {0.31,0.12,0.001,1};
        double foot_vector[4] = {0.13,0.02,0.0003,1};
        transform_to_base(dh[0],thigh_vector);
        transform_to_base(dh[1],shank_vector);
        transform_to_base(dh[2],foot_vector);
        
        double com_vector[4]={0,0,0,1};
        double total_mass = THIGH_MASS + SHANK_MASS + FOOT_MASS;
        for(int i=0; i<3; i++){
            thigh_vector[i] *= THIGH_MASS;
            shank_vector[i] *= SHANK_MASS;
            foot_vector[i] *= FOOT_MASS;
            com_vector[i] = (thigh_vector[i] + shank_vector[i] + foot_vector[i])/(total_mass);
        }
        com->x = com_vector[0];
        com->y = com_vector[1];
        com->z = com_vector[2];
        return;
    }
    else return;
}

void check_COM(COM* com,double(*dh[])[4]){
    double thigh_vector[4] = {0.6,0.23,0.0012,1};
    double shank_vector[4] = {0.31,0.12,0.001,1};
    double foot_vector[4] = {0.13,0.02,0.0003,1};
    transform_to_base(dh[0],thigh_vector);
    transform_to_base(dh[1],shank_vector);
    transform_to_base(dh[2],foot_vector);
    double temp[4] = {0,0,0,1};
    double temp1[4] = {0,0,0,1};
    double temp2[4] = {0,0,0,1};
    
    temp[0]=(thigh_vector[0]-(com->x));
    temp[1]=(thigh_vector[1]-(com->y));
    temp[2]=(thigh_vector[2]-(com->z));
    vector_scalar_multiple(THIGH_MASS,temp);

    temp1[0]=(shank_vector[0]-(com->x));
    temp1[1]=(shank_vector[1]-(com->y));
    temp1[2]=(shank_vector[2]-(com->z));
    vector_scalar_multiple(SHANK_MASS,temp1);

    temp2[0]=(foot_vector[0]-(com->x));
    temp2[1]=(foot_vector[1]-(com->y));
    temp2[2]=(foot_vector[2]-(com->z));
    vector_scalar_multiple(FOOT_MASS,temp2);

    double result[4]={1,1,1,1};
    for(int i=0; i<3; i++){
        result[i] = temp[i]+temp1[i]+temp2[i];
    }

    printf("\ncheck centor of mass by definition : sum(m_i*r_i) = 0\n");
    for(int i=0; i<4; i++){
        printf("\t\t | %f |\n",result[i]);
    }
}