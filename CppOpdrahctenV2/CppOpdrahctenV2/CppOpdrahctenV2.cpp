#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& s) {
    std::string lowerCaseString = s;
    std::transform(lowerCaseString.begin(), lowerCaseString.end(), lowerCaseString.begin(), ::tolower);

    int left = 0;
    int right = lowerCaseString.length() - 1;

    while (left < right) {
        if (lowerCaseString[left] != lowerCaseString[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    if (isPalindrome(input)) {
        std::cout << input << " is a palindrome" << std::endl;
    }
    else {
        std::cout << input << " is not a palindrome" << std::endl;
    }

    return 0;
}
