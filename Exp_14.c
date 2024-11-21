#include <stdio.h>
#include <string.h>

// Function to encrypt plaintext using the key stream
void vigenere_encrypt(char *plaintext, int key[], int key_len) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        if (plaintext[i] == ' ') {
            printf(" ");
        } else {
            int shift = key[i % key_len];
            char encrypted = ((plaintext[i] - 'a') + shift) % 26 + 'a';
            printf("%c", encrypted);
        }
    }
    printf("\n");
}

int main() {
    char plaintext[] = "send more money";
    int key[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    int key_len = sizeof(key) / sizeof(key[0]);

    printf("Ciphertext: ");
    vigenere_encrypt(plaintext, key, key_len);

    return 0;
}
