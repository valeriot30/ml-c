
#include "regression/regression.h"

int main() {

	struct Data* data = create_from_file("./examples/regression.txt");

	struct LModel *model = linear_regression(data);	

	float predicted_y = predict(model, 2);

	printf("Predicted y is %f\n", predicted_y);
	
}
