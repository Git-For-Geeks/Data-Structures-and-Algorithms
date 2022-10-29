// C program to create a mirror of
// binary tree

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node* left;
    struct node* right;

} Node;

void AddNode(Node** root, int item)
{
    Node* temp = *root;
    Node* prev = *root;

    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));

        (*root)->item = item;
        (*root)->left = (*root)->right = NULL;
    }
    else {
        while (temp != NULL) {
            if (item > temp->item) {
                prev = temp;
                temp = temp->right;
            }
            else {
                prev = temp;
                temp = temp->left;
            }
        }
        temp = (Node*)malloc(sizeof(Node));
        temp->item = item;

        if (item >= prev->item)
            prev->right = temp;
        else
            prev->left = temp;
    }
}

void Inorder(Node* root)
{
    if (root != NULL) {
        Inorder(root->left);
        printf("%d ", root->item);
        Inorder(root->right);
    }
}

void createMirrorTree(Node* root)
{
    Node* temp;

    if (root == NULL)
        return;

    createMirrorTree(root->left);
    createMirrorTree(root->right);

    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main()
{
    Node* root = NULL;

    AddNode(&root, 10);
    AddNode(&root, 20);
    AddNode(&root, 60);
    AddNode(&root, 50);
    AddNode(&root, 40);

    printf("Tree Items: (INORDER) \n");
    Inorder(root);

    createMirrorTree(root);

    printf("\nMirror Tree items: (INORDER)\n");
    Inorder(root);
    printf("\n");

    return 0;
}
