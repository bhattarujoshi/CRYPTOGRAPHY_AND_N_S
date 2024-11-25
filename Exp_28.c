#include <stdio.h>
#include <math.h>

// Modular exponentiation
int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int p = 23; // Prime modulus
    int g = 5;  // Primitive root modulo p

    // Private keys (secret)
    int a = 6; // Alice's secret
    int b = 15; // Bob's secret

    // Public keys
    int A = modExp(g, a, p); // g^a mod p
    int B = modExp(g, b, p); // g^b mod p

    printf("Public Key of Alice: %d\n", A);
    printf("Public Key of Bob: %d\n", B);

    // Shared secret
    int aliceShared = modExp(B, a, p); // B^a mod p
    int bobShared = modExp(A, b, p);   // A^b mod p

    printf("Shared Secret (Alice): %d\n", aliceShared);
    printf("Shared Secret (Bob): %d\n", bobShared);

    return 0;
}
