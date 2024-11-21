#include <stdio.h>
#include<string.h>
// Function to encrypt plaintext
char encrypt(char p, int a, int b) {
    return 'a' + (a * (p - 'a') + b) % 26;
}

// Function to decrypt ciphertext
char decrypt(char c, int a, int b) {
    int a_inv = 0;
    // Find modular inverse of a
    for (int i = 0; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            a_inv = i;
            break;
        }
    }
    return 'a' + (a_inv * (c - 'a' - b + 26)) % 26;
}

int main() {
    char plaintext[100] = "hello";
    int a = 5, b = 8;

    // Check if a is valid
    if (a == 0 || (a % 2 == 0 && a % 13 == 0)) {
        printf("Invalid value of a\n");
        return 1;
    }

    printf("Original Text: %s\n", plaintext);
    for (int i = 0; i < strlen(plaintext); i++) {
        plaintext[i] = encrypt(plaintext[i], a, b);
    }
    printf("Encrypted Text: %s\n", plaintext);

    for (int i = 0; i < strlen(plaintext); i++) {
        plaintext[i] = decrypt(plaintext[i], a, b);
    }
    printf("Decrypted Text: %s\n", plaintext);

    return 0;
}