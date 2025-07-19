#include "logistic.h"

float get_logistic_partial_derivative(float* parameters, int** features, int y[], bool bias, int num_samples) {

	float sum = 0;


	for(int i = 0; i < num_samples; i++) {
		sum += (SIGMOID(parameters[0] + parameters[1] * features[i][0]) - y[i]) * (bias == true ? 1 : features[i][0]);
	}

	return (1 / num_samples) * sum;

}

float log_logistic(float* parameters, int** features, int y[], int num_samples) {

	float sum = 0;

	for(int i = 0; i < num_samples; i++) {
		sum += (-log(SIGMOID(parameters[0] + parameters[1] * features[i][0]))) - log(1 - SIGMOID(parameters[0] + parameters[1] * features[i][0])) * (1 - y[i]);
	}

	return sum / num_samples;

}	