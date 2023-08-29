#include <stdio.h>
#include <string.h>

#define NUM_NON_TERMINALS 3
#define NUM_TERMINALS 2

// Production rules of the grammar
char productions[NUM_NON_TERMINALS][NUM_TERMINALS][20] = {
    {"E", "E+T"},
    {"E", "T"},
    {"T", "T*F"},
    {"T", "F"},
    {"F", "(E)"},
    {"F", "id"}
};

// Non-terminals and terminals
char nonTerminals[NUM_NON_TERMINALS] = {'E', 'T', 'F'};
char terminals[NUM_TERMINALS] = {'+', '*'};

// Parsing table
char parsingTable[NUM_NON_TERMINALS][NUM_TERMINALS][20];

// Initialize the parsing table
void initializeParsingTable() {
    for (int i = 0; i < NUM_NON_TERMINALS; i++) {
        for (int j = 0; j < NUM_TERMINALS; j++) {
            strcpy(parsingTable[i][j], "");
        }
    }
}

// Fill the parsing table based on production rules
void fillParsingTable() {
    for (int i = 0; i < NUM_NON_TERMINALS; i++) {
        for (int j = 0; j < NUM_TERMINALS; j++) {
            for (int k = 0; k < 6; k++) {
                if (strchr(productions[k][1], nonTerminals[i]) != NULL &&
                    strchr(productions[k][1], terminals[j]) != NULL) {
                    strcat(parsingTable[i][j], productions[k][1]);
                }
            }
        }
    }
}

int main() {
    initializeParsingTable();
    fillParsingTable();

    printf("Predictive Parsing Table:\n");
    printf("  +   *   id\n");
    for (int i = 0; i < NUM_NON_TERMINALS; i++) {
        printf("%c ", nonTerminals[i]);
        for (int j = 0; j < NUM_TERMINALS; j++) {
            printf("%s ", parsingTable[i][j]);
        }
        printf("\n");
    }

    return 0;
}

