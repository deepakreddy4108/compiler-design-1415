#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define the grammar production rules
char* productionRules[] = {
    "E -> E + T",
    "E -> T",
    "T -> T * F",
    "T -> F",
    "F -> ( E )",
    "F -> id"
};

// Define the SLR parsing table
char parsingTable[6][7][10] = {
    // Action table
    { "", "", "S5", "", "S4", "", "" },
    { "S6", "", "", "", "", "", "accept" },
    { "", "", "S5", "", "S4", "", "" },
    { "", "R2", "R2", "S7", "", "R2", "R2" },
    { "", "R4", "R4", "R4", "", "R4", "R4" },
    { "S6", "", "", "", "S11", "", "" },

    // Goto table
    { "1", "2", "", "3", "", "", "" },
    { "", "", "", "", "", "8", "" },
    { "", "", "S10", "", "", "", "9" },
};

// Stack for parsing
char stack[100];
int top = -1;

// Function to push a symbol onto the stack
void push(char symbol) {
    stack[++top] = symbol;
}

// Function to pop a symbol from the stack
char pop() {
    return stack[top--];
}

// Function to perform parsing
bool parse(char* input) {
    push('0'); // Initial state
    int inputIndex = 0;

    while (true) {
        char currentState = stack[top] - '0';
        char currentInput = input[inputIndex];

        // Find the action in the parsing table
        char* action = parsingTable[currentState][currentInput - 'a'];

        if (action[0] == 'S') {
            // Shift operation
            push(currentInput);
            push(action[1]);
            inputIndex++;
        } else if (action[0] == 'R') {
            // Reduce operation
            int ruleIndex = action[1] - '0';
            char* production = productionRules[ruleIndex];

            // Pop symbols based on the length of the production
            int length = strlen(production) - 4;
            for (int i = 0; i < 2 * length; i++) {
                pop();
            }

            // Push the non-terminal symbol and update the state
            char nextState = parsingTable[stack[top] - '0'][production[0] - 'E' + 1][0];
            push(production[0]);
            push(nextState);
        } else if (action[0] == 'a') {
            // Accept the input
            return true;
        } else {
            // Error condition
            return false;
        }
    }
}

int main() {
    char input[100];

    // Input an expression to parse
    printf("Enter an expression to parse: ");
    scanf("%s", input);

    // Add '$' to the end of the input to mark the end
    strcat(input, "$");

    // Perform parsing
    if (parse(input)) {
        printf("Accepted!\n");
    } else {
        printf("Rejected!\n");
    }

    return 0;
}

