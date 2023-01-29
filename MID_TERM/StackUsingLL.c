#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *push(node *top)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    printf("Enter value:");
    int val;
    scanf("%d", &val);
    p->data = val;
    p->next = NULL;
    if (top == NULL)
    {
        top = p;
    }
    else
    {
        p->next = top;
        top = p;
    }
    return top;
}

node *pop(node *top)
{
    if (top == NULL)
    {
        printf("STACK IS EMPTY\n");
        return top;
    }
    else
    {
        printf("Value of deleted elemet:%d\n", top->data);
        node *temp = top;
        top = top->next;
        temp->next = NULL;
        free(temp);
    }
    return top;
}

void display(node *top)
{
    if (top == NULL)
    {
        printf("Stack is EMPTY\n");
        return;
    }
    node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    node *top = NULL;
    int ch;
    do
    {
        printf("Enter your  choice:\n 1).Insert\n 2).Delete\n 3).Display\n 4).Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            top = push(top);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("WRONG CHOICE!!");
        }
    } while (1);
}