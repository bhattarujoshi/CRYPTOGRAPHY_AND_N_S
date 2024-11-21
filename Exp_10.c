#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100
void formatPlaintext(char *plaintext, char *formattedText) {
    int len = strlen(plaintext);
    int i, j = 0;

    for (i = 0; i < len; i++) {
        if (plaintext[i] == ' ') continue;
        formattedText[j++] = toupper((unsigned char)plaintext[i]);
        if (i + 1 < len && plaintext[i] == plaintext[i + 1]) {
            formattedText[j++] = 'X';
        }
    }
    if (j % 2 != 0) {
        formattedText[j++] = 'X';
    }
    formattedText[j] = '\0';
}
void encodePlayfair(char *plaintext) {
    char key[5][5] = {
        {'M', 'O', 'N', 'A', 'R'},
        {'C', 'H', 'Y', 'B', 'D'},
        {'E', 'F', 'G', 'I', 'K'},
        {'L', 'P', 'Q', 'S', 'T'},
        {'U', 'V', 'W', 'X', 'Z'}
    };   
    int i, j;
    char formattedText[MAX_LENGTH];
    formatPlaintext(plaintext, formattedText); 
    for (i = 0; i < strlen(formattedText); i += 2) {
        char first = formattedText[i];
        char second = formattedText[i + 1];
        int row1 = -1, col1 = -1, row2 = -1, col2 = -1;
        for (j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (key[j][k] == first) {
                    row1 = j;
                    col1 = k;
                }
                if (key[j][k] == second) {
                    row2 = j;
                    col2 = k;
                }
            }
        }
        if (row1 == row2) {
            printf("%c%c", key[row1][(col1 + 1) % 5], key[row2][(col2 + 1) % 5]);
        } else if (col1 == col2) {
            printf("%c%c", key[(row1 + 1) % 5][col1], key[(row2 + 1) % 5][col2]);
        } else {
            printf("%c%c", key[row1][col2], key[row2][col1]);
        }
    }
    printf("\n");
}
int main() {
    char plaintext[MAX_LENGTH] = " Must see you over Cadogan West. Coming at once";
    printf("Encoded Message: ");
    encodePlayfair(plaintext);   
    return 0;
}