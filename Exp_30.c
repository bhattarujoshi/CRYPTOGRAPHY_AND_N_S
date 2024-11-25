#include <stdio.h>

// Function to compute XOR
int XOR(int a, int b) {
    return a ^ b;
}

// Function to compute CBC-MAC
int computeCBCMAC(int message[], int key, int size) {
    int mac = 0;
    for (int i = 0; i < size; i++) {
        mac = XOR(mac, message[i]);
        mac = XOR(mac, key);
    }
    return mac;
}

int main() {
    int message1[] = {1}; // Example one-block message
    int message2[] = {1, 2}; // Two-block message
    int key = 42; // Example key

    int mac1 = computeCBCMAC(message1, key, 1);
    int mac2 = computeCBCMAC(message2, key, 2);

    printf("CBC-MAC for single block: %d\n", mac1);
    printf("CBC-MAC for two blocks: %d\n", mac2);

    return 0;
}
