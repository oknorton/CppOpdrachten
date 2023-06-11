#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream inputFile("Exercise3_8.txt");
    if (!inputFile) {
        return 1;
    }

    std::vector<int> numbers;
    int number;
    while (inputFile >> number) {
        numbers.push_back(number);
    }

    inputFile.close();

    std::sort(numbers.rbegin(), numbers.rend());

    std::ofstream outputFile("Exercise3_8.txt");
    if (!outputFile) {
        return 1;
    }

    for (int num : numbers) {
        outputFile << num << " ";
    }

    outputFile.close();

    std::cout << "Numbers flipped" << std::endl;

    return 0;
}
