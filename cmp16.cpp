#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an expression
struct Expression {
    char op;
    char operand1[10];
    char operand2[10];
    char result[10];
};

// Function to check if two expressions are the same
int areExpressionsEqual(struct Expression exp1, struct Expression exp2) {
    return (exp1.op == exp2.op &&
            strcmp(exp1.operand1, exp2.operand1) == 0 &&
            strcmp(exp1.operand2, exp2.operand2) == 0);
}

int main() {
    struct Expression expressions[100];
    int count = 0; // Keep track of the number of expressions

    // Example expressions
    strcpy(expressions[count].operand1, "a");
    strcpy(expressions[count].operand2, "b");
    strcpy(expressions[count].result, "temp1");
    expressions[count].op = '+';
    count++;

    strcpy(expressions[count].operand1, "a");
    strcpy(expressions[count].operand2, "b");
    strcpy(expressions[count].result, "temp2");
    expressions[count].op = '*';
    count++;

    // Initialize a flag array to keep track of common subexpressions
    int isCommon[100] = {0};

    // Eliminate common subexpressions
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (!isCommon[j] && areExpressionsEqual(expressions[i], expressions[j])) {
                isCommon[j] = 1;
                strcpy(expressions[j].result, expressions[i].result);
            }
        }
    }

    // Print the expressions after eliminating common subexpressions
    printf("Expressions after eliminating common subexpressions:\n");
    for (int i = 0; i < count; i++) {
        if (!isCommon[i]) {
            printf("%s = %s %c %s\n", expressions[i].result, expressions[i].operand1,
                   expressions[i].op, expressions[i].operand2);
        }
    }

    return 0;
}

