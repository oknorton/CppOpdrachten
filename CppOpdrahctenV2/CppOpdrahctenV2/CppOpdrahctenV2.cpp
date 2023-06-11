#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("Exercise3_5.txt");
    if (!inputFile) {
        std::cout << "File does not exist." << std::endl;
        return 1;
    }

    std::string line;
    int characterCount = 0;

    while (std::getline(inputFile, line)) {
        characterCount += line.length();
    }

    inputFile.close();

    std::ofstream outputFile("Exercise3_5.txt");
    if (!outputFile) {
        return 1;
    }

    outputFile << "Total number of characters: " << characterCount << std::endl;
    outputFile.close();

    std::cout << "Characterr count appended." << std::endl;

    return 0;
}
