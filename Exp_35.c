#include <stdio.h>
#include <string.h>

void vigenere_encrypt(const char *plaintext, const int *key, char *ciphertext, int key_length) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = ((plaintext[i] - 'A') + key[i % key_length]) % 26 + 'A';
    }
    ciphertext[strlen(plaintext)] = '\0';
}

int main() {
    char plaintext[] = "HELLO";
    int key[] = {3, 1, 9, 5}; // Example key
    char ciphertext[100];

    vigenere_encrypt(plaintext, key, ciphertext, 4);

    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
