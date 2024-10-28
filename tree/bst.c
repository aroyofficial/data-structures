#include <stdio.h>
#include <stdlib.h>

enum Child {
    NONE,
    LEFT,
    RIGHT
} typedef Child;

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
    
    printf("Node added successfully...");
}

Node *search(Node *root, int data)
{    
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (data == root->data)
        {
            return root;
        }
        else if (data < root->data)
        {
            search(root->left, data);
        }
        else
        {
            search(root->right, data);
        }
    }
}

Node *getParent(Node *root, Node *child, Child *childName)
{    
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (child == root->left)
        {
            *childName = LEFT;
            return root;
        }
        else if (child == root->right)
        {
            *childName = RIGHT;
            return root;
        }
        else if (child->data < root->data)
        {
            return getParent(root->left, child, childName);
        }
        else
        {
            return getParent(root->right, child, childName);
        }
    }
}

int isLeafNode(Node *node)
{
    return node->right == NULL && node->left == NULL ? 1 : 0;
}

int hasSingleChild(Node *node)
{
    return node->right == NULL || node->left == NULL ? 1 : 0;
}

int haveBothChild(Node *node)
{
    return node->right != NULL && node->left != NULL ? 1 : 0;
}

Node *getInorderSuccessor(Node *node)
{
    Node *currentNode = node->right;
    while (currentNode != NULL && currentNode->left != NULL)
    {
        currentNode = currentNode->left;
    }
    return currentNode;
}

void updateParent(Node *root, Node *nodeToDelete, Node *address)
{
    Child childName = NONE;
    Node *parentNode = getParent(root, nodeToDelete, &childName);
            
    if (childName == LEFT)
    {
        parentNode->left = address;
    }
    else if (childName == RIGHT)
    {
        parentNode->right = address;
    }
}

void delete(Node **root, int data)
{
    Node *nodeToDelete = search(*root, data);
    
    if (nodeToDelete == NULL)
    {
        printf("No node found!");
    }
    else
    {
        if(nodeToDelete == *root && hasSingleChild(nodeToDelete))
        {
            Node *childNode = nodeToDelete->left == NULL ? nodeToDelete->right : nodeToDelete->left;
            *root = childNode;
        }
        else if (isLeafNode(nodeToDelete))
        {
            updateParent(*root, nodeToDelete, NULL);
        }
        else if (hasSingleChild(nodeToDelete))
        {
            Node *childNode = nodeToDelete->left == NULL ? nodeToDelete->right : nodeToDelete->left;
            updateParent(*root, nodeToDelete, childNode);
        }
        else if (haveBothChild(nodeToDelete))
        {
            Node *inorderSuccessor = getInorderSuccessor(nodeToDelete);
            nodeToDelete->data = inorderSuccessor->data;
            nodeToDelete = inorderSuccessor;
            updateParent(*root, nodeToDelete, NULL);
        }
        free(nodeToDelete);
        printf("Node deleted successfully...");
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
        printf("Press 2 for Delete\n");
        printf("Press 3 for Inorder Traversal\n");
        printf("Press 4 for Preorder Traversal\n");
        printf("Press 5 for Postorder Traversal\n");
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
                break;
            case 2:
                printf("Enter the node to delete: ");
                scanf("%d", &data);
                delete(&root, data);
                break;
            case 3:
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
            case 4:
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
            case 5:
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