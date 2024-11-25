#include <stdio.h>
#include <string.h>

void padMessage(char *message, int blockSize) {
    int len = strlen(message);
    int padding = blockSize - (len % blockSize);
    for (int i = 0; i < padding; i++) {
        message[len + i] = (padding == 1) ? '1' : '0';
    }
    message[len + padding] = '\0';
}

int main() {
    char plaintext[128];
    int blockSize = 8;

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    printf("Original plaintext: %s\n", plaintext);
    padMessage(plaintext, blockSize);

    printf("Padded plaintext: %s\n", plaintext);
    printf("Padding ensures that block encryption works seamlessly.\n");

    return 0;
}
