#include "dh_parameter.h"
#include "exo_msgs.h"
#include <stdio.h>



/**
 * calculate Centor of Mass (without Upper-Body Robot)
 * @param stacne : detected gait phase
 * @param dh : array of T_i w.r.t base frame 
 * @return : Centor of Mass w.r.t base frame
*/
COM calculate_COM(const GaitPhase* gait,double(*dh[])[4]){
    COM com;
    if(*gait==SWING){
        double thigh_vector[4] = {0.6,0.23,0.0012,1}; // Thigh link CoM w.r.t frame 1
        double shank_vector[4] = {0.31,0.12,0.001,1}; // Shank link CoM w.r.t frame 2
        double foot_vector[4] = {0.13,0.02,0.0003,1}; // Foot link CoM w.r.t frame 3
        transform_to_base(dh[0],thigh_vector); // T01
        transform_to_base(dh[1],shank_vector); // T02
        transform_to_base(dh[2],foot_vector);  // T03
        
        double com_vector[4]={0,0,0,1};
        double total_mass = THIGH_MASS + SHANK_MASS + FOOT_MASS;
        for(int i=0; i<3; i++){
            thigh_vector[i] *= THIGH_MASS;
            shank_vector[i] *= SHANK_MASS;
            foot_vector[i] *= FOOT_MASS;
            com_vector[i] = (thigh_vector[i] + shank_vector[i] + foot_vector[i])/(total_mass);
        }
        com.x = com_vector[0];
        com.y = com_vector[1];
        com.z = com_vector[2];
    }
    else if(*gait == HEEL_STRIKE || *gait == MID_STANCE){
        double shank_vector[4] = {0.31,0.12,0.001,1}; // Shank link CoM w.r.t frame 1
        double thigh_vector[4] = {0.6,0.23,0.0012,1}; // Thigh link CoM w.r.t frame 2
        double torso_vector[4] = {0.41,0.18,0.05,1}; // Torso link CoM w.r.t frame 3

        transform_to_base(dh[0],shank_vector); // T01
        transform_to_base(dh[1],thigh_vector); // T02
        transform_to_base(dh[2],torso_vector);  // T03

        double com_vector[4]={0,0,0,1};
        double total_mass =  SHANK_MASS + THIGH_MASS + TORSO_MASS;
        for(int i=0; i<3; i++){
            shank_vector[i] *= SHANK_MASS;
            thigh_vector[i] *= THIGH_MASS;
            torso_vector[i] *= TORSO_MASS;
            com_vector[i] = (shank_vector[i] + thigh_vector[i] + torso_vector[i])/(total_mass);
        }
        com.x = com_vector[0];
        com.y = com_vector[1];
        com.z = com_vector[2];
    }
    // TOE_OFF 
    else{
        double foot_vector[4] = {0.13,0.02,0.0003,1}; // Foot link CoM w.r.t frame 3
        double shank_vector[4] = {0.31,0.12,0.001,1}; // Shank link CoM w.r.t frame 1
        double thigh_vector[4] = {0.6,0.23,0.0012,1}; // Thigh link CoM w.r.t frame 2
        double torso_vector[4] = {0.41,0.18,0.05,1}; // Torso link CoM w.r.t frame 3

        transform_to_base(dh[0],foot_vector);  // T01
        transform_to_base(dh[1],shank_vector); // T02
        transform_to_base(dh[2],thigh_vector); // T03
        transform_to_base(dh[3],torso_vector); // T04

        double com_vector[4]={0,0,0,1};
        double total_mass =  FOOT_MASS + SHANK_MASS + THIGH_MASS + TORSO_MASS;
        for(int i=0; i<3; i++){
            foot_vector[i] *= FOOT_MASS;
            shank_vector[i] *= SHANK_MASS;
            thigh_vector[i] *= THIGH_MASS;
            torso_vector[i] *= TORSO_MASS;
            com_vector[i] = (foot_vector[i] + shank_vector[i] + thigh_vector[i] + torso_vector[i])/(total_mass);
        }
        com.x = com_vector[0];
        com.y = com_vector[1];
        com.z = com_vector[2];
    }
    
    return com;
}


/**
 * check Centor of Mass is right
 * @param com : Centor of mass (return of calculate_COM function)
*/
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