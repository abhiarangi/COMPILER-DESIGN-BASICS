#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

const char *keywords[] = {"int", "float", "if", "else", "while", "return"};
const int numKeywords = 6;

// Function to check if a string is a keyword
int isKeyword(const char *word) {
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Lexical analyzer logic using states
void lexicalAnalyze(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file %s.\n", filename);
        return;
    }

    char ch, buffer[MAX];
    int state = 0, index = 0;

    printf("Tokens found in file %s:\n", filename);
    while ((ch = fgetc(file)) != EOF) {
        switch (state) {
        case 0: // Initial state
            if (isalpha(ch)) { // Start of an identifier/keyword
                state = 1;
                buffer[index++] = ch;
            } else if (isdigit(ch)) { // Start of a numeric constant
                state = 2;
                buffer[index++] = ch;
            } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '>' || ch == '<') {
                state = 3; // Operator
                buffer[index++] = ch;
            } else if (isspace(ch) || ch == ',' || ch == ';') {
                state = 0; // Ignoring separators
            }
            break;

        case 1: // Building an identifier/keyword
            if (isalnum(ch)) {
                buffer[index++] = ch;
            } else {
                buffer[index] = '\0';
                index = 0;
                if (isKeyword(buffer)) {
                    printf("Keyword: %s\n", buffer);
                } else {
                    printf("Identifier: %s\n", buffer);
                }
                state = 0; // Return to initial state
                ungetc(ch, file); // Reprocess the character
            }
            break;

        case 2: // Building a numeric constant
            if (isdigit(ch)) {
                buffer[index++] = ch;
            } else {
                buffer[index] = '\0';
                printf("Numeric Constant: %s\n", buffer);
                index = 0;
                state = 0; // Return to initial state
                ungetc(ch, file); // Reprocess the character
            }
            break;

        case 3: // Operator handling
            buffer[index] = '\0';
            printf("Operator: %s\n", buffer);
            index = 0;
            state = 0; // Return to initial state
            ungetc(ch, file); // Reprocess the character
            break;
        }
    }

    fclose(file);
}

int main() {
    char filename[MAX];

    printf("Enter the name of the file to analyze: ");
    scanf("%s", filename);

    lexicalAnalyze(filename);

    return 0;
}
