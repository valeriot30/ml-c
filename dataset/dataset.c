#include "dataset.h"

int get_features_count(struct Data* data) {
    return data->features_count;
}

int get_samples(struct Data* data) {
    return data->samples;
}

int** get_features(struct Data* data) {
    return data->features;
}

int* get_labels(struct Data* data) {
    return data->labels;
}

struct Data* create_from_file(char* filename) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return NULL;
    }

    struct Data* data = malloc(sizeof(struct Data));
    if (data == NULL) {
        fprintf(stderr, "Memory allocation for Data failed\n");
        fclose(fptr);
        return NULL;
    }

    size_t capacity = 10; // initial capacity for samples
    data->features = malloc(capacity * sizeof(int*));
    data->labels = malloc(capacity * sizeof(int));
    data->samples = 0;

    if (data->features == NULL || data->labels == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(data);
        fclose(fptr);
        return NULL;
    }

    char buffer[256];
    size_t feature_count = 0;

    while (fgets(buffer, sizeof(buffer), fptr)) {
        if (data->samples >= capacity) {
            capacity *= 2;
            data->features = realloc(data->features, capacity * sizeof(int*));
            data->labels = realloc(data->labels, capacity * sizeof(int));
            if (data->features == NULL || data->labels == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                fclose(fptr);
                free(data);
                return NULL;
            }
        }

        // Count how many integers in this line
        int temp_vals[100];
        int count = 0;
        char* token = strtok(buffer, " \t\n");
        while (token != NULL) {
            temp_vals[count++] = atoi(token);
            token = strtok(NULL, " \t\n");
        }

        if (count < 2) {
            fprintf(stderr, "Invalid line: %s", buffer);
            continue;
        }

        if (feature_count == 0) {
            feature_count = count - 1;
        }

        int* feature_row = malloc(feature_count * sizeof(int));
        for (int i = 0; i < feature_count; ++i) {
            feature_row[i] = temp_vals[i];
        }

        data->features_count = feature_count;

        data->features[data->samples] = feature_row;
        data->labels[data->samples] = temp_vals[feature_count];
        data->samples++;
    }

    fclose(fptr);
    return data;
}