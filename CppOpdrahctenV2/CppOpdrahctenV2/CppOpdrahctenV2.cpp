#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
std::vector<T> intersect(const std::vector<T>& v1, const std::vector<T>& v2) {
    std::vector<T> result;
    for (const auto& element : v1) {
        if (std::find(v2.begin(), v2.end(), element) != v2.end()) {
            result.push_back(element);
        }
    }
    return result;
}

int main() {
    std::vector<std::string> vector1;
    std::vector<std::string> vector2;

    std::cout << "Enter five strings for vector1: ";
    for (int i = 0; i < 5; i++) {
        std::string input;
        std::cin >> input;
        vector1.push_back(input);
    }

    std::cout << "Enter five strings for vector2: ";
    for (int i = 0; i < 5; i++) {
        std::string input;
        std::cin >> input;
        vector2.push_back(input);
    }

    std::vector<std::string> intersection = intersect(vector1, vector2);

    std::cout << "The common strings are: ";
    for (const auto& element : intersection) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
