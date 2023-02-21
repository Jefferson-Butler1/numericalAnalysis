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
    if(matrix[0][0] == 0){
	for(int i = 1; i < rows; i++){
	    if(matrix[i][0] != 0) rowSwp(matrix[0], matrix[i]);
	}
    }
    if(matrix[0][0] == 0){
	    fprintf(stderr, "invalid matrix\n");
	    exit(1);
    }
    for(int r = 0; r < rows; r ++){
	rowScl(matrix[r], cols, 1/matrix[r][r]);
	for(int l = r + 1; l < rows; l++){
	    if(l > rows) break ;
	    rowAdd(matrix[l], cols, matrix[r], -matrix[l][r]);
	printm(matrix, rows);
	}
    }
}
void solvSystem1(double **matrix, int rows) {
    printf("Made it to solv\n");
    int cols = rows + 1; // one more column than row
    int lead = 0; // index of leading variable

    for (int r = 0; r < rows; r++) { // for each row
        if (lead >= cols) {
            break; // no more columns to pivot
        }
        int i = r;
        while (matrix[i][lead] == 0.0) {
            i++;
            if (i == rows) {
                i = r;
                lead++;
                if (lead == cols) {
                    break; // no more columns to pivot
                }
            }
        }
        // swap rows i and r
        double *temp = matrix[i];
        matrix[i] = matrix[r];
        matrix[r] = temp;

        // scale pivot row
        double pivot = matrix[r][lead];
        if (pivot != 1.0) {
            for (int j = lead; j < cols; j++) {
                matrix[r][j] /= pivot;
            }
        }

        // eliminate other rows
        for (int k = 0; k < rows; k++) {
            if (k != r) {
                double factor = matrix[k][lead];
                for (int j = lead; j < cols; j++) {
                    matrix[k][j] -= factor * matrix[r][j];
                }
            }
        }
        lead++;
    }
}
void scanRandom(double **matrix, int rows) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows +1; j++) {
            matrix[i][j] = (double) (rand() % 10);
        }
    }
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

int main() {
    int n;
    char method[2];
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc((n+1) * sizeof(double));
    }
    printf("enter 'm' if you wish to enter a square matrix, or\n's' if you wish to enter a triangular matrix\n");
    scanf("%s", method);
    
    if     (method[0] == 't') scanRandom(matrix, n);
    else if(method[0] == 'm') scanMatrix(matrix, n); 
    else if(method[0] == 's') scanSystem(matrix, n); 
    else {fprintf(stderr, "no method selected"); exit(1);}
    printf("matrix stored\n");
    
    printm(matrix, n);
    makeTriangle(matrix, n);
    printm(matrix, n);
    
    // free memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
