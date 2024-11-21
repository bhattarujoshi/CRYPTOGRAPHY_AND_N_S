#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

// Frequency of English letters in standard texts
const float english_frequencies[ALPHABET_SIZE] = {
    8.2, 1.5, 2.8, 4.3, 12.7, 2.2, 2.0, 6.1, 7.0, 0.2, 
    0.8, 4.0, 2.4, 6.7, 7.5, 1.9, 0.1, 6.0, 6.3, 9.1, 
    2.8, 1.0, 2.4, 0.2, 2.0, 0.1
};

// Function to calculate letter frequencies in a text
void calculate_frequencies(const char *text, float frequencies[ALPHABET_SIZE]) {
    int count[ALPHABET_SIZE] = {0};
    int total = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            count[text[i] - 'a']++;
            total++;
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            count[text[i] - 'A']++;
            total++;
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        frequencies[i] = ((float)count[i] / total) * 100;
    }
}

// Function to match ciphered text frequencies with English frequencies
void perform_frequency_attack(const char *ciphertext, int top_matches) {
    float cipher_frequencies[ALPHABET_SIZE] = {0};
    calculate_frequencies(ciphertext, cipher_frequencies);

    printf("Letter frequencies in ciphertext:\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c: %.2f%%\n", 'A' + i, cipher_frequencies[i]);
    }

    printf("\nFrequency analysis not fully automated in this sample.\n");
    printf("You can manually match high-frequency letters (e.g., E, T, A) to ciphertext.\n");
}

int main() {
    char ciphertext[1024];
    int top_matches;

    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    printf("How many top plaintext guesses would you like? ");
    scanf("%d", &top_matches);

    perform_frequency_attack(ciphertext, top_matches);
    return 0;
}
