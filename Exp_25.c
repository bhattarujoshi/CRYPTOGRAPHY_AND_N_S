#include <stdio.h>

// Function to calculate gcd using the Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Example RSA modulus
    int n = 61 * 53; // n = p * q, where p = 61, q = 53
    int plaintextBlock = 53; // Example plaintext block with a common factor with n

    printf("RSA Modulus (n): %d\n", n);
    printf("Plaintext block: %d\n", plaintextBlock);

    // Compute gcd(plaintextBlock, n)
    int factor = gcd(plaintextBlock, n);

    if (factor > 1) {
        printf("Found a factor of n: %d\n", factor);
        printf("The other factor is: %d\n", n / factor);
    } else {
        printf("No factor of n found with the given plaintext block.\n");
    }

    return 0;
}
