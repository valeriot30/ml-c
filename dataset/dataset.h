#ifndef DATASET_H
#define DATASET_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

struct Data {
	int** features; // shape n x m
	int* labels; // shape 1 x m

	int samples;
	int features_count; 
};

int get_features_count(struct Data* data);
struct Data* create_from_file(char* filename);
int* get_labels(struct Data* data);
int** get_features(struct Data* data);
int get_samples(struct Data* data);

#endif