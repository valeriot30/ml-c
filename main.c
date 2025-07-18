
#include "regression/regression.h"

int main() {

	struct Data* data = create_from_file("./examples/regression.txt");

	struct LModel *model = linear_regression(data);	

	float x = 2.0;

	float predicted_y = predict(model, x);

	printf("Predicted y for x = %f is %f\n", x, predicted_y);
	
}
