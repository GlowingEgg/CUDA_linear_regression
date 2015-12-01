#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse(int features, int examples, double **X, double *Y, char *filename){
	FILE* file = fopen(filename, "r");
	printf("Filename: %s\n", filename);
	printf("Features: %d\n", features);
	printf("Training examples: %d\n", examples);
	int lineLength = (5 * features) + 1;
	char *example = malloc(lineLength * sizeof(char)); 
	char *splitting = malloc(lineLength * sizeof(char));
	int exampleNumber = 0;
	int featureNumber;
	for(int i = 0; i < examples; i++){
		X[i][0] = 1.0;
	}
	while(fgets(example, lineLength, file)){
		splitting = strtok(example, ",");
		featureNumber = 1;
		while(splitting){
			fflush(stdout);
			if(featureNumber < features){
				X[exampleNumber][featureNumber] = atof(splitting);
			}
			else{
				Y[exampleNumber] = atof(splitting);
			}
			splitting = strtok(NULL, ",");
			featureNumber++;
		}
		exampleNumber++;
	}
	fclose(file);
}