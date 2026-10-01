#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// Helper function to print a matrix with right-aligned formatting
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << setw(4) << val;
        }
        cout << "\n";
    }
}

// 1. Read values from a file into the matrix
bool loadMatrices(const string& filename, int& N, vector<vector<int>>& A, vector<vector<int>>& B) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Cannot open file " << filename << "\n";
        return false;
    }
    
    // Read the size of the square matrix
    if (!(file >> N) || N <= 0) {
        cerr << "Error: Invalid matrix size.\n";
        return false;
    }
    
    // Initialize matrices with size N x N
    A.assign(N, vector<int>(N));
    B.assign(N, vector<int>(N));
    
    // Load Matrix A
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> A[i][j];
        }
    }
    
    // Load Matrix B
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> B[i][j];
        }
    }
    
    return true;
}

// 2. Add two matrices and display the result
void addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int N = A.size();
    vector<vector<int>> C(N, vector<int>(N));
    cout << "A + B:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = A[i][j] + B[i][j]; // Entry-by-entry addition[cite: 5]
        }
    }
    printMatrix(C);
}

// 3. Multiply two matrices and display the result
void multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int N = A.size();
    vector<vector<int>> C(N, vector<int>(N, 0));
    cout << "A * B:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j]; // Row-column dot product[cite: 5]
            }
        }
    }
    printMatrix(C);
}

// 4. Get the sums of matrix diagonal elements
void diagonalSums(const vector<vector<int>>& A) {
    int N = A.size();
    int mainSum = 0;
    int secSum = 0;
    for (int i = 0; i < N; ++i) {
        mainSum += A[i][i];             // Top-left to bottom-right[cite: 4]
        secSum += A[i][N - 1 - i];      // Top-right to bottom-left[cite: 4]
    }
    cout << "Diagonal sums for Matrix A:\n";
    cout << "Main diagonal sum: " << mainSum << "\n";
    cout << "Secondary diagonal sum: " << secSum << "\n";
}

// 5. Swap matrix rows and display the result
// Passing matrix A by value so the original remains unmodified for subsequent problems
void swapRows(vector<vector<int>> A, int r1, int r2) {
    int N = A.size();
    // Valid means index is between 0 and N-1
    if (r1 >= 0 && r1 < N && r2 >= 0 && r2 < N) {
        swap(A[r1], A[r2]);
        cout << "Problem 5 - Rows " << r1 << " and " << r2 << " swapped:\n";
        printMatrix(A);
    } else {
        cout << "Invalid row indices.\n";
    }
}

// 6. Swap matrix columns and display the result
void swapCols(vector<vector<int>> A, int c1, int c2) {
    int N = A.size();
    if (c1 >= 0 && c1 < N && c2 >= 0 && c2 < N) {
        for (int i = 0; i < N; ++i) {
            swap(A[i][c1], A[i][c2]);
        }
        cout << "Problem 6 - Columns " << c1 << " and " << c2 << " swapped:\n";
        printMatrix(A);
    } else {
        cout << "Invalid column indices.\n";
    }
}

// 7. Update a matrix element and display the result
void updateElement(vector<vector<int>> A, int r, int c, int val) {
    int N = A.size();
    if (r >= 0 && r < N && c >= 0 && c < N) {
        A[r][c] = val; // Direct indexed access update
        cout << "Problem 7 - Updated matrix:\n";
        printMatrix(A);
    } else {
        cout << "Invalid indices.\n";
    }
}

int main() {
    string filename;
    cout << "Enter input filename: \n";
    cin >> filename;
    
    int N;
    vector<vector<int>> A, B;
    
    if (loadMatrices(filename, N, A, B)) {
        cout << "Matrix A:\n";
        printMatrix(A);
        
        cout << "\nMatrix B:\n";
        printMatrix(B);
        
        cout << "\n";
        addMatrices(A, B);
        
        cout << "\n";
        multiplyMatrices(A, B);
        
        cout << "\n";
        diagonalSums(A);
        
        cout << "\n";
        // Passing arguments based on the expected sample output targets
        swapRows(A, 0, 2);
        
        cout << "\n";
        swapCols(A, 0, 2);
        
        cout << "\n";
        updateElement(A, 1, 2, 99);
    }
    
    return 0;
}
