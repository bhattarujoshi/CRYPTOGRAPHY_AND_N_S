#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 8

void xor_blocks(uint8_t *a, uint8_t *b, uint8_t *result) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        result[i] = a[i] ^ b[i];
    }
}

void encrypt_block(uint8_t *input, uint8_t *output, uint8_t *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        output[i] = input[i] ^ key[i]; // Simple XOR encryption
    }
}

int main() {
    uint8_t plaintext[BLOCK_SIZE] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};
    uint8_t key[BLOCK_SIZE] = {0x10, 0x32, 0x54, 0x76, 0x98, 0xBA, 0xDC, 0xFE};
    uint8_t iv[BLOCK_SIZE] = {0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA, 0x99, 0x88};
    uint8_t ciphertext[BLOCK_SIZE], temp[BLOCK_SIZE];

    // CBC Mode Example
    xor_blocks(plaintext, iv, temp);
    encrypt_block(temp, ciphertext, key);

    printf("Ciphertext (CBC): ");
    for (int i = 0; i < BLOCK_SIZE; i++) printf("%02X ", ciphertext[i]);
    printf("\n");

    return 0;
}
