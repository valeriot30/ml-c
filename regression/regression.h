#ifndef REGRESSION_H
#define REGRESSION_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "../dataset/dataset.h"
#include "../algorithms/gd.h"

struct LModel {
	float *parameters;
};

struct LModel* linear_regression(struct Data* data);

float predict(struct LModel* model, float x);

#endif