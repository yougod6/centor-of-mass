#define _USE_MATH_DEFINES

#include "com.h"

// get Sensor Data , TBD 
BodyAngle* get_angles(){
	BodyAngle angle;

	angle.left_leg.hip = 32.5;
	angle.left_leg.knee = 32.4;
	angle.left_leg.ankle = 32.4;

	angle.right_leg.hip = 32.5;
	angle.right_leg.knee = 32.4;
	angle.right_leg.ankle = 32.4;
	
	angle.back.roll = 4.3;

	BodyAngle *pBodyAngle = &angle;

	return pBodyAngle;
}


void transformation(const Stance* stance,const BodyAngle* angle){
    
    if(stance==SWING){

    }
    else if(stance==HEEL_STRIKE || stance==MID_STANCE){

    }
    //stace == TOE-OFF
    else{
        
    }
        
}

// compute Centor Of Mass 
void calculate_COM(double* pCOM){
    const double upper_mass;
    const double torso_mass;
    const double thigh_mass;
    const double shank_mass;

    //tranformation code
    

    //

}


void dh_parameter(Stance* stance, const BodyAngle* angle){
    if(stance==SWING){
        //create 
        
    }
    
}



double[4][4] dh(Stance* stance){
    const double l_i;
    const double d_i;
    const double q_i=angle->left_leg.hip;
    double dh[4][4] ={
        { cos(q_i), -sin(q_i), 0, 0},
        { sin(q_i), cos(q_i), 0, 0},
        { 0, 0, 1, d_i},
        {0, 0, 0, 1}
    };
    //배열의 주소 리턴
}


