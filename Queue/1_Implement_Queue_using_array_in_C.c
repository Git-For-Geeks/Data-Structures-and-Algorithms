#include <stdio.h>

#define MAX 10000

int arr[MAX];
int front = 0;
int back = -1;
int maxSize;

void enqueue(int enq);
void dequeue();
void peek_front();
int isEmpty();
int isFull();
void size();

void main()
{
    int inp, enq, f, e;
    printf("Enter Maximum size of Queue: ");
    scanf("%d", &maxSize);
    {
        printf("\nQueue Operations-\n");
        printf("1. Enqueue\t2. Dequeue\t3. Peek Front\n4. isEmpty\t5. isFull\t6. Size\n0. Exit\n");
        scanf("%d", &inp);
        switch (inp)
        {
        case 1:
            printf("Enter Element to be Enqueued: ");
            scanf("%d", &enq);
            enqueue(enq);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek_front();
            break;

        case 4:
            e = isEmpty();
            if (e == 0)
            {
                printf("Queue is Not Empty\n");
            }
            else
            {
                printf("Queue is Empty\n");
            }
            break;

        case 5:
            f = isFull();
            if (f == 0)
            {
                printf("Queue is Not Full\n");
            }
            else
            {
                printf("Queue is Full\n");
            }
            break;

        case 6:
            size();
            break;
        }
    }
    while (inp != 0)
        ;
    return;
}

int isEmpty()
{
    if (back < front)
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
    if ((back - front + 1) == maxSize)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int enq)
{
    if (isFull())
    {
        printf("Can't Enqueue, Queue is Full.\n");
    }
    else
    {
        back++;
        arr[back] == enq;
        printf("Element Enqueued...\n");
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Element Dequeued: %d\n", arr[front]);
        front++;
        if (isEmpty())
        {
            front = 0;
            back = -1;
        }
    }
}

void peek_front()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Element at the Front: %d", front);
    }
}

void size()
{

    printf("Size of the Queue is: %d", back - front + 1);
}