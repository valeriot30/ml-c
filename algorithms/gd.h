#ifndef GRADIENT_DESCENT_H
#define GRADIENT_DESCENT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "../functions/loss.h"
#include "../functions/logistic.h"

#define EPSILON 1e-3

#define EPOCHS 3000

float* gd(int** features, int real_y[], float learning_rate, int size, int samples, loss_type_t loss_type);

#endif