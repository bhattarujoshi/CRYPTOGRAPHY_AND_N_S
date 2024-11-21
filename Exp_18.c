#include <stdio.h>

void generate_subkeys(const unsigned long initial_key, unsigned long subkeys[16]) {
    for (int i = 0; i < 16; i++) {
        subkeys[i] = (initial_key >> i) & 0xFFFFFF; // Mock logic for demonstration
    }
}

int main() {
    unsigned long initial_key;
    unsigned long subkeys[16];

    printf("Enter the initial 28-bit key: ");
    scanf("%lu", &initial_key);

    generate_subkeys(initial_key, subkeys);

    printf("Generated subkeys:\n");
    for (int i = 0; i < 16; i++) {
        printf("Subkey %d: %lu\n", i + 1, subkeys[i]);
    }

    return 0;
}
