#include "regression.h"

struct LModel* linear_regression(struct Data* data) {

	int size = get_features_count(data);

	printf("Total features: %d\n", size);

	int samples = get_samples(data);

	printf("Number of samples: %d\n", samples);

	int** features = get_features(data);

	int* labels = get_labels(data);

	print_dataset(data);

	struct LModel *model = malloc(sizeof(struct LModel));

	if(model == NULL) {
		fprintf(stderr, "Error allocating the linear model \n");
		return NULL;
	}


	// we will write the equation in the form
	// Y = X * \beta + \epsilon

	// for finding \beta we will use gradient descent

	float* parameters = NULL;

	if(size == 1) {
		parameters = gd(features, labels, 0.005, size, samples);
	}

	model->parameters = parameters;

	return model;
}

float predict(struct LModel* model, float x) {

	if(model == NULL) {
		fprintf(stderr, "Error reading the linear model \n");
		return -1;
	}

	return (float) model->parameters[0] + model->parameters[1] * x;

}