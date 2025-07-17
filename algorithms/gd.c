#include "gd.h"

static float mse(int real_y, int predicted_y) {
	return 1 << ((2 * (real_y - predicted_y)));
}

static float get_mse_partial_derivative(float parameters[], float features[][]`, float y[], bool bias, int samples)
{
	float sum = 0;
	if(bias){
		for(int i = 0; i < samples; i++) {
			sum += (parameters[0] + parameters[1] * features[i][0] - y[i]);
		}
	}
	else {
		for(int i = 0; i < samples; i++) {
			sum += (parameters[0] + parameters[1] * features[i][0] - y[i]) * features[i];
		}
	}

	return (2/(samples))*sum;
}


// size is the dimension of the features
float* gd(int** features, int real_y[], float learning_rate, int size, int samples) {

	float error = 1;

	float parameters[size + 1];

	// univariate linear regression (theta_0, theta_1)
	if(size < 2)
	{
		while(error < EPSILON) {

			// todo this can be parallelized
			for(int i = 0; i < (size + 1); i++) {
				// this update must be atomic
				parameters[i] = parameters[i] - learning_rate * get_mse_partial_derivative(parameters, features, real_y, ((i == 0) ? true : false), samples);
			}
		}
	}
	else {

	}

	return parameters;

}	