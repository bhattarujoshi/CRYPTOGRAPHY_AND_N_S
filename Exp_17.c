#include <stdio.h>
#include <string.h>

// Use `unsigned long long` for 64-bit integers
unsigned long long keys[16] = {
    0x133457799BBCDFF1, 0x1A2B3C4D5E6F7081, 0x1234567890ABCDE2, 0xFEDCBA9876543213,
    0xA1B2C3D4E5F60718, 0x87654321ABCDEF19, 0xDEADBEEFCAFEBABE, 0x0F1E2D3C4B5A697A,
    0x1111111111111111, 0x2222222222222222, 0x3333333333333333, 0x4444444444444444,
    0x5555555555555555, 0x6666666666666666, 0x7777777777777777, 0x8888888888888888
};

// Function to reverse the key schedule for decryption
void generate_reverse_keys(unsigned long long original_keys[16], unsigned long long reversed_keys[16]) {
    for (int i = 0; i < 16; i++) {
        reversed_keys[i] = original_keys[15 - i];
    }
}

// Mock DES decryption function (for demonstration)
void des_decrypt(const char *ciphertext, char *plaintext, unsigned long long reversed_keys[16]) {
    printf("Using reversed keys for decryption:\n");
    for (int i = 0; i < 16; i++) {
        printf("Key %d: %016llx\n", i + 1, reversed_keys[i]); // Use %llx for 64-bit hex values
    }

    // In a real DES implementation, you would use the reversed keys here
    // For now, this is a placeholder that simply copies the ciphertext to plaintext
    strcpy(plaintext, ciphertext);
}

int main() {
    char ciphertext[1024], plaintext[1024];
    unsigned long long reversed_keys[16];

    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    ciphertext[strcspn(ciphertext, "\n")] = '\0'; // Remove newline character

    // Generate reversed keys for decryption
    generate_reverse_keys(keys, reversed_keys);

    // Perform decryption
    des_decrypt(ciphertext, plaintext, reversed_keys);

    // Print the decrypted plaintext
    printf("Decrypted text: %s\n", plaintext);

    return 0;
}
