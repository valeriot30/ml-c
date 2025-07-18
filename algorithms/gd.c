#include "gd.h"

// size is the dimension of the features
float* gd(int** features, int real_y[], float learning_rate, int size, int samples, loss_type_t loss_type){

	srand(time(NULL));

	float *parameters = malloc(sizeof(float) * (size + 1));

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
				if(loss_type == MSE)
					update[i] = parameters[i] - learning_rate * get_mse_partial_derivative(parameters, features, real_y, ((i == 0) ? true : false), samples);
				else
					update[i] = parameters[i] - learning_rate * get_logistic_partial_derivative(parameters, features, real_y, ((i == 0) ? true : false), samples);
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