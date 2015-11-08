#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** parse(int features, int examples, int **X, char *filename){
	FILE* file = fopen(filename, "r");
	printf("Filename: %s\n", filename);
	printf("Features: %d\n", features);
	printf("Training examples: %d\n", examples);
	int lineLength = (2 * features) + 1;
	char *example = malloc(lineLength * sizeof(char)); 
	char *splitting = malloc(lineLength * sizeof(char));
	int exampleNumber = 0;
	int featureNumber;
	while(fgets(example, lineLength, file)){
		splitting = strtok(example, ",");
		featureNumber = 0;
		while(splitting){
			fflush(stdout);
			X[exampleNumber][featureNumber] = atoi(splitting);
			splitting = strtok(NULL, ",");
			featureNumber++;
		}
		exampleNumber++;
	}
	fclose(file);
	return X;
}