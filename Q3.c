#include<stdio.h>
#include<stdlib.h>
struct Node{
    int transaction_ID;
    int transaction_amount;
    struct Node* next_transaction;
};

struct Node* head_transaction=NULL;

void Add_Transaction(int transaction_ID,int transaction_amount){
    struct Node* new_transaction=(struct Node*)malloc(sizeof(struct Node));
    new_transaction->transaction_ID=transaction_ID;
    new_transaction->transaction_amount=transaction_amount;
    new_transaction->next_transaction=NULL;

    if(head_transaction==NULL){
        head_transaction=new_transaction;
    }else{
        struct Node* curr=head_transaction;
        while(curr->next_transaction != NULL){
            curr=curr->next_transaction;
        }
        curr->next_transaction=new_transaction;

    }

}
void Del_Transaction(int frad_ID){
    struct Node* p=head_transaction;
    struct Node* q=NULL;
    while(p != NULL && p->transaction_ID != frad_ID){
        q=p;
        p=p->next_transaction;
    }
    if (p == NULL) {
        printf("Transaction with ID %d not found.\n", frad_ID);
        return;
    }

    if (q == NULL) {
        // Deleting the first node
        head_transaction = p->next_transaction;
    } else {
        // Deleting a node in the middle or at the end
        q->next_transaction = p->next_transaction;
    }

    free(p);
}
int main()
{
    FILE *fptr;
    fptr=fopen("te2.txt","r");
    if (fptr == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    int nooftransaction,nooffradtransaction;
    fscanf(fptr, "%d" ,&nooftransaction);
    printf("No of transaction is:%d\t \t",nooftransaction);
    fscanf(fptr, "%d" ,&nooffradtransaction);
    printf("No of fraud-Transaction is:%d\n",nooffradtransaction);
    int transaction_ID,transaction_amount,frad_ID;
    for(int i=0; !feof(fptr); i++){
        if(i<nooftransaction){
            fscanf(fptr, "%d", &transaction_ID);
            fgetc(fptr);
            fscanf(fptr, "%d", &transaction_amount);
            printf("Transaction ID:%d\t\tTransaction amount: %d\n",transaction_ID,transaction_amount);
            Add_Transaction(transaction_ID,transaction_amount);
        }
        if(i>nooftransaction){
            fscanf(fptr, "%d", &frad_ID);
            printf("Frad_user ID is:%d\n",frad_ID);
            Del_Transaction(frad_ID);
        }
    }
    struct Node* p = head_transaction;
    printf("\nRemaining Transactions:\n");
    while (p != NULL) {
        printf("Transaction ID: %d\t\tTransaction amount: %d\n", p->transaction_ID, p->transaction_amount);
        p = p->next_transaction;
    }

    // Free the memory allocated for transactions
    p = head_transaction;
    while (p != NULL) {
        struct Node* temp = p;
        p = p->next_transaction;
        free(temp);
    }

    fclose(fptr);
    return 0;
}