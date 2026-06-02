#include <stdio.h>

#define MAX 10

// Function for Matrix Addition
void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function for Matrix Multiplication
void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2)
{
    int i, j, k;

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function for Transpose
void transposeMatrix(int a[MAX][MAX], int transpose[MAX][MAX], int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            transpose[j][i] = a[i][j];
        }
    }
}

// Function to Display Matrix
void displayMatrix(int matrix[MAX][MAX], int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[MAX][MAX], b[MAX][MAX];
    int add[MAX][MAX], mul[MAX][MAX], trans[MAX][MAX];
    int r1, c1, r2, c2;
    int i, j;

    // Input for first matrix
    printf("Enter rows and columns of First Matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of First Matrix:\n");
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Input for second matrix
    printf("Enter rows and columns of Second Matrix: ");
    scanf("%d %d", &r2, &c2);

    printf("Enter elements of Second Matrix:\n");
    for(i = 0; i < r2; i++)
    {
        for(j = 0; j < c2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    // Matrix Addition
    if(r1 == r2 && c1 == c2)
    {
        addMatrix(a, b, add, r1, c1);

        printf("\nMatrix Addition:\n");
        displayMatrix(add, r1, c1);
    }
    else
    {
        printf("\nMatrix Addition not possible.\n");
    }

    // Matrix Multiplication
    if(c1 == r2)
    {
        multiplyMatrix(a, b, mul, r1, c1, c2);

        printf("\nMatrix Multiplication:\n");
        displayMatrix(mul, r1, c2);
    }
    else
    {
        printf("\nMatrix Multiplication not possible.\n");
    }

    // Transpose of First Matrix
    transposeMatrix(a, trans, r1, c1);

    printf("\nTranspose of First Matrix:\n");
    displayMatrix(trans, c1, r1);

    return 0;
}