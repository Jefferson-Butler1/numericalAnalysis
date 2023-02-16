#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

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

void solvSystem(double **matrix, int rows) {
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

int main() {
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(n * sizeof(double));
    }

    scanSystem(matrix, n); 
    solvSystem(matrix, n);
    // print the matrix
    printf("The upper triangular matrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (j < i) {
                printf("%10s", "");
            } else {
                printf("%10.2lf", matrix[i][j]);
            }
        }
        printf("\n");
    }

    // free memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
