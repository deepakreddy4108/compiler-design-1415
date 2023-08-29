#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure to hold symbol table entry
struct SymbolEntry {
    char name[50];
    int value;
    struct SymbolEntry* next;
};

// Symbol table (linked list)
struct SymbolEntry* symbolTable = NULL;

// Function to insert a new entry into the symbol table
void insertEntry(char name[], int value) {
    struct SymbolEntry* newEntry = (struct SymbolEntry*)malloc(sizeof(struct SymbolEntry));
    strcpy(newEntry->name, name);
    newEntry->value = value;
    newEntry->next = symbolTable;
    symbolTable = newEntry;
}

// Function to search for an entry in the symbol table
struct SymbolEntry* searchEntry(char name[]) {
    struct SymbolEntry* current = symbolTable;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete an entry from the symbol table
void deleteEntry(char name[]) {
    if (symbolTable == NULL)
        return;

    if (strcmp(symbolTable->name, name) == 0) {
        struct SymbolEntry* temp = symbolTable;
        symbolTable = symbolTable->next;
        free(temp);
        return;
    }

    struct SymbolEntry* prev = symbolTable;
    struct SymbolEntry* current = symbolTable->next;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            prev->next = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Function to display the symbol table
void displaySymbolTable() {
    struct SymbolEntry* current = symbolTable;
    printf("Symbol Table:\n");
    while (current != NULL) {
        printf("%s = %d\n", current->name, current->value);
        current = current->next;
    }
}

int main() {
    insertEntry("x", 10);
    insertEntry("y", 20);
    insertEntry("z", 30);

    displaySymbolTable();

    struct SymbolEntry* searchResult = searchEntry("y");
    if (searchResult != NULL) {
        printf("Found: %s = %d\n", searchResult->name, searchResult->value);
    } else {
        printf("Not found\n");
    }

    deleteEntry("y");
    displaySymbolTable();

    return 0;
}
