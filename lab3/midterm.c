#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
int printm(double **matrix, int size);
int isDiag(double **matrix, int size);

void scanFile(double ** matrix, int rows, FILE *file){
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < rows +1; j++) 
	    fscanf(file, "%lf", &matrix[i][j]);
}
int isDiag(double **matrix, int size){
	for(int r = 0; r < size; r++){
		int rowMax = 0;
		for(int c = 0; c < size; c++){
			rowMax = fmax(rowMax, matrix[r][c]);	
		}
		if(rowMax > matrix[r][r]) return 1;
		rowMax = 0;
	}
	return 0;
}
	
int printm(double **matrix, int size) {
    if (matrix == NULL) {
	fprintf(stderr, "Bad Matrix pointer in print");
        return 1; // matrix pointer is null
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= size; j++) {
            printf("\t%5.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

int main(int argc, char ** argv) {
    int n;
    FILE* in; 
    char method[2];
    if(argc > 1){
	printf("Scanning from file %4s\n", argv[1]);
	in = fopen(argv[1], "r");
	method[0] = 'f';
	fscanf(in,"%d\n", &n);
    }else{
        fprintf(stderr, "Usage: ./midterm filename\n");
	exit(1);
    }
    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc((n+1) * sizeof(double));
    }
    
    scanFile(matrix, n, in);

    printf("matrix stored\n");
    printm(matrix, n);
    printf("isDiag: %s\n", (isDiag(matrix, n) == 1) ? "False": "True");
    // free memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
