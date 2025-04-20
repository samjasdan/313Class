#include <iostream>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {  
            cout << val << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();  
    int colsA = A[0].size();
    int rowsB = B.size();  
    int colsB = B[0].size();
   
    if (colsA != rowsB) {
        throw invalid_argument("Matrix dimensions are not compatible for multiplication.");
    }
   
    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));
   
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

vector<vector<int>> transposeMatrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();  
    int cols = matrix[0].size();
    vector<vector<int>> transposed(cols, vector<int>(rows));
   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rows = A.size();  
    int cols = A[0].size();
   
    if (rows != B.size() || cols != B[0].size()) {
        throw invalid_argument("Matrix dimensions are not compatible for addition.");
    }
   
    vector<vector<int>> result(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

int main() {
    vector<vector<int>> A = {{6, 4}, {8, 3}};
    vector<vector<int>> B = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> C = {{2, 4}, {1, 3}, {5, 6}};

    try {
        for (auto& row : B) {
            for (auto& element : row) {
                element *= 3;
            }
        }

        vector<vector<int>> C_T = transposeMatrix(C);

        vector<vector<int>> result = multiplyMatrices(B, C);

        vector<vector<int>> D = addMatrices(A, result);

        cout << "Matrix D is: " << endl;
        printMatrix(D);

    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}
