#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 10; // Maximum size of the matrix

// Function to read matrix data from a file
void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int &size, const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    file >> size; // Read matrix size
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j]; // Read matrix elements
        }
    }
    file.close();
}

// Function to print a matrix
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(4) << matrix[i][j]; // Align output
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to update an element in the matrix
void updateElement(int matrix[MAX_SIZE][MAX_SIZE], int size, int row, int col, int newValue) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = newValue;
    } else {
        std::cerr << "Invalid row or column." << std::endl;
    }
}

// Function to find max value in a matrix
int findMaxValue(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

// Function to transpose a matrix
void transposeMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int transposed[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    printMatrix(transposed, size);
}

int main() {
    int size;
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    readMatrixFromFile(matrix1, size, "matrix.txt");
    readMatrixFromFile(matrix2, size, "matrix.txt");

    std::cout << "Matrix 1:" << std::endl;
    printMatrix(matrix1, size);
    std::cout << std::endl;

    std::cout << "Matrix 2:" << std::endl;
    printMatrix(matrix2, size);
    std::cout << std::endl;

    addMatrices(matrix1, matrix2, result, size);
    std::cout << "Matrix 1 + Matrix 2:" << std::endl;
    printMatrix(result, size);
    std::cout << std::endl;

    multiplyMatrices(matrix1, matrix2, result, size);
    std::cout << "Matrix 1 * Matrix 2:" << std::endl;
    printMatrix(result, size);
    std::cout << std::endl;

    subtractMatrices(matrix1, matrix2, result, size);
    std::cout << "Matrix 1 - Matrix 2:" << std::endl;
    printMatrix(result, size);
    std::cout << std::endl;

    updateElement(matrix1, size, 0, 0, 100);
    std::cout << "Updated Matrix 1:" << std::endl;
    printMatrix(matrix1, size);
    std::cout << std::endl;

    std::cout << "Max value in Matrix 1: " << findMaxValue(matrix1, size) << std::endl;
    std::cout << std::endl;

    std::cout << "Transpose of Matrix 1:" << std::endl;
    transposeMatrix(matrix1, size);

    return 0;
}
