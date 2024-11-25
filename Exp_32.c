#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MODULUS_P 23 // Example prime modulus (use a real large prime in practice)
#define MODULUS_Q 11 // Another prime modulus (must divide P-1)
#define GENERATOR_G 2 // Example generator

unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
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

unsigned long long mod_inverse(unsigned long long a, unsigned long long m) {
    for (unsigned long long x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 0; // No modular inverse found
}

void dsa_keygen(unsigned long long *private_key, unsigned long long *public_key) {
    *private_key = rand() % (MODULUS_Q - 1) + 1; // Private key x (1 < x < q)
    *public_key = mod_exp(GENERATOR_G, *private_key, MODULUS_P); // Public key y = g^x mod p
}

void dsa_sign(unsigned long long hash, unsigned long long private_key, unsigned long long *r, unsigned long long *s) {
    unsigned long long k, k_inv;

    // Generate a random k (1 < k < q)
    do {
        k = rand() % (MODULUS_Q - 1) + 1;
    } while ((k_inv = mod_inverse(k, MODULUS_Q)) == 0);

    *r = mod_exp(GENERATOR_G, k, MODULUS_P) % MODULUS_Q; // r = (g^k mod p) mod q
    *s = (k_inv * (hash + private_key * (*r))) % MODULUS_Q; // s = (k^(-1) * (H(m) + x * r)) mod q
}

int dsa_verify(unsigned long long hash, unsigned long long r, unsigned long long s, unsigned long long public_key) {
    if (r <= 0 || r >= MODULUS_Q || s <= 0 || s >= MODULUS_Q) {
        return 0; // Invalid signature
    }

    unsigned long long w = mod_inverse(s, MODULUS_Q); // w = s^(-1) mod q
    unsigned long long u1 = (hash * w) % MODULUS_Q;
    unsigned long long u2 = (r * w) % MODULUS_Q;
    unsigned long long v = ((mod_exp(GENERATOR_G, u1, MODULUS_P) * mod_exp(public_key, u2, MODULUS_P)) % MODULUS_P) % MODULUS_Q;

    return v == r;
}

int main() {
    srand(time(0)); // Seed random number generator

    unsigned long long private_key, public_key;
    unsigned long long hash = 9; // Example hash of the message
    unsigned long long r, s;

    // Key generation
    dsa_keygen(&private_key, &public_key);
    printf("Private Key (x): %llu\n", private_key);
    printf("Public Key (y): %llu\n", public_key);

    // Signing the hash
    dsa_sign(hash, private_key, &r, &s);
    printf("Signature: r = %llu, s = %llu\n", r, s);

    // Verifying the signature
    if (dsa_verify(hash, r, s, public_key)) {
        printf("Signature is valid.\n");
    } else {
        printf("Signature is invalid.\n");
    }

    return 0;
}
