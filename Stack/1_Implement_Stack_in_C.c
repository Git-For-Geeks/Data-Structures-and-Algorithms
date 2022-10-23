#include <stdio.h>

#define MAX 1000

int arr[MAX], top = -1;

void push(int toPush);
void pop();
void peek();
int isEmpty();
int isFull();
int size();

void main()
{
    int inp, toPush, e, f;
    do
    {
        printf("\nStack Operations-\n");
        printf("1. Push\t\t2. Pop\t\t3. Peek\n4. isEmpty\t5. isFull\t6. Size\n0. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &inp);
        switch (inp)
        {
        case 1:
            printf("Element to be Pushed: ");
            scanf("%d", &toPush);
            push(toPush);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            e = isEmpty();
            if (e == 0)
            {
                printf("Stack is Not Empty\n");
            }
            else
            {
                printf("Stack is Empty\n");
            }
            break;

        case 5:
            f = isFull();
            if (f == 0)
            {
                printf("Stack is Not Full\n");
            }
            else
            {
                printf("Stack is Full\n");
            }
            break;

        case 6:
            printf("Size of the Stack is: %d", size());
        }
    } while (inp != 0);
    printf("Program Terminated....\n");
    return;
}

void push(int toPush)
{
    if (isFull())
    {
        printf("Stack is Full\n");
    }
    else
    {
        top++;
        arr[top] = toPush;
        printf("Element Pushed Successfully...\n");
    }
    return;
}

void pop()
{
    if (isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Element Popped: %d\n", arr[top]);
        top--;
    }
    return;
}

void peek()
{
    if (isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top of the Stack: %d\n", arr[top]);
    }
    return;
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (top == (MAX - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int size()
{
    return top + 1;
}