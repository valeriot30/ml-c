
#include "regression/regression.h"
#include "classification/classification.h"

int main() {

	struct Data* data = create_from_file("./examples/classification.txt");

	struct LModel *model = classification(data);	

	float x = 2.0;

	float predicted_y = classification_predict(model, x);

	printf("Predicted class for x = %f is %f\n", x, predicted_y);
	
}
