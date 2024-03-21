#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 10; // Maximum size of the matrix

// Reads matrix data from a file
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int &size, const std::string &filename) {
    std::ifstream file(filename); // Open file
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    file >> size; // Read matrix size
    for (int i = 0; i < size; ++i) {  // Loop through rows
        for (int j = 0; j < size; ++j) { // Loop through columns
            file >> matrix[i][j]; // Read matrix elements
        }
    }
    file.close(); // Close file
}

// Function to print a matrix
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) { // Pass matrix and size as parameters
    for (int i = 0; i < size; ++i) { // Loop through rows
        for (int j = 0; j < size; ++j) { // Loop through columns
            std::cout << std::setw(4) << matrix[i][j]; // Align output
        }
        std::cout << std::endl; // New line after each row
    }
}

// Function to add two matrices
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) { // Loop through rows
        for (int j = 0; j < size; ++j) { // Loop through columns
            result[i][j] = matrix1[i][j] + matrix2[i][j]; // Add elements
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) { // Loop through rows
        for (int j = 0; j < size; ++j) { // Loop through columns
            result[i][j] = 0; // Initialize result
            for (int k = 0; k < size; ++k) { // Loop through columns of matrix1
                result[i][j] += matrix1[i][k] * matrix2[k][j]; // Multiply and add elements
            }
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) { // Loop through rows
        for (int j = 0; j < size; ++j) { // Loop through columns
            result[i][j] = matrix1[i][j] - matrix2[i][j]; // Subtract elements
        }
    }
}

// Function to update an element in the matrix
void updateElement(int matrix[MAX_SIZE][MAX_SIZE], int size, int row, int col, int newValue) { // Pass matrix, size, row, column, and new value as parameters
    if (row >= 0 && row < size && col >= 0 && col < size) { // Check if row and column are valid
        matrix[row][col] = newValue; // Update element
    } else { // If row or column is invalid, display error message
        std::cerr << "Invalid row or column." << std::endl;
    }
}

// Function to find max value in a matrix
int findMaxValue(const int matrix[MAX_SIZE][MAX_SIZE], int size) { // Pass matrix and size as parameters
    int maxVal = matrix[0][0]; // Initialize max value
    for (int i = 0; i < size; ++i) { // Loop through rows
        for (int j = 0; j < size; ++j) { // Loop through columns
            if (matrix[i][j] > maxVal) { // If element is greater than max value
                maxVal = matrix[i][j]; // Update max value
            }
        }
    }
    return maxVal; // Return max value
}

// Function to transpose a matrix
void transposeMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) { // Pass matrix and size as parameters
    int transposed[MAX_SIZE][MAX_SIZE]; // Create a new matrix to store the transposed matrix
    for (int i = 0; i < size; ++i) { // Loop through rows
        for (int j = 0; j < size; ++j) { // Loop through columns
            transposed[j][i] = matrix[i][j]; // Transpose elements
        }
    }
    printMatrix(transposed, size); 
}

int main() { 
    int size; // Declare size variable
    int matrix1[MAX_SIZE][MAX_SIZE]; // Declare matrix1
    int matrix2[MAX_SIZE][MAX_SIZE]; // Declare matrix2
    int result[MAX_SIZE][MAX_SIZE]; // Declare result matrix

    readMatrix(matrix1, size, "matrix.txt"); // Read matrix data from file
    readMatrix(matrix2, size, "matrix.txt");

    std::cout << "Matrix 1:" << std::endl; // Print matrix1
    printMatrix(matrix1, size); // Call printMatrix function
    std::cout << std::endl; // New line

    std::cout << "Matrix 2:" << std::endl; // Print matrix2
    printMatrix(matrix2, size); // Call printMatrix function
    std::cout << std::endl; 

    addMatrices(matrix1, matrix2, result, size); // Add matrix1 and matrix2
    std::cout << "Matrix 1 + Matrix 2:" << std::endl; // Print result
    printMatrix(result, size);
    std::cout << std::endl;

    multiplyMatrices(matrix1, matrix2, result, size); // Multiply matrix1 and matrix2
    std::cout << "Matrix 1 * Matrix 2:" << std::endl; // Print result
    printMatrix(result, size);
    std::cout << std::endl;

    subtractMatrices(matrix1, matrix2, result, size); // Subtract matrix2 from matrix1
    std::cout << "Matrix 1 - Matrix 2:" << std::endl; // Print result
    printMatrix(result, size);
    std::cout << std::endl;

    updateElement(matrix1, size, 0, 0, 100); // Update element in matrix1
    std::cout << "Updated Matrix 1:" << std::endl; // Print updated matrix1
    printMatrix(matrix1, size);
    std::cout << std::endl;

    std::cout << "Max value in Matrix 1: " << findMaxValue(matrix1, size) << std::endl; // Find max value in matrix1
    std::cout << std::endl;

    std::cout << "Transpose of Matrix 1:" << std::endl; // Transpose matrix1
    transposeMatrix(matrix1, size);

    return 0;
}
