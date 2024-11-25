#include <stdio.h>
#include <string.h>

void ctrEncrypt(char *message, int key, int counter) {
    for (int i = 0; i < strlen(message); i++) {
        message[i] ^= (key + counter) % 256; // XOR plaintext with keystream
        counter++;
    }
}

void ctrDecrypt(char *message, int key, int counter) {
    ctrEncrypt(message, key, counter); // Decryption is identical to encryption
}

int main() {
    char message[128];
    int key = 7, counter = 0;

    printf("Enter plaintext: ");
    scanf("%s", message);

    printf("Original message: %s\n", message);
    ctrEncrypt(message, key, counter);
    printf("Encrypted message: %s\n", message);

    ctrDecrypt(message, key, counter);
    printf("Decrypted message: %s\n", message);

    return 0;
}
