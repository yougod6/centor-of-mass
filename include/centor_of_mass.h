#include "exo_msgs.h"
#include "dh_parameter.h"

void transform_to_base(double (*matrix)[4], double *vector);
void vector_scalar_multiple(double scalar, double* vector);
void calculate_COM(const Stance* stance,double (*dh[])[4],COM* com);
void check_COM(COM* com,double(*dh[])[4]);