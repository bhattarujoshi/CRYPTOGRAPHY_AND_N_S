#include <stdio.h>
#include <string.h>

#define MATRIX_SIZE 2

// Function to perform matrix multiplication for encryption
void matrix_multiply(int key[MATRIX_SIZE][MATRIX_SIZE], int input[], int output[]) {
    output[0] = (key[0][0] * input[0] + key[0][1] * input[1]) % 26;
    output[1] = (key[1][0] * input[0] + key[1][1] * input[1]) % 26;
}

// Function to encrypt the plaintext
void hill_encrypt(char *plaintext, int key[MATRIX_SIZE][MATRIX_SIZE]) {
    int input[MATRIX_SIZE], output[MATRIX_SIZE];
    int len = strlen(plaintext);

    // Process plaintext in pairs
    for (int i = 0; i < len; i += 2) {
        input[0] = plaintext[i] - 'a';
        input[1] = plaintext[i + 1] - 'a';

        matrix_multiply(key, input, output);

        // Convert result back to characters
        printf("%c%c", output[0] + 'a', output[1] + 'a');
    }
}

int main() {
    char plaintext[] = "meetmeattheusualplaceattenratherthaneightoclock";
    int key[MATRIX_SIZE][MATRIX_SIZE] = {{9, 4}, {5, 7}};

    printf("Ciphertext: ");
    hill_encrypt(plaintext, key);

    return 0;
}
