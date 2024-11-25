#include <stdio.h>

// Function to calculate GCD using the Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute modular inverse using the Extended Euclidean Algorithm
int modInverse(int e, int phi) {
    for (int d = 1; d < phi; d++) {
        if ((e * d) % phi == 1) {
            return d;
        }
    }
    return -1;
}

// Function for modular exponentiation
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
    // RSA setup
    int p = 61, q = 53; // Prime numbers
    int n = p * q;      // Modulus
    int phi = (p - 1) * (q - 1); // Euler's totient function

    // Public key (e)
    int e = 17; // Choose e such that gcd(e, phi) = 1

    // Private key (d)
    int d = modInverse(e, phi);

    // Display keys
    printf("Public Key: (e = %d, n = %d)\n", e, n);
    printf("Private Key: (d = %d, n = %d)\n", d, n);

    // Encryption
    int plaintext = 42; // Example plaintext
    int ciphertext = modExp(plaintext, e, n);
    printf("Ciphertext: %d\n", ciphertext);

    // Decryption
    int decrypted = modExp(ciphertext, d, n);
    printf("Decrypted Text: %d\n", decrypted);

    // Scenario: Private key leakage
    printf("\nIf Bob's private key is leaked, generating a new key is safer if new primes are chosen.\n");

    return 0;
}
