#include<stdio.h>
#include<stdlib.h>
struct Node{
    int value;
    struct Node* next_value;
};
struct Node* head=NULL;

void printdata(){
    struct Node* temp=head;
    int i=1;
    while(temp != NULL){
        printf("The number at index %d is %d \n",i,temp->value);
        temp=temp->next_value;
        i++;
    }
}
int findLastThird(struct Node **head_ref){
    int count = 0;
    struct Node* temp = *head_ref;
    while(temp != NULL){
        count++;
        temp = temp->next_value;
    }
    if (count < 3){
        printf("The list does not have enough elements.\n");
        return -1;
    }
    temp = *head_ref;
    for (int i = 1; i < count - 2; i++)
        temp = temp->next_value;
    printf("\nThe last third element in the list is %d\n", temp->value);

}
// Another Method of find third last element
// void ThirdLastElement(struct Node* head, int Index){
//     int len = 0, i;
//     struct Node* temp = head;
//     while (temp != NULL) {
//         temp = temp->next_value;
//         len++;
//     }
//      if (len < Index)
//         return;
//     temp = head;
//     for (i = 1; i < len - Index + 1; i++)
//         temp = temp->next_value;
//     printf("%d", temp->value);
    
    
//     //free(q);
//     return ;
    
// }
struct Node* add_numbers(int n){
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    p->value=n;
    if(head==NULL){
        head=p;
        head->next_value=NULL;
    }else{
        struct Node*pt=head;
        while(pt->next_value != NULL){
            pt=pt->next_value;
        }
        pt->next_value=p;
        p->next_value=NULL;
    }
}
int main()
{
    FILE *fptr;
    fptr=fopen("T5.txt","r");
    int n;
    for(int i=0; !feof(fptr); i++){
        fscanf(fptr, "%d" ,&n);
        add_numbers(n);
       // printf("%d ",n);
    }
    fclose(fptr);
    printdata();
    //ThirdLastElement(head,3);
    findLastThird(&head);
    return 0;
}