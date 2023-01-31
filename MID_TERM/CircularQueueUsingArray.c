#include <stdio.h>
#include <stdlib.h>
int insert(int arr[], int rear, int* front, int n)
{
    if (*front == 0 && rear == n - 1 || rear == *front - 1)
    {
        printf("Queue is overflowed");
        return rear;
    }
    printf("Enter the value: ");
    int value;
    scanf("%d", &value);
    if (*front == -1 && rear == -1)
    {
        rear = 0;
        *front = 0;
    }
    else if (rear == n - 1 && *front != 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    arr[rear] = value;
    return rear;
}
int deletion(int arr[], int front, int *rear, int n)
{
    if (front == -1 && *rear == -1)
    {
        printf("Queue is underflow/Empty\n");
        return -1;
    }
    if (front == *rear) // single element present
    {
        printf("Deleted Element: %d", arr[front]);
        front = *rear = -1;
    }
    else if (front == n - 1 && *rear != front)
    {
        printf("Deleted Element: %d", arr[front]);
        front = 0; // to maintain cyclic nature
    }
    else
    {
        printf("Deleted Element: %d", arr[front]);
        front++;
    }
    return front;
}

void display(int arr[], int front, int rear, int n)
{
    if (front == -1)
    {
        printf("Queue is EMPTY!\n");
    }
    else{
    if (front < rear)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    else
    {
        for (int i = front; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
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
          \n 1).Insertion \n 2).Deletion \n 3).Display\n 4).Exit\n");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            rear = insert(arr, rear, &front, n);
            printf("front:%d rear:%d ", front, rear);
            break;
        case 2:
            front = deletion(arr, front, &rear, n);
            printf("front:%d rear:%d ", front, rear);
            break;
        case 3:
            display(arr, front, rear, n);
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