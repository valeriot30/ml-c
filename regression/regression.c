#include "regression.h"

float linear_regression(struct Data* data) {

	int size = get_features_count(data);

	int samples = get_samples(data);

	int** features = get_features(data);

	int* labels = get_labels(data);

	if(size == 1) {
		float parameters[] = gd(features, labels, 0.1, size, samples);

		for(int i = 0; i < (size + 1); i++) {
			printf("%f", parameters[i]);
		}
	}

	// we will write the equation in the form
	// Y = X * \beta + \epsilon

	// for finding \beta we will use gradient descent

	return 0;
}