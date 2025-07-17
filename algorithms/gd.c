#include "gd.h"

static float mse(int real_y, int predicted_y) {
	return 1 << ((2 * (real_y - predicted_y)));
}

static float get_mse_partial_derivative(float* parameters, int** features, int y[], bool bias, int samples)
{
	float sum = 0;
	if(bias){
		for(int i = 0; i < samples; i++) {
			sum += pow((parameters[0] + parameters[1] * features[i][0] - y[i]), 2);
		}
	}
	else {
		for(int i = 0; i < samples; i++) {
			sum += pow((parameters[0] + parameters[1] * features[i][0] - y[i]) * features[i][0], 2);
		}
	}

	return (2/(samples))*sum;
}

float cost(float theta_0, float theta_1, int** features, int y[], int samples) {

	float sum = 0;

	for(int i = 0; i < samples; i++) {
		sum += (theta_0 + theta_1 * features[i][0] - y[i]);
	}

	return sum / samples;
}


// size is the dimension of the features
float* gd(int** features, int real_y[], float learning_rate, int size, int samples) {

	srand(time(NULL));

	float parameters[size + 1];

	for(int i = 0; i < (size + 1); i++) {
		// select a random point in the space
		parameters[i] = (rand() / ((double) RAND_MAX  + 1));
	}

	int n_epochs = 0;

	// univariate linear regression (theta_0, theta_1)
	if(size < 2)
	{
		while(n_epochs < EPOCHS) {

			float update[(size + 1)];

			update[0] = 0;
			update[1] = 0;

			// todo this can be parallelized
			for(int i = 0; i < (size + 1); i++) {
				// this update must be atomic
				update[i] = parameters[i] - learning_rate * get_mse_partial_derivative(parameters, features, real_y, ((i == 0) ? true : false), samples);
			}

			for(int i = 0; i < (size + 1); i++) {
				parameters[i] = update[i];

				//printf("%f\n", parameters[i]);
			}

			n_epochs++;
		}
	}

	return parameters;

}	