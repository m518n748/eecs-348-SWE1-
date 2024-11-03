#include <iostream>
#include <cstdlib>
using namespace std;
const int SIZE = 4; // Global variable for matrix size


class Matrix {

private:
    int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)
    const int SIZE = 4; // Global variable for matrix size

public:
    // 1. Read values from stdin into a matrix
    void readFromStdin()
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) { //nested loop for reading each element
                if (!(cin >> data[i][j])) {
                    cout << "Invalid input (Please enter an integer)" << endl;
                    exit(EXIT_FAILURE); //exit the program if input is invalid (not an integer)
                }
            }
        }
    }

    // 2. Display a matrix
    void display() const
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << data[i][j] << " "; //print each element
            }
            cout << endl;
        }
    }

    // 3. Add two matrices (operator overloading for +)
    
    Matrix operator+(const Matrix& other) 
    {
        if (SIZE != other.SIZE) { //check if the size of the two matrices are the same
            cout << "Matrices size invalid for adding" << endl;
            return *this; //return the current matrix if the sizes are not the same
        }
        Matrix sum;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                sum.data[i][j] = data[i][j] + other.data[i][j]; //add the corresponding elements
            }
        }
        return sum; //return the sum matrix
    }

    // 4. Multiply two matrices (operator overloading for *)
    Matrix operator*(const Matrix& other)
    {
        if (SIZE != other.SIZE) { //check if the size of the two matrices are the same
            cout << "Matrices size invalid for multiplying" << endl;
            return *this;
        }
        Matrix product;
        for (int i = 0; i < SIZE; i++) { 
            for (int j = 0; j < SIZE; j++) {
                product.data[i][j] = 0; //initialize the product matrix to 0
                for (int k = 0; k < SIZE; k++) {
                    product.data[i][j] += data[i][k] * other.data[k][j]; //multiply the corresponding elements
                }
            }
        }
        return product; //return the product matrix
    }
    
    // 5. Compute the sum of matrix diagonal elements
    int sumOfDiagonals() const
    {
        int sum = 0;
        for (int i = 0; i < SIZE; i++) { //loop through the diagonal elements
            sum +=data[i][i]; //add the diagonal elements
        }
        return sum;

    }

    // 6. Swap matrix rows
    void swapRows(int row1, int row2)
    {
        if (row1 < 0 || row1 >= SIZE || row2 < 0 || row2 >= SIZE) { //check if the row numbers are valid
            cout << "Invalid row numbers for swapping" << endl;
        }
        else {
            for (int j = 0; j < SIZE; j++) {
                int temp = data[row1][j]; //swap the elements of the two rows
                data[row1][j] = data[row2][j];
                data[row2][j] = temp;
            }
        }
    }
    };


int main() {
// Example usage:
    Matrix mat1;
    cout << "Enter values for Matrix 1:" << endl;
    mat1.readFromStdin();
    cout << "Matrix 1:" << endl;
    mat1.display();
    Matrix mat2;
    cout << "Enter values for Matrix 2:" << endl;
    mat2.readFromStdin();
    cout << "Matrix 2:" << endl;
    mat2.display();
    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();
    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();
    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();
return 0;
}