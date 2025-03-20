#include <stdio.h>
#include <string.h>

// Function to encrypt the plaintext
void encrypt(char *plaintext, char *cipher) {
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            plaintext[i] = cipher[plaintext[i] - 'a'];
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            plaintext[i] = cipher[plaintext[i] - 'A'] - 32;
        }
    }
}

// Function to decrypt the ciphertext
void decrypt(char *ciphertext, char *cipher) {
    int i;
    char original[26];
    for (i = 0; i < 26; i++) {
        original[cipher[i] - 'a'] = 'a' + i;
    }
    for (i = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            ciphertext[i] = original[ciphertext[i] - 'a'];
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            ciphertext[i] = original[ciphertext[i] - 'A'] - 32;
        }
    }
}

int main() {
    char plaintext[100];
    char cipher[26] ="zyxwvutsrqponml"; // Example cipher alphabet
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    printf("Original Text: %s\n", plaintext);
    encrypt(plaintext, cipher);
    printf("Encrypted Text: %s\n", plaintext);
    decrypt(plaintext, cipher);
    printf("Decrypted Text: %s\n", plaintext);

    return 0;
}
