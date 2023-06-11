#include <iostream>
#include <string>


bool search(std::string basicString, char key);

int main() {
    std::string s;
    char key;
    std::cout << "Enter a string";
    std::getline(std::cin, s);
    std::cout << "Search for a character in the previously entered string: ";
    std::cin >> key;
    if (search(s, key)) {
        std::cout << "The character " << key << " is found in the string: " << s << "\n";
    }
    else {
        std::cout << "The character " << key << " is not found in the string: " << s << "\n";
    }
    return 0;
}

bool search(std::string s, char key) {
    for (char c : s) {
        if (c == key) {
            return true;
        }
    }
    return false;
}
