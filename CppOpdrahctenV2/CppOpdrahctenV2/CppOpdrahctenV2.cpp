#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

int countVowels(const std::string& text) {
    int vowelCount = 0;
    for (char c : text) {
        c = std::tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowelCount++;
    }
    return vowelCount;
}
//Testbestanden om te gebruiken "bestand1.txt", "bestand2.txt"
int main() {
    std::string filename;
    std::cout << "Kies een bestand: ";
    std::cin >> filename;

    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cout << "Bestand bestaat niet." << std::endl;
        return 1;
    }

    std::string fileContents;
    std::string line;
    while (std::getline(inputFile, line)) {
        fileContents += line;
    }

    inputFile.close();

    int vowelCount = countVowels(fileContents);

    std::cout << "Vowel count: " << vowelCount << std::endl;

    return 0;
}
