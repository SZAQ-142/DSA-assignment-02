#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int customer_no;
    struct Node* next_customer;
};
struct Node* head=NULL;

void add_customer(int customer_no){
    struct Node* customer=(struct Node*)malloc(sizeof(struct Node));
    customer->customer_no=customer_no;
    customer->next_customer=NULL;
    if(head==NULL){
        head=customer;
    }else{
        struct Node* temp=head;
        while(temp->next_customer != NULL){
            temp=temp->next_customer;
        }
        temp->next_customer=customer;
    }
}
void delete_customer(){
    if (head == NULL) {
        printf("No customers to delete.\n");
    }
    struct Node* current=head;
    struct Node* previous=NULL;
    while(current->next_customer != NULL){
        previous=current;
        current=current->next_customer;
    }
    if (previous == NULL) {
        // Deleting the first customer
        head = NULL;
    } else {
        previous->next_customer = NULL;
    }

    free(current);
}
// Function to find and print the middle customer(s)
void findAndPrintMiddleCustomer() {
    if (head == NULL) {
        printf("No customers in the list.\n");
        return;
    }

    struct Node *p = head;
    struct Node *q = head;

    while (q != NULL && q->next_customer != NULL) {
        p = p->next_customer;
        q = q->next_customer->next_customer;
    }

    if (q == NULL) {
        // Even number of customers, print the two middle customers
        printf("Middle Customers: %d, %d\n", p->customer_no, p->next_customer->customer_no);
    } else {
        // Odd number of customers, print the middle customer
        printf("Middle Customer: %d\n", p->customer_no);
    }
}
// Function to free memory allocated for customers
void freeCustomers() {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next_customer;
        free(temp);
    }
}

int main()
{
    FILE* fptr;
    int number;
    fptr=fopen("ese3.txt","r");
        if (fptr == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    char line[100]; // Assuming each line has at most 100 characters
    while (fscanf(fptr, "%s", line) != EOF) {
        if(strcmp(line, "ADD")==0){
            fscanf(fptr, "%d",&number);
            add_customer(number);
        }else if(strcmp(line, "DELETE")==0){
            delete_customer();
        }else if(strcmp(line, "END")==0){
            break;
        }else{
            printf("Invalid command:\n");
        }
    }
    fclose(fptr);
     // Find and print the middle customer(s)
    findAndPrintMiddleCustomer();

    // Free memory allocated for customers
    freeCustomers();

    return 0;
}