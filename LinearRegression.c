#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include "csvparse.c"

double costFunction();
void meanNormalization();

int main(int argc, char **argv){
	char* filename = argv[1];
	/*This is the number of features provided on the command line*/
	/*The csv should contain values for each x value and the result, per example*/
	int features = atoi(argv[2]);
	int examples = atoi(argv[3]); /*Number of training examples provided*/
	double cost = DBL_MAX; /*Cost for the current hypothesis, set arbitratily high*/
	/*Values for the coefficients in the hypothesis function*/
	double *theta = malloc(features * sizeof(double));
	double **X = malloc(examples * sizeof(double*));
	for(int i = 0; i < examples; i++){
		X[i] = malloc(features * sizeof(double));
	}
	double *Y = malloc(examples * sizeof(double));
	parse(features, examples, X, Y, filename);
	for(int i = 0; i < features; i++){
		theta[i] = 0;
	}
	double **meanAndRange = malloc((features - 1) * sizeof(double*));
	for(int i = 0; i < features - 1; i++){
		meanAndRange[i] = malloc(2 * sizeof(double));
	}

	/*meanNormalization();         GOTTA MAKE THIS WORK NEXT!!!!!!*/

	/*****************************************************************************/
	/*This part will be inside the gradient descent function*/
	cost = costFunction(theta, X, Y, features, examples);
	printf("%f\n", cost);
	/*****************************************************************************/
}

double costFunction(int *theta, double **X, double *Y, int features, int examples){
	double cost;
	double runningSum;
	for(int i = 0; i< examples; i++){
		double xValue = 0;
		for(int j = 0; j < features; j++){
			xValue += X[i][j] * theta[j];
		}
		runningSum += pow(xValue - Y[i], 2);
	}
	cost = (.5 * examples) * runningSum;
	return cost;
}

void meanNormalization(double **X, double **Y, double **meanAndRange, int features, int examples){
	double min;
	double max;
	double mean;
	for(int i = 1; i < features; i++){
		min = X[0][i];
		max = X[0][i];
		mean = 0;
		for(int j = 0; j < examples; j++){
			if(X[j][i] > max){
				max = X[j][i];
			}
			if(X[i][j] < min){
				min = X[j][i];
			}
			mean += X[j][i];
		}
		mean /= features - 1;
		meanAndRange[i -1][0] = mean;
		meanAndRange[i - 1][1] = max - min;
	}
	for(int i = 0; i < examples; i++){
		for(int j = 1; j < features; j++){
			X[i][j] = (X[i][j] - meanAndRange[j - 1][0]) / meanAndRange[j - 1][1];
		}
	}
}
