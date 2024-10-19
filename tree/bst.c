#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} typedef Node;

void preorder(Node *root)
{
    if (root == NULL)
    {
        return ;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return ;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

Node *createNode(int data)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void add(Node **root, int data)
{
    if (*root == NULL)
    {
        *root = createNode(data);
    }
    else
    {
        Node *currentNode = *root;
        
        while (1)
        {
            if (data < currentNode->data)
            {
                if (currentNode->left == NULL)
                {
                    currentNode->left = createNode(data);
                    break;
                }
                else
                {
                    currentNode = currentNode->left;
                }
            }
            else
            {
                if (currentNode->right == NULL)
                {
                    currentNode->right = createNode(data);
                    break;
                }
                else
                {
                    currentNode = currentNode->right;
                }
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    int choice, data;
    while (1)
    {
        printf("\n----------------------------------\n");
        printf("Press 0 for Exit\n");
        printf("Press 1 for Add\n");
        printf("Press 2 for Inorder Traversal\n");
        printf("Press 3 for Preorder Traversal\n");
        printf("Press 4 for Postorder Traversal\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 0:
                printf("Program exited successfully...");
                return 0;
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                add(&root, data);
                printf("Node added successfully...");
                break;
            case 2:
                if (root == NULL)
                {
                    printf("No root node found!");
                }
                else
                {
                    printf("Inorder Sequence: ");
                    inorder(root);
                }
                break;
            case 3:
                if (root == NULL)
                {
                    printf("No root node found!");
                }
                else
                {
                    printf("Preorder Sequence: ");
                    preorder(root);
                }
                break;
            case 4:
                if (root == NULL)
                {
                    printf("No root node found!");
                }
                else
                {
                    printf("Postorder Sequence: ");
                    postorder(root);
                }
                break;
            default:
                printf("Wrong choice is given!");
        }
    }
    return 0;
}