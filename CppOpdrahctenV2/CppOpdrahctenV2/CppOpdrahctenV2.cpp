#include <iostream>
#include <vector>

std::vector<int> findLargestBlock(const std::vector<std::vector<int>>& m) {
    int maxRow = 0;
    int maxCol = 0;
    int maxSize = 0;

    int numRows = m.size();
    int numCols = m[0].size();

    std::vector<std::vector<int>> dp(numRows, std::vector<int>(numCols, 0));

    for (int i = 0; i < numRows; i++) {
        dp[i][0] = m[i][0];
    }
    for (int j = 0; j < numCols; j++) {
        dp[0][j] = m[0][j];
    }

    for (int i = 1; i < numRows; i++) {
        for (int j = 1; j < numCols; j++) {
            if (m[i][j] == 1) {
                dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if (dp[i][j] > maxSize) {
                    maxSize = dp[i][j];
                    maxRow = i - maxSize + 1;
                    maxCol = j - maxSize + 1;
                }
            }
        }
    }

    return { maxRow, maxCol, maxSize };
}

int main() {
    int numRows;
    std::cout << "Enter the number of rows for the matrix: ";
    std::cin >> numRows;

    std::vector<std::vector<int>> matrix(numRows, std::vector<int>(numRows, 0));
    std::cout << "Enter the matrix row by row:" << std::endl;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows; j++) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<int> result = findLargestBlock(matrix);
    int maxRow = result[0];
    int maxCol = result[1];
    int maxSize = result[2];

    std::cout << "The maximum square submatrix is at (" << maxRow << ", " << maxCol << ") with size " << maxSize << std::endl;

    return 0;
}
