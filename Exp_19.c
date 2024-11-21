#include <stdio.h>
#include <string.h>

void cbc_encrypt(const char *plaintext, const char *key, char *ciphertext) {
    // Mock encryption logic
    strcpy(ciphertext, plaintext); // For demonstration only
}

int main() {
    char plaintext[1024], key[24], ciphertext[1024];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the 3DES key: ");
    fgets(key, sizeof(key), stdin);

    cbc_encrypt(plaintext, key, ciphertext);

    printf("Encrypted text (CBC): %s\n", ciphertext);
    return 0;
}
