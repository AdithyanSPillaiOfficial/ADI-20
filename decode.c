#include <stdio.h>
#include <string.h>
#define MAX 10000

int main() {
    char userinp[MAX], key[MAX];
    int inplen, keylength;

    printf("Please enter the string to decrypt: ");
    //scanf("%s", userinp);
    gets(userinp);

    inplen = (int) strlen(userinp);

    printf("Enter the key used for encryption: ");
    //scanf("%s", key);
    gets(key);

    keylength = (int) strlen(key);

    char splitmat[inplen / keylength + 1][keylength];
    int ptr = 0;

    // Fill the matrix
    for (int i = 0; i < (inplen / keylength + 1); i++) {
        for (int j = 0; j < keylength && ptr < inplen; j++) {
            splitmat[i][j] = userinp[ptr];
            ptr++;
        }
    }

    // Decrypt the matrix
    for (int i = 0; i < (inplen / keylength + 1); i++) {
        for (int j = 0; j < keylength && i * keylength + j < inplen; j++) {
            int asciicode = (int) splitmat[i][j];
            asciicode -= ((int) key[j] - '0');
            splitmat[i][j] = (char) asciicode;
        }
    }

    printf("Decrypted String: ");
    // Print the decrypted string
    for (int i = 0; i < (inplen / keylength + 1); i++) {
        for (int j = 0; j < keylength && i * keylength + j < inplen; j++) {
            printf("%c", splitmat[i][j]);
        }
    }
    printf("\n");

    return 0;
}
