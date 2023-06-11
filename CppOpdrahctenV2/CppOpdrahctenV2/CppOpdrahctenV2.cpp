#include <stdio.h>
#include <ctype.h>

void count(const char s[], int counts[]) {
    for (int i = 0; i < 26; i++) {
        counts[i] = 0;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        char c = tolower(s[i]);
        if (isalpha(c)) {
            counts[c - 'a']++;
        }
    }
}

int main() {
    char s[100];
    int counts[26];

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    count(s, counts);

    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0) {
            printf("%c: %d times\n", 'a' + i, counts[i]);
        }
    }

    return 0;
}