#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
int printm(double **matrix, int size);

int scanSystem(double **matrix, int rows) {
    int cols = rows + 1; // one more column than row
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j < i) {
                matrix[i][j] = 0.0;
            } else if (j == cols-1) {
                printf("Enter coefficient of y%d: ", i+1);
                scanf("%lf", &matrix[i][j]);
            } else {
                printf("Enter coefficient of x%d: ", j);
                scanf("%lf", &matrix[i][j]);
            }
        }
    }
    return 0;
}

int scanMatrix(double **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n+1 ; j++) {
            double value;
            printf("Enter value for matrix[%d][%d]: ", i, j);
            scanf("%lf", &value);
            matrix[i][j] = value;
        }
    }
    return 0;
}
int rowSwp(double * row, double * target){
    double * temp = row;
    row = target;
    target = temp;
    return 1;
}	
int rowAdd(double * row, int cols, double * addend, double scale){
    if(row == NULL) fprintf(stderr, "bad row pointer\n");
    for(int c = 0; c < cols; c++) row[c] += scale * addend[c];
    return 0;
}
int rowScl(double * row, int cols, double scale){
    if(row == NULL) fprintf(stderr, "bad row pointer\n");
    for(int c = 0; c < cols; c++) row[c] *= scale;
    return 0;
}
void makeTriangle(double * matrix[], int rows) {
    int cols = rows + 1;
    //get to upper triangle
    for(int r = 0; r < rows; r ++){
        if(matrix[r][r] == 0)
	    for(int i = 1; i < rows; i++)
	        if(matrix[i][r] != 0) 
		    rowSwp(matrix[r], matrix[i]);
	rowScl(matrix[r], cols, 1/matrix[r][r]);
	for(int l = r + 1; l < rows; l++){
	    if(l > rows) break ;
	    rowAdd(matrix[l], cols, matrix[r], -matrix[l][r]);
	}
    }
}

int solvTriangle(double **matrix, int rows, double* sols){
    int cols = rows + 1;
    for(int r = rows-2; r >= 0; r -- )
	for(int i = r; i >= 0; i--)
	    rowAdd(matrix[i], rows + 1, matrix[r+1], -matrix[i][r+1]);	
    return 0;
}
void scanRandom(double **matrix, int rows) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < rows +1; j++) 
            matrix[i][j] = (double) (rand() % 10);
}
void scanFile(double ** matrix, int rows, FILE *file){
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < rows +1; j++) 
	    fscanf(file, "%lf", &matrix[i][j]);
}

int printm(double **matrix, int size) {
    if (matrix == NULL) {
	fprintf(stderr, "Bad Matrix pointer in print");
        return 1; // matrix pointer is null
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= size; j++) printf("\t%5.2f ", matrix[i][j]);
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
        printf("Enter the size of the matrix: ");
        scanf("%d", &n);
        printf("enter 'm' if you wish to enter a square matrix, or\n's' if you wish to enter a triangular matrix\n");
        scanf("%s", method);
    }
    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) matrix[i] = (double *)malloc((n+1) * sizeof(double));
    double * sols = (double *)malloc(n * sizeof(double));
    
    if     (method[0] == 't') scanRandom(matrix, n);
    else if(method[0] == 'm') scanMatrix(matrix, n); 
    else if(method[0] == 's') scanSystem(matrix, n); 
    else if(method[0] == 'f') scanFile(matrix, n, in);
    else {fprintf(stderr, "no method selected"); exit(1);}
    printf("matrix stored\n");
    
    printm(matrix, n);
    makeTriangle(matrix, n);
    printm(matrix, n);
    solvTriangle(matrix, n, sols);
    printm(matrix, n); 
    for(int i = 0; i < n; i++){
	printf("%6lf\t", sols[i]);
    }
    printf("\n");
    // free memory
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
    return 0;
}
