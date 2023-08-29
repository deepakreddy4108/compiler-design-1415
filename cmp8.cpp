#include <stdio.h>
#include <ctype.h>

char input[100];
int position = 0;

void E();
void T();
void F();

void error() {
    printf("Error in parsing\n");
}

void match(char expectedToken) {
    if (input[position] == expectedToken) {
        position++;
    } else {
        error();
    }
}

void E() {
    T();
    if (input[position] == '+') {
        match('+');
        E();
    }
}

void T() {
    F();
    if (input[position] == '*') {
        match('*');
        T();
    }
}

void F() {
    if (isdigit(input[position])) {
        match(input[position]);
    } else if (input[position] == '(') {
        match('(');
        E();
        match(')');
    } else {
        error();
    }
}

int main() {
    printf("Enter an expression: ");
    scanf("%s", input);

    E();

    if (input[position] == '\0') {
        printf("Parsing successful!\n");
    } else {
        error();
    }

    return 0;
}
