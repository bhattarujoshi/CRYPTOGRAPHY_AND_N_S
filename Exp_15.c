#include <stdio.h>
#include <string.h>

// Function to calculate frequency of each letter
void calculate_frequency(char *ciphertext, int freq[]) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            freq[ciphertext[i] - 'a']++;
        }
    }
}

// Function to decrypt with a given key
void decrypt_with_key(char *ciphertext, int key, char *plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] == ' ') {
            plaintext[i] = ' ';
        } else {
            plaintext[i] = ((ciphertext[i] - 'a' - key + 26) % 26) + 'a';
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

// Function to generate possible plaintexts
void frequency_attack(char *ciphertext) {
    int freq[26] = {0};
    char plaintext[100];

    calculate_frequency(ciphertext, freq);

    printf("Possible plaintexts:\n");
    for (int key = 0; key < 26; key++) {
        decrypt_with_key(ciphertext, key, plaintext);
        printf("Key %2d: %s\n", key, plaintext);
    }
}

int main() {
    char ciphertext[] = "wklv lv d whvw phvvdjh";

    frequency_attack(ciphertext);

    return 0;
}
