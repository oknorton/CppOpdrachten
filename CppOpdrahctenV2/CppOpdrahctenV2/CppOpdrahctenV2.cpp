#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::string> words = { "hallo", "wereld", "en Peter", "programma" };

std::string getRandomWord() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int index = std::rand() % words.size();
    return words[index];
}

std::string getHiddenWord(const std::string& word, const std::vector<bool>& revealed) {
    std::string hiddenWord;
    for (size_t i = 0; i < word.length(); ++i) {
        if (revealed[i]) {
            hiddenWord += word[i];
        }
        else {
            hiddenWord += '*';
        }
    }
    return hiddenWord;
}

bool isLetterInWord(const std::string& word, char letter) {
    return word.find(letter) != std::string::npos;
}

void revealLetter(const std::string& word, std::vector<bool>& revealed, char letter) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (word[i] == letter) {
            revealed[i] = true;
        }
    }
}

bool isWordComplete(const std::vector<bool>& revealed) {
    for (bool letterRevealed : revealed) {
        if (!letterRevealed) {
            return false;
        }
    }
    return true;
}

void playHangman() {
    std::string word = getRandomWord();
    std::vector<bool> revealed(word.length(), false);
    int misses = 0;

    while (true) {
        std::cout << "(Guess) Enter a letter in the word " << getHiddenWord(word, revealed) << " > ";
        char guess;
        std::cin >> guess;

        if (isLetterInWord(word, guess)) {
            if (isWordComplete(revealed)) {
                std::cout << "The word is " << word << ". You missed " << misses << " time." << std::endl;
                break;
            }
            if (std::find(revealed.begin(), revealed.end(), true) != revealed.end()) {
                std::cout << guess << " is already in the word" << std::endl;
            }
            revealLetter(word, revealed, guess);
        }
        else {
            std::cout << guess << " is not in the word" << std::endl;
            misses++;
        }
    }
}

int main() {
    char playAgain;
    do {
        playHangman();

        std::cout << "Do you want to guess for another word? Enter 'y' or 'n' > ";
        std::cin >> playAgain;
    } while (playAgain == 'y');

    return 0;
}
