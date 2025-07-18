#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "../dataset/dataset.h"
#include "../algorithms/gd.h"
#include "../regression/regression.h"

struct LModel* classification(struct Data* data);

int classification_predict(struct LModel* model, float x);

#endif