#include <iostream>

using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

// Fungsi untuk menginput matriks
void inputMatrix(int matrix[][MAX_COLS], int numRows, int numCols) {
    cout << "Masukkan elemen matriks:" << endl;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cin >> matrix[i][j];
        }
    }
}

// Fungsi untuk menampilkan matriks
void printMatrix(int matrix[][MAX_COLS], int numRows, int numCols) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk mengurangkan dua matriks
void subtractMatrix(int A[][MAX_COLS], int B[][MAX_COLS], int C[][MAX_COLS], int numRows, int numCols) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Fungsi untuk mengalikan dua matriks
void multiplyMatrix(int A[][MAX_COLS], int B[][MAX_COLS], int C[][MAX_COLS], int numRowsA, int numColsA, int numColsB) {
    for (int i = 0; i < numRowsA; ++i) {
        for (int j = 0; j < numColsB; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < numColsA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Fungsi untuk menjumlahkan dua matriks
void addMatrix(int A[][MAX_COLS], int B[][MAX_COLS], int C[][MAX_COLS], int numRows, int numCols) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Fungsi untuk membagi dua matriks
void divideMatrix(int A[][MAX_COLS], int B[][MAX_COLS], int C[][MAX_COLS], int numRows, int numCols) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (B[i][j] == 0) {
                cout << "Operasi pembagian tidak bisa dilakukan karena matriks B memiliki elemen 0." << endl;
                return;
            }
            C[i][j] = A[i][j] / B[i][j];
        }
    }
}


int main() {
    int matrixA[MAX_ROWS][MAX_COLS];
    int matrixB[MAX_ROWS][MAX_COLS];
    int result[MAX_ROWS][MAX_COLS];
    int numRowsA, numColsA, numRowsB, numColsB;

    cout << "Masukkan jumlah baris matriks A: ";
    cin >> numRowsA;
    cout << "Masukkan jumlah kolom matriks A: ";
    cin >> numColsA;

    cout << "Masukkan jumlah baris matriks B: ";
    cin >> numRowsB;
    cout << "Masukkan jumlah kolom matriks B: ";
    cin >> numColsB;

    if (numColsA != numRowsB) {
        cout << "Operasi perkalian matriks tidak bisa dilakukan karena jumlah kolom matriks A tidak sama dengan jumlah baris matriks B." << endl;
        return 1;
    }

    if (numRowsA > MAX_ROWS || numColsA > MAX_COLS || numRowsB > MAX_ROWS || numColsB > MAX_COLS) {
        cout << "Ukuran matriks terlalu besar. Maksimum " << MAX_ROWS << " baris dan " << MAX_COLS << " kolom." << endl;
        return 1;
    }
    

    cout << "Masukkan elemen matriks A:" << endl;
    inputMatrix(matrixA, numRowsA, numColsA);

    cout << "Masukkan elemen matriks B:" << endl;
    inputMatrix(matrixB, numRowsB, numColsB);

    // Operasi pengurangan matriks
    if (numRowsA == numRowsB && numColsA == numColsB) {
        subtractMatrix(matrixA, matrixB, result, numRowsA, numColsA);
        cout << "Hasil pengurangan matriks A dan B:" << endl;
        printMatrix(result, numRowsA, numColsA);
    } else {
        cout << "Operasi pengurangan matriks tidak bisa dilakukan karena ukuran matriks tidak sesuai." << endl;
    }
    
    if (numRowsA == numRowsB && numColsA == numColsB) {
        addMatrix(matrixA, matrixB, result, numRowsA, numColsA);
        cout << "Hasil penjumlahan matriks A dan B:" << endl;
        printMatrix(result, numRowsA, numColsA);
    } else {
        cout << "Operasi penjumlahan matriks tidak bisa dilakukan karena ukuran matriks tidak sesuai." << endl;
    }

    // Pembagian matriks
    divideMatrix(matrixA, matrixB, result, numRowsA, numColsA);
    cout << "Hasil pembagian matriks A dan B:" << endl;
    printMatrix(result, numRowsA, numColsA);

    // Operasi perkalian matriks
    multiplyMatrix(matrixA, matrixB, result, numRowsA, numColsA, numColsB);
    cout << "Hasil perkalian matriks A dan B:" << endl;
    printMatrix(result, numRowsA, numColsB);
    

    return 0;
}
