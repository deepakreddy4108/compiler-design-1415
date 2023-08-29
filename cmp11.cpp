#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a Triple
struct Triple {
    char oper[10];
    char operand1[10];
    char operand2[10];
};

int main() {
    // Create an array to store triples
    struct Triple triples[100];
    int count = 0; // Keep track of the number of triples

    // Example triples
    strcpy(triples[count].oper, "+");
    strcpy(triples[count].operand1, "a");
    strcpy(triples[count].operand2, "b");
    count++;

    strcpy(triples[count].oper, "*");
    strcpy(triples[count].operand1, "c");
    strcpy(triples[count].operand2, "d");
    count++;

    // Print the triples
    printf("Triples:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s %s %s\n", i + 1, triples[i].oper, triples[i].operand1,
               triples[i].operand2);
    }

    return 0;
}

