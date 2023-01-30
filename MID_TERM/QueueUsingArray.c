#include <stdio.h>
#include <stdlib.h>
int insert(int arr[], int rear, int n)
{
    if (rear == n - 1)
    {
        printf("Queue is overflowed");
    }
    else
    {
        printf("Enter the value: ");
        int value;
        scanf("%d", &value);
        rear++;
        arr[rear] = value;
    }
    return rear;
}

int deletion(int arr[], int front, int rear, int n)
{
    if (front == -1)
    {
        printf("Queue is underflow\n");
    }
    else
    {
        printf("Deleted Element: %d", arr[front]);
        front++;
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
    return front;
}

void display(int arr[], int front, int rear)
{
    if (front == -1)
    {
        printf("Queue is EMPTY!\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}

int main()
{
    int n, ch;
    printf("Enter the size of array:\n");
    scanf("%d", &n);
    int arr[n];
    int front = -1;
    int rear = -1;
    do
    {
        printf("\nEnter your choice:\
          \n 1).Insertion \n 2).Deletion \n 3).Display\n");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (front == -1)
                front++;
            rear = insert(arr, rear, n);
            printf("front:%d rear:%d ", front, rear);
            break;
        case 2:
            front = deletion(arr, front, rear, n);
            printf("front:%d rear:%d ", front, rear);
            break;
        case 3:
            display(arr, front, rear);
            printf("front:%d rear:%d ", front, rear);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Wrong Choice!");
        }
    } while (1);
}
