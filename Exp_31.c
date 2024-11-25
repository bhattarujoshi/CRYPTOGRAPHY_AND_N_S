#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 16 // 128 bits for CMAC
#define R_128 0x87    // Polynomial for 128-bit CMAC

void left_shift_xor(uint8_t *input, uint8_t *output, uint8_t xor_constant) {
    uint8_t carry = 0;
    for (int i = BLOCK_SIZE - 1; i >= 0; i--) {
        uint8_t temp = input[i];
        output[i] = (temp << 1) | carry;
        carry = (temp & 0x80) ? 1 : 0; // Check MSB
    }
    if (carry) {
        output[BLOCK_SIZE - 1] ^= xor_constant;
    }
}

void AES_encrypt(const uint8_t *input, uint8_t *output, const uint8_t *key) {
    // Mock AES encryption: Just copy input to output for demonstration.
    memcpy(output, input, BLOCK_SIZE);
}

int main() {
    uint8_t key[BLOCK_SIZE] = {0};
    uint8_t zero_block[BLOCK_SIZE] = {0};
    uint8_t L[BLOCK_SIZE], K1[BLOCK_SIZE], K2[BLOCK_SIZE];

    AES_encrypt(zero_block, L, key);
    left_shift_xor(L, K1, R_128);
    left_shift_xor(K1, K2, R_128);

    printf("L:  ");
    for (int i = 0; i < BLOCK_SIZE; i++) printf("%02X ", L[i]);
    printf("\nK1: ");
    for (int i = 0; i < BLOCK_SIZE; i++) printf("%02X ", K1[i]);
    printf("\nK2: ");
    for (int i = 0; i < BLOCK_SIZE; i++) printf("%02X ", K2[i]);
    printf("\n");
    return 0;
}
