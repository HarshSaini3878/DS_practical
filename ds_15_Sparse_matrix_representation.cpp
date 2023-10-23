#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a sparse matrix element
struct MatrixElement {
    int row;
    int col;
    int value;
};

// Function to display a sparse matrix
void displaySparseMatrix(const vector<MatrixElement>& sparseMatrix) {
    for (const MatrixElement& element : sparseMatrix) {
        cout << element.row << "\t" << element.col << "\t" << element.value << endl;
    }
}

// Function to add two sparse matrices
vector<MatrixElement> addSparseMatrices(const vector<MatrixElement>& matrix1,
                                        const vector<MatrixElement>& matrix2) {
    vector<MatrixElement> result;
    int index1 = 0;
    int index2 = 0;

    while (index1 < matrix1.size() && index2 < matrix2.size()) {
        if (matrix1[index1].row < matrix2[index2].row ||
            (matrix1[index1].row == matrix2[index2].row && matrix1[index1].col < matrix2[index2].col)) {
            result.push_back(matrix1[index1]);
            ++index1;
        } else if (matrix1[index1].row > matrix2[index2].row ||
                   (matrix1[index1].row == matrix2[index2].row && matrix1[index1].col > matrix2[index2].col)) {
            result.push_back(matrix2[index2]);
            ++index2;
        } else {
            // The elements are at the same position in both matrices
            MatrixElement sumElement;
            sumElement.row = matrix1[index1].row;
            sumElement.col = matrix1[index1].col;
            sumElement.value = matrix1[index1].value + matrix2[index2].value;

            result.push_back(sumElement);

            ++index1;
            ++index2;
        }
    }

    // Copy any remaining elements from matrix1
    while (index1 < matrix1.size()) {
        result.push_back(matrix1[index1]);
        ++index1;
    }

    // Copy any remaining elements from matrix2
    while (index2 < matrix2.size()) {
        result.push_back(matrix2[index2]);
        ++index2;
    }

    return result;
}

int main() {
    // Example sparse matrices
    vector<MatrixElement> sparseMatrix1 = {
        {0, 1, 3},
        {1, 2, 4},
        {2, 0, 1},
    };

    vector<MatrixElement> sparseMatrix2 = {
        {0, 1, 1},
        {1, 2, 2},
        {2, 0, 5},
    };

    // Display the original sparse matrices
    cout << "Sparse Matrix 1:\n";
    displaySparseMatrix(sparseMatrix1);

    cout << "\nSparse Matrix 2:\n";
    displaySparseMatrix(sparseMatrix2);

    // Perform addition of sparse matrices
    vector<MatrixElement> sumMatrix = addSparseMatrices(sparseMatrix1, sparseMatrix2);

    // Display the result of addition
    cout << "\nSum of Sparse Matrices:\n";
    displaySparseMatrix(sumMatrix);

    return 0;
}
