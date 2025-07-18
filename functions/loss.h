#ifndef LOSS_H
#define LOSS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float get_mse_partial_derivative(float* parameters, int** features, int y[], bool bias, int num_samples);

float mse(float theta_0, float theta_1, int** features, int y[], int samples);

#endif