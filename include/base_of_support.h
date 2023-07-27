#pragma once
#include "exo_msgs.h"
#include <stdbool.h>
BOS calculate_bos(BodyAngle* pBodyAngle);
bool check_stability(const BOS* bos, const COM* com);
