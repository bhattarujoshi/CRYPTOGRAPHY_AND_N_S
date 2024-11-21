#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100
void caesarEncrypt(char text[], int shift) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char base;
            if (isupper(text[i])) 
                base = 'A';
            else 
                base = 'a';

            text[i] = ((text[i] - base + shift) % 26) + base;
        }
    }
}
void caesarDecrypt(char text[], int shift) {
    caesarEncrypt(text, 26 - shift);
}
int main() {
    char text[MAX_LENGTH];
    int shift;
    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline character
    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);
    printf("Original Text: %s\n", text);
    caesarEncrypt(text, shift);
    printf("Encrypted Text: %s\n", text);
    caesarDecrypt(text, shift);
    printf("Decrypted Text: %s\n", text);
    return 0;
}