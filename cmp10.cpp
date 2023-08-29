#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a Quadruple
struct Quadruple {
    char oper[10];
    char operand1[10];
    char operand2[10];
    char result[10];
};

int main() {
    // Create an array to store quadruples
    struct Quadruple quadruples[100];
    int count = 0; // Keep track of the number of quadruples

    // Example quadruples
    strcpy(quadruples[count].oper, "+");
    strcpy(quadruples[count].operand1, "a");
    strcpy(quadruples[count].operand2, "b");
    strcpy(quadruples[count].result, "temp1");
    count++;

    strcpy(quadruples[count].oper, "*");
    strcpy(quadruples[count].operand1, "temp1");
    strcpy(quadruples[count].operand2, "c");
    strcpy(quadruples[count].result, "temp2");
    count++;

    // Print the quadruples
    printf("Quadruples:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s %s %s %s\n", i + 1, quadruples[i].oper, quadruples[i].operand1,
               quadruples[i].operand2, quadruples[i].result);
    }

    return 0;
}

