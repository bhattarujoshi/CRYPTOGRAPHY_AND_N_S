#include <stdio.h>
#include <string.h>

void encryptAffineCBC(char *message, int keyA, int keyB, int iv) {
    int block;
    for (int i = 0; i < strlen(message); i++) {
        block = (message[i] ^ iv); // XOR with Initialization Vector (IV)
        message[i] = ((block * keyA) + keyB) % 256; // Affine cipher
        iv = message[i]; // Update IV
    }
}

void decryptAffineCBC(char *message, int keyA, int keyB, int iv, int keyAInverse) {
    int block;
    for (int i = 0; i < strlen(message); i++) {
        block = message[i];
        message[i] = (keyAInverse * (block - keyB)) % 256; // Affine decryption
        message[i] ^= iv; // XOR with IV
        iv = block; // Update IV
    }
}

int modularInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

int main() {
    char message[128];
    int keyA = 5, keyB = 8, iv = 101; // Example keys and IV
    int keyAInverse = modularInverse(keyA, 256);

    printf("Enter plaintext: ");
    scanf("%s", message);

    printf("Original message: %s\n", message);
    encryptAffineCBC(message, keyA, keyB, iv);
    printf("Encrypted message: %s\n", message);

    decryptAffineCBC(message, keyA, keyB, iv, keyAInverse);
    printf("Decrypted message: %s\n", message);

    return 0;
}
