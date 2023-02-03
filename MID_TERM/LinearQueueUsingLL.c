#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;

node* insertion(node** front,node* rear){
    node *p;
    p=(node*)malloc(sizeof(node));
    int val;
    printf("Enter the value:\n");
    scanf("%d",&val);
    p->data=val;
    p->next=NULL;
    if(rear==NULL){
      rear=p;
      *front=p;
    }
    else{
        rear->next=p;
        rear=p;
    }
    return rear;
}

node *deletion(node* front, node** rear){
    if(front==NULL){
        printf("Queue is Empty\n");
        return front;
    }
    printf("Deleted node:%d \n",front->data);
    node *temp=front;
    front=front->next;
    temp->next=NULL;
    free(temp);
    return front;
}

void display(node*front,node*rear){
    node* temp=front;
    if(front==NULL){
        printf("Queue is empty!\n");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    node *front = NULL;
    node *rear = NULL;
    int ch;
    do
    {
        printf("Enter your  choice:\n 1).Insert\n 2).Delete\n 3).Display\n 4).Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            rear = insertion(rear, &front);
            break;
        case 2:
            front = deletion(&rear, front);
            break;
        case 3:
            display(rear, front);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("WRONG CHOICE!!");
        }
    } while (1);
}