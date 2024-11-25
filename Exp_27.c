#include <stdio.h>

// Modular exponentiation function
int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int p = 61, q = 53; // Prime numbers
    int n = p * q;      // Modulus
    int phi = (p - 1) * (q - 1);
    int e = 17;         // Public key
    int d = 2753;       // Private key (precomputed for this example)

    char message[] = "HELLO"; // Example message
    int encrypted[5];
    int decrypted[5];

    printf("Original Message: %s\n", message);

    // Encrypt each character
    for (int i = 0; i < 5; i++) {
        int m = message[i] - 'A'; // Map A-Z to 0-25
        encrypted[i] = modExp(m, e, n);
        printf("Encrypted[%d]: %d\n", i, encrypted[i]);
    }

    // Decrypt each character
    printf("Decrypted Message: ");
    for (int i = 0; i < 5; i++) {
        int c = encrypted[i];
        decrypted[i] = modExp(c, d, n);
        printf("%c", decrypted[i] + 'A');
    }
    printf("\n");

    return 0;
}
