#include "loss.h"

float get_mse_partial_derivative(float* parameters, int** features, int y[], bool bias, int samples)
{
	float sum = 0;
	if(bias){
		for(int i = 0; i < samples; i++) {
			sum += (parameters[0] + parameters[1] * features[i][0] - y[i]);
		}
	}
	else {
		for(int i = 0; i < samples; i++) {
			sum += (parameters[0] + parameters[1] * features[i][0] - y[i]) * features[i][0];
		}
	}

	return (2.0f /(samples))*sum;
}

float mse(float theta_0, float theta_1, int** features, int y[], int samples) {

	float sum = 0;

	for(int i = 0; i < samples; i++) {
		sum += pow((theta_0 + theta_1 * features[i][0] - y[i]), 2);
	}

	return sum / samples;
}