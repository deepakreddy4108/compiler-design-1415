#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to check if a given grammar rule is ambiguous
bool isAmbiguousGrammar(char* grammarRule) {
    int length = strlen(grammarRule);
    for (int i = 0; i < length - 2; i++) {
        if (grammarRule[i] == 'i' && grammarRule[i + 1] == 'f' && grammarRule[i + 2] == 'E') {
            return true;
        }
    }
    return false;
}

int main() {
    char grammar[MAX_LENGTH];

    // Input a grammar rule
    printf("Enter a grammar rule: ");
    fgets(grammar, sizeof(grammar), stdin);

    // Check for ambiguity
    if (isAmbiguousGrammar(grammar)) {
        printf("The grammar is ambiguous (dangling else ambiguity).\n");
    } else {
        printf("The grammar is not ambiguous.\n");
    }

    return 0;
}

