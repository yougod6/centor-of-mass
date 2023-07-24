#pragma once

#include "exo_msgs.h"
#include "dh_parameter.h"


COM calculate_COM(const GaitPhase* gait,double (*dh[])[4]);
void check_COM(COM* com,double(*dh[])[4]);