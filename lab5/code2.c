#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 //size of the matrices

//add matrices function
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE])
{
    int sum[SIZE][SIZE]; //initialize the sum matrix

    for (int i = 0; i < SIZE; i++) //iterate through the matrices
    {
        for (int j = 0; j < SIZE; j++)
        {
            sum[i][j] = m1[i][j] + m2[i][j]; //add the elements of the matrices
        }
    }

    printf("Sum of the matrices:\n"); //print the sum matrix
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

//multiply matrices function
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE])
{
    int product[SIZE][SIZE]; //initialize the product matrix

    if (m1[0][SIZE - 1] != m2[SIZE - 1][0]) //check if the matrices can be multiplied
    {
        printf("Matrices cannot be multiplied\n");
        return;
    }

    for (int i = 0; i < SIZE; i++) //initialize the product matrix
    {
        for (int j = 0; j < SIZE; j++)
        {
            product[i][j] = 0;
        }
    }

    for (int i = 0; i < SIZE; i++) //multiply the matrices
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                product[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    printf("Product of the matrices:\n"); //print the product matrix
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
}

//transpose matrix function
void transposeMatrix(int m[SIZE][SIZE])
{
    int temp[SIZE][SIZE]; //initialize the temporary matrix

    for (int i = 0; i < SIZE; i++) //transpose the matrix
    {
        for (int j = 0; j < SIZE; j++)
        {
            temp[j][i] = m[i][j];
        }
    }

    for (int i = 0; i < SIZE; i++) //copy the transposed matrix back to the original matrix
    {
        for (int j = 0; j < SIZE; j++)
        {
            m[i][j] = temp[i][j];
        }
    }

    for (int i = 0; i < SIZE; i++) //print the transposed matrix
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

//print matrix function
void printMatrix(int m[SIZE][SIZE])
{
    int temp[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
        };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
        };

    //test cases
    addMatrices(m1, m2);
    multiplyMatrices(m1, m2);
    printf("Matrix 1 transposed:\n");
    transposeMatrix(m1);
    printf("Matrix 2 transposed:\n");
    transposeMatrix(m2);
    printf("Matrix 1 printed:\n");
    printMatrix(m1);

    return 0;
}