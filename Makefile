CC = gcc
CFLAGS = -lm -Wall -Wextra -g
OBJ = regression/regression.o dataset/dataset.o algorithms/gd.o functions/logistic.o functions/loss.o classification/classification.o main.o

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o main