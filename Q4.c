#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;

struct Node* cursor=NULL;

// Function to add a number to the end of the list
void addNumber(int number) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = number;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        cursor = head;
    }
    else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

}
// Function to delete the tail of the list
void deleteTail() {
    if (head == NULL) {
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        cursor = NULL;
    }
    else {
        struct Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
}
// Function to move the cursor forward by a given number of steps
void moveCursorForward(int steps) {
    if (cursor == NULL) {
        return;
    }

    for (int i = 0; i < steps; i++) {
        if (cursor->next != NULL) {
            cursor = cursor->next;
        }
        else {
            break;
        }
    }
}

// Function to move the cursor backward by a given number of steps
void moveCursorBackward(int steps) {
    if (cursor == NULL) {
        return;
    }

    for (int i = 0; i < steps; i++) {
        struct Node* prev = head;
        while (prev->next != cursor) {
            prev = prev->next;
        }
        cursor = prev;
    }
}

// Function to print the data at the cursor's node
void printData() {
    if (cursor != NULL) {
        printf("Cursor Data: %d\n", cursor->data);
    }
}


int main()
{
    FILE* fptr;
    fptr=fopen("TEST1.txt","r");
    if(fptr==NULL){
        printf("File doesn't exists:");
        return 1;
    }
    char command[50];
    int number,steps;
     while (fscanf(fptr, "%s", command) != EOF) {
        if (strcmp(command, "Add") == 0) {
            fscanf(fptr, "%d", &number);
            addNumber(number);
        }
        else if (strcmp(command, "Delete") == 0) {
            deleteTail();
        }
        else if (strcmp(command, "MoveForward") == 0) {
            fscanf(fptr, "%d", &steps);
            moveCursorForward(steps);
        }
        else if (strcmp(command, "MoveBackward") == 0) {
            fscanf(fptr, "%d", &steps);
            moveCursorBackward(steps);
        }
        else if (strcmp(command, "Print") == 0) {
            printData();
        }
        
    }

    fclose(fptr);

    // Clean up the linked list
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}