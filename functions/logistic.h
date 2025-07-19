#ifndef LOGISTIC_H
#define LOGISTIC_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIGMOID(x) (1.0f / (1.0f + expf(-(x))))

#define FAST_SIGMOID(x) (1.0f / (1.0f + abs((x))))

float get_logistic_partial_derivative(float* parameters, int** features, int y[], bool bias, int num_samples);

float log_logistic(float* parameters, int** features, int y[], int num_samples);

#endif