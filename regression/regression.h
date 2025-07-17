#ifndef REGRESSION_H
#define REGRESSION_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../dataset/dataset.h"
#include "../algorithms/gd.h"

float linear_regression(struct Data* data);

#endif