#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Function to calculate the modular multiplicative inverse
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to count the frequency of each letter in the ciphertext
void count_frequency(const char *text, int *freq) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            freq[text[i] - 'A']++;
    }
}

// Function to find the most frequent character in the frequency array
int find_most_frequent(const int *freq) {
    int max_freq_index = 0;
    for (int i = 1; i < ALPHABET_SIZE; i++) {
        if (freq[i] > freq[max_freq_index]) {
            max_freq_index = i;
        }
    }
    return max_freq_index;
}

int main() {
    char ciphertext[1000];
    int freq[ALPHABET_SIZE] = {0};
    int most_freq_index;
    int b_index = 'B' - 'A'; // Assuming 'B' is the most frequent character in plaintext
    int a, b;

    printf("Enter the ciphertext (uppercase letters only): ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = '\0';

    // Count letter frequencies in the ciphertext
    count_frequency(ciphertext, freq);

    // Find the most frequent character in the ciphertext
    most_freq_index = find_most_frequent(freq);

    // Calculate the 'a' value using modular arithmetic
    int diff = most_freq_index - b_index;
    if (diff < 0)
        diff += ALPHABET_SIZE;

    a = mod_inverse(diff, ALPHABET_SIZE);
    if (a == 0) {
        printf("No valid modular inverse found. Decryption not possible.\n");
        return 1;
    }

    // Calculate 'b' value
    b = (b_index - a * most_freq_index) % ALPHABET_SIZE;
    if (b < 0)
        b += ALPHABET_SIZE;

    // Print the deciphered text
    printf("Deciphered text:\n");
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int decrypted_char = (mod_inverse(a, ALPHABET_SIZE) * ((ciphertext[i] - 'A') - b)) % ALPHABET_SIZE;
            if (decrypted_char < 0)
                decrypted_char += ALPHABET_SIZE;
            printf("%c", decrypted_char + 'A');
        } else {
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");

    return 0;
}