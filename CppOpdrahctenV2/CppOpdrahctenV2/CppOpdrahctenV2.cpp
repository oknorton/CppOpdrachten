#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template<typename T>
void removeDuplicates(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end());
}

int main() {
    std::vector<int> numbers;

    std::cout << "Enter ten integers: ";
    for (int i = 0; i < 10; i++) {
        int input;
        std::cin >> input;
        numbers.push_back(input);
    }

    removeDuplicates(numbers);

    std::cout << "The distinct integers are: ";
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
