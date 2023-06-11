#include <iostream>
#include <string>
#include <iostream>
#include <string>
using namespace std;
bool isValid(const std::string& cardNumber);
int sumOfDoubleEvenPlace(const std::string& cardNumber);
int getDigit(int number);
int sumOfOddPlace(const std::string& cardNumber);
bool startsWith(const std::string& cardNumber, const std::string& substr);
std::string cardProvider;

int main() {
    string cardNumber;
    cout << "Enter a credit card number: ";
    cin >> cardNumber;
    if (isValid(cardNumber)) {
        cout << cardNumber << " is a valid " << cardProvider << " card-number.\n";
    }
    else {
        cout << cardNumber << "Is an invalid card number.\n";
    }

    return 0;
}

bool isValid(const string& cardNumber) {
    if (cardNumber.length() < 13 || cardNumber.length() > 16) {
        return false;
    }

    if (startsWith(cardNumber, "4")) { // Visa
        return (sumOfDoubleEvenPlace(cardNumber) + sumOfOddPlace(cardNumber)) % 10 == 0;
    }
    else if (startsWith(cardNumber, "5")) { // MasterCard kaart
        cardProvider = "Mastercard";
        return (sumOfDoubleEvenPlace(cardNumber) + sumOfOddPlace(cardNumber)) % 10 == 0;
    }
    else if (startsWith(cardNumber, "37")) { // American Express kaart
        cardProvider = "American Express";
        return (sumOfDoubleEvenPlace(cardNumber) + sumOfOddPlace(cardNumber)) % 10 == 0;
    }
    else if (startsWith(cardNumber, "6")) { // Discover kaart
        cardProvider = "Discover";
        return (sumOfDoubleEvenPlace(cardNumber) + sumOfOddPlace(cardNumber)) % 10 == 0;
    }
    else {
        return false;
    }
}

int sumOfDoubleEvenPlace(const string& cardNumber) {
    int sum = 0;
    for (int i = cardNumber.length() - 2; i >= 0; i -= 2) {
        int doubleVal = (cardNumber[i] - '0') * 2;
        sum += getDigit(doubleVal);
    }
    return sum;
}

int getDigit(int number) {
    if (number < 10) {
        return number;
    }
    else {
        return (number % 10) + (number / 10);
    }
}

int sumOfOddPlace(const string& cardNumber) {
    int sum = 0;
    for (int i = cardNumber.length() - 1; i >= 0; i -= 2) {
        sum += cardNumber[i] - '0';
    }
    return sum;
}

bool startsWith(const string& cardNumber, const string& substr) {
    return cardNumber.find(substr) == 0;
}