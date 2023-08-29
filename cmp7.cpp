#include <stdio.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_SYMBOLS 10

char nonTerminal;
char rules[MAX_RULES][MAX_SYMBOLS];
int numRules;

void eliminateLeftRecursion() {
    for (int i = 0; i < numRules; i++) {
        if (rules[i][0] == nonTerminal) {
            for (int j = 0; j < numRules; j++) {
                if (rules[j][0] != nonTerminal) {
                    printf("%c -> %s%c'\n", nonTerminal, &rules[j][1], nonTerminal);
                    printf("%c' -> %s%c' | e\n", nonTerminal, &rules[i][1], nonTerminal);
                }
            }
            return;
        }
    }
    printf("No left recursion found for %c\n", nonTerminal);
}

int main() {
    printf("Enter the non-terminal: ");
    scanf("%c", &nonTerminal);

    printf("Enter the number of rules: ");
    scanf("%d", &numRules);

    printf("Enter the rules:\n");
    for (int i = 0; i < numRules; i++) {
        scanf("%s", rules[i]);
    }

    eliminateLeftRecursion();

    return 0;
}
