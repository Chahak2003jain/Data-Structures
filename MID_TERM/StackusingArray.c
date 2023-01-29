#include <stdio.h>
#include <stdlib.h>

int insertion(int arr[], int n, int top)
{
    if (top == n - 1)
        printf("STACK IS FULL/OVERFLOW");
    else
    {
        int value;
        printf("Enter the value:\n");
        scanf("%d", &value);
        top++;
        arr[top] = value;
    }
    return top;
}

int deletion(int arr[], int n, int top)
{
    if (top == -1)
        printf("STACK IS EMPTY/UNDERFLOW\n");
    else
    {
        printf("Value deleted is %d\n", arr[top]);
        top--;
    }
    return top;
}

void display(int arr[], int n, int top)
{
    int i;
    if(top==-1)
    printf("Stack is empty. No elements present\n");
    for (i = top; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int n, top = -1, ch;
    printf("Enter the size of array:\n");
    scanf("%d", &n);
    int arr[n];
    do
    {
        printf("Enter your  choice:\n 1).Insert\n 2).Delete\n 3).Display\n 4).Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            top = insertion(arr, n, top);
            break;
        case 2:
            top = deletion(arr, n, top);
            break;
        case 3:
            display(arr, n, top);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("WRONG CHOICE!!");
        }
    } while (1);
    printf("Value of top: %d ", top);
    return 0;
}