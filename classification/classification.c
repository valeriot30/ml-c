#include "classification.h"

struct LModel* classification(struct Data* data) {

	int size = get_features_count(data);

	printf("Total features: %d\n", size);

	int num_samples = get_samples(data);

	printf("Number of samples: %d\n", num_samples);

	int** features = get_features(data);

	int* labels = get_labels(data);

	print_dataset(data);

	struct LModel *model = malloc(sizeof(struct LModel));

	if(model == NULL) {
		fprintf(stderr, "Error allocating the linear model \n");
		return NULL;
	}

	float* parameters = NULL;

	if(size == 1) {
		parameters = gd(features, labels, 0.005, size, num_samples, LOG);
	}

	model->parameters = parameters;

	return model;
}

int classification_predict(struct LModel* model, float x) {

	if(model == NULL) {
		fprintf(stderr, "Error reading the linear model \n");
		return -1;
	}

	return SIGMOID(model->parameters[0] + model->parameters[1] * x) >= 0.5 ? 1 : 0;

}