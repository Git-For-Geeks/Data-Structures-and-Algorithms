// C program to create Even and Odd lists
// from a Singly linked list

#include <stdio.h>
#include <stdlib.h>

//Self-referential structure to create the node.
typedef struct tmp {
    int item;
    struct tmp* next;
} Node;

//structure for creating linked list.
typedef struct
    {
    Node* head;
    Node* tail;

} List;

//Initialize List
void initList(List* lp)
{
    lp->head = NULL;
    lp->tail = NULL;
}

//Create node and return the reference of it.
Node* createNode(int item)
{
    Node* nNode;

    nNode = (Node*)malloc(sizeof(Node));

    nNode->item = item;
    nNode->next = NULL;

    return nNode;
}

//Add a new item at the end of the list.
void addAtTail(List* lp, int item)
{
    Node* node;
    node = createNode(item);

    //if list is empty.
    if (lp->head == NULL) {
        lp->head = node;
        lp->tail = node;
    }
    else {
        lp->tail->next = node;
        lp->tail = lp->tail->next;
    }
}

//Add a new item at the beginning of the list.
void addAtHead(List* lp, int item)
{
    Node* node;
    node = createNode(item);

    //if list is empty.
    if (lp->head == NULL) {
        lp->head = node;
        lp->tail = node;
    }
    else {
        node->next = lp->head;
        lp->head = node;
    }
}

//To print the list from start to end of the list.
void printList(List* lp)
{
    Node* node;

    if (lp->head == NULL) {
        printf("\nEmpty List");
        return;
    }

    node = lp->head;

    while (node != NULL) {
        printf("| %05d |", node->item);
        node = node->next;

        if (node != NULL)
            printf("--->");
    }
    printf("\n\n");
}

void createEvenOddList(List* lp, List* lpEven, List* lpOdd)
{
    Node* temp;

    temp = lp->head;

    while (temp != NULL) {
        if (temp->item % 2 == 0)
            addAtTail(lpEven, temp->item);
        else
            addAtTail(lpOdd, temp->item);

        temp = temp->next;
    }
}

//Main function to execute program.
int main()
{
    List* lp;
    List* lpEven;
    List* lpOdd;

    lp = (List*)malloc(sizeof(List));
    lpEven = (List*)malloc(sizeof(List));
    lpOdd = (List*)malloc(sizeof(List));

    initList(lp);
    initList(lpEven);
    initList(lpOdd);

    addAtTail(lp, 101);
    addAtTail(lp, 102);
    addAtTail(lp, 103);
    addAtTail(lp, 104);
    addAtTail(lp, 105);

    createEvenOddList(lp, lpEven, lpOdd);

    printf("List:\n");
    printList(lp);

    printf("Even List:\n");
    printList(lpEven);

    printf("Odd List:\n");
    printList(lpOdd);

    return 0;
}
