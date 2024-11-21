#include <stdio.h>
#include <string.h> // Required for strcmp function

void analyze_error_propagation(const char *mode) {
    if (strcmp(mode, "ECB") == 0) {
        printf("Error in ECB mode affects only the corresponding plaintext block.\n");
    } else if (strcmp(mode, "CBC") == 0) {
        printf("Error in CBC mode affects the current block and propagates to the next block.\n");
    } else {
        printf("Invalid mode. Please enter either 'ECB' or 'CBC'.\n");
    }
}

int main() {
    char mode[4]; // To store "ECB" or "CBC"

    printf("Enter the encryption mode (ECB/CBC): ");
    scanf("%3s", mode); // Limit input to 3 characters to prevent buffer overflow

    analyze_error_propagation(mode);

    return 0;
}
