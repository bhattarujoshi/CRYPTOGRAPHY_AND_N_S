#include <stdio.h>
#include <math.h>

// Function to compute (base^exp) % mod
int modularExponentiation(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Extended Euclidean Algorithm to find modular inverse
int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int modularInverse(int a, int m) {
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    return (x % m + m) % m;
}

int main() {
    int p = 61, q = 59;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 31; // Public key exponent
    int d = modularInverse(e, phi); // Private key

    int plaintext = 65; // Example plaintext
    int ciphertext = modularExponentiation(plaintext, e, n);
    int decryptedText = modularExponentiation(ciphertext, d, n);

    printf("Plaintext: %d\n", plaintext);
    printf("Ciphertext: %d\n", ciphertext);
    printf("Decrypted text: %d\n", decryptedText);

    return 0;
}
