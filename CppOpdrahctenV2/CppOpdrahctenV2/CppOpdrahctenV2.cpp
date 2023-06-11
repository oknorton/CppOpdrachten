#include <iostream>

const int SIZE = 4;

double sumColumn(const double m[][SIZE], int rowSize, int columnIndex) {
    double sum = 0;
    for (int i = 0; i < rowSize; i++) {
        sum += m[i][columnIndex];
    }
    return sum;
}

int main() {
    double matrix[3][SIZE];
    std::cout << "Enter a 3-by-4 matrix row by row:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < SIZE; i++) {
        double colSum = sumColumn(matrix, 3, i);
        std::cout << "Sum of the elements at column " << i + 1 << " is " << colSum << std::endl;
    }

    return 0;
}