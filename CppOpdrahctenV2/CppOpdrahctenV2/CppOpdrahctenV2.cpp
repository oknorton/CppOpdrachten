#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// Typedef voor de lambda-functie
typedef std::function<int(const std::vector<int>&)> MyLambdaType;

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    MyLambdaType sum = [](const std::vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        return total;
    };

    int result = sum(numbers);

    std::cout << "De som van de getallen is: " << result << std::endl;

    return 0;
}
