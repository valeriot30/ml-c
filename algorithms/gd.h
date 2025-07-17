#ifndef GRADIENT_DESCENT_H
#define GRADIENT_DESCENT_H

#include <stdbool.h>

#define EPSILON 1e-7

float* gd(int** features, int real_y[], float learning_rate, int size, int samples);

#endif