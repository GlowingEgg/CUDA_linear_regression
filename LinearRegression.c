#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csvparse.c"

int main(int argc, char **argv){
	char* filename = argv[1];
	int features = atoi(argv[2]);
	int examples = atoi(argv[3]);
	int **X = malloc(examples * sizeof(int*));
	for(int i = 0; i < examples; i++){
		X[i] = malloc(features * sizeof(int));
	}
	X = parse(features, examples, X, filename);
	for(int i = 0; i < examples; i++){
		for(int j = 0; j< features; j++){
			printf("%d ", X[i][j]);
		}
		printf("\n");
	}
}