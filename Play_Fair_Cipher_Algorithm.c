#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to prepare the key matrix
void prepareMatrix(char key[], char keyMatrix[5][5]) {
    int alphabet[26] = {0};
    int i, j, k, index = 0;
    
    // Fill the key into the matrix, marking used characters
    for (k = 0; k < strlen(key); k++) {
        if (key[k] != 'j' && key[k] != 'J' && !alphabet[toupper(key[k]) - 'A']) {
            keyMatrix[index / 5][index % 5] = toupper(key[k]);
            alphabet[toupper(key[k]) - 'A'] = 1;
            index++;
        }
    }
    
    // Fill remaining alphabet characters
    for (i = 0; i < 26; i++) {
        if (i != 9 && !alphabet[i]) { // Skip 'J'
            keyMatrix[index / 5][index % 5] = 'A' + i;
            index++;
        }
    }
}

// Function to search the position of characters in the key matrix
void search(char keyMatrix[5][5], char a, char b, int pos[]) {
    int i, j;

    // Search for the positions of 'a' and 'b'
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (keyMatrix[i][j] == a) {
                pos[0] = i;
                pos[1] = j;
            } else if (keyMatrix[i][j] == b) {
                pos[2] = i;
                pos[3] = j;
            }
        }
    }
}

// Function to encrypt the plaintext
void encrypt(char plaintext[], char keyMatrix[5][5], char ciphertext[]) {
    int length = strlen(plaintext);
    int pos[4];
    int i, j = 0;

    // Process each pair of characters
    for (i = 0; i < length; i += 2) 
    {
        if (i + 1 == length || plaintext[i] == plaintext[i + 1]) 
        {
            // Add a filler 'X' if last character or if characters are the same
            plaintext[length + 1] = '\0';
            plaintext[length] = 'X';
            length++;
        }
        search(keyMatrix, toupper(plaintext[i]), toupper(plaintext[i + 1]), pos);

        // Apply Playfair cipher rules
        if (pos[0] == pos[2]) 
        {
            // Same row
            ciphertext[j++] = keyMatrix[pos[0]][(pos[1] + 1) % 5];
            ciphertext[j++] = keyMatrix[pos[2]][(pos[3] + 1) % 5];
        } 
        else if (pos[1] == pos[3]) 
        {
            // Same column
            ciphertext[j++] = keyMatrix[(pos[0] + 1) % 5][pos[1]];
            ciphertext[j++] = keyMatrix[(pos[2] + 1) % 5][pos[3]];
        } 
        else 
        {
            // Rectangle swap
            ciphertext[j++] = keyMatrix[pos[0]][pos[3]];
            ciphertext[j++] = keyMatrix[pos[2]][pos[1]];
        }
    }
    ciphertext[j] = '\0';
}

int main() {
    char key[100], plaintext[100], ciphertext[100];
    char keyMatrix[5][5];

    // Input key and plaintext
    printf("Enter key: ");
    gets(key);
    printf("Enter plaintext: ");
    gets(plaintext);

    // Prepare the key matrix
    prepareMatrix(key, keyMatrix);

    // Encrypt the plaintext
    encrypt(plaintext, keyMatrix, ciphertext);

    // Output the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
