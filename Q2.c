#include<stdio.h>
#include<stdlib.h>
struct Node{
    int number;
    struct Node* next_number;
};
struct Node* head=NULL;
int count=0;
// Function to insert a number into the linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->number =data;
    newNode->next_number = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next_number != NULL) {
            current = current->next_number;
        }
        current->next_number = newNode;
    }
    count++;
}
//function of calculate median
float calculate_median(){
    struct Node *current = head;
    int mid = count/2;
    if(count%2 == 0){
        for(int i=1;i<mid;i++){
            current = current->next_number;
        }
        float median = (current->number + current->next_number->number)/2.0;
        return median;
    }
    else{
        for(int i=1;i<=mid;i++){
            current = current->next_number;
        }
        return current->number;
    }
}
int main()
{
    FILE *fptr;
    int numbers;
    fptr=fopen("Q3liye.txt","r");
    if(fptr==NULL){
        printf("Error: File does not exists:");
    }
    while(fscanf(fptr, "%d",&numbers)!=EOF){
        insert(&head,numbers);
        float median = calculate_median(head);
        printf("%d Median: %.1f\n", numbers, median);
    }
    fclose(fptr);
    // Free the linked list
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next_number;
        free(temp);
    }
    return 0;
}