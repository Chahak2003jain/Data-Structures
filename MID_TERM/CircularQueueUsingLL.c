#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *insertion(node *rear, node *front)
{
    int val;
    printf("Enter the value to be inserted:\n");
    scanf("%d", &val);
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = val;
    ptr->next = NULL;
    if (rear == NULL)
    {
        rear = ptr;
        ptr->next = rear;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
        rear->next = front;
    }
    return rear;
}

node *deletion(node *front, node *rear)
{
    node *temp = front;
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return front;
    }
    if (rear->next == front && rear == front)
    {
        printf("Deleted Value:%d\n", temp->data);
        temp->next = NULL;
        front = NULL;
        free(temp);
    }
    else
    {
        printf("Deleted Value:%d\n", temp->data);
        front = front->next;
        rear->next = front;
        temp->next = NULL;
        free(temp);
    }
    return front;
}

void display(node *front, node *rear)
{
    if (front == NULL)
    {
        printf("Empty queue\n");
        return;
    }
    node *temp = front;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main()
{
    int ch;
    node *rear = NULL;
    node *front = NULL;
    do
    {
        printf("\nEnter  your choice\n1).Insertion\n2).Deletion\n3).Display\n4).Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            rear = insertion(rear, front);
            if (front == NULL)
            {
                front = rear;
                ;
            }
            break;
        case 2:
            front = deletion(front, rear);
            if (front == NULL)
            {
                rear = NULL;
            }
            break;
        case 3:
            display(front, rear);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (1);
}