#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} typedef Node;

Node *createNode(int data)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

Node *getLastNode(Node *head)
{
    Node *currentNode = head;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    return currentNode;
}

Node *getNode(Node **head, int data)
{
    Node *searchNode = *head;
    while (searchNode != NULL && searchNode->data != data)
    {
        searchNode = searchNode->next;
    }
    return searchNode;
}

void addFromStart(Node **head, int data)
{
    if (*head == NULL)
    {
        *head = createNode(data);
    }
    else
    {
        Node *newNode = createNode(data);
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void addFromEnd(Node **head, int data)
{
    if (*head == NULL)
    {
        *head = createNode(data);
    }
    else
    {
        Node *newNode = createNode(data);
        Node *lastNode = getLastNode(*head);
        lastNode->next = newNode;
        newNode->prev = lastNode;
    }
}

void addAfter(Node **head, int searchData, int data)
{
    Node *searchNode = getNode(head, searchData);    
    if (searchNode != NULL)
    {
        Node *newNode = createNode(data);
        newNode->next = searchNode->next;

        if (searchNode->next != NULL)
        {
            searchNode->next->prev = newNode;
        }

        searchNode->next = newNode;
        newNode->prev = searchNode;
    }
}

void addBefore(Node **head, int searchData, int data)
{
    Node *searchNode = getNode(head, searchData); 

    if (searchNode != NULL)
    {
        Node *newNode = createNode(data), *currentNode = *head;
        
        if (searchNode != *head)
        {
            searchNode->prev->next = newNode;
            newNode->prev = searchNode->prev;
            searchNode->prev = newNode;
        }
        else
        {
            (*head)->prev = newNode;
            *head = newNode;
        }

        newNode->next = searchNode;
    }
}

void deleteFromStart(Node **head)
{
    if (*head != NULL)
    {
        Node *secondNode = (*head)->next;
        free(*head);
        *head = secondNode;

        if (secondNode != NULL)
        {
            secondNode->prev = NULL;
        }
    }
}

void deleteFromEnd(Node **head)
{
    if (*head != NULL)
    {
        if ((*head)->next == NULL)
        {
            free(*head);
            *head = NULL;
        }
        else
        {
            Node *lastNode = getLastNode(*head);
            Node *secondLastNode = lastNode->prev;
            free(lastNode);
            secondLastNode->next = NULL;
        }
    }
}

void deleteAllNodes(Node **head)
{
    while (*head != NULL)
    {
        deleteFromEnd(head);
    }
}

void display(Node **head)
{
    if (*head != NULL)
    {
        Node *currentNode = *head;
        printf("Linked List:");
        while (currentNode != NULL)
        {
            printf(" %d <--->", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
    else
    {
        printf("Linked List has no nodes!\n");
    }
}

int main()
{
    Node *head = NULL;

    while (1)
    {
        int choice, data, target;
        printf("-----------------------------\n");
        printf("Press 0 - Exit\n");
        printf("Press 1 - Add from start\n");
        printf("Press 2 - Add from end\n");
        printf("Press 3 - Add after\n");
        printf("Press 4 - Add before\n");
        printf("Press 5 - Delete from start\n");
        printf("Press 6 - Delete from end\n");
        printf("Press 7 - Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 0:
                printf("Deleting the nodes...\n");
                deleteAllNodes(&head);
                printf("Program exited successfully");
                exit(0);
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                addFromStart(&head, data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                addFromEnd(&head, data);
                break;
            case 3:
                printf("Enter the node after which you want to add: ");
                scanf("%d", &target);
                printf("Enter the data: ");
                scanf("%d", &data);
                addAfter(&head, target, data);
                break;
            case 4:
                printf("Enter the node before which you want to add: ");
                scanf("%d", &target);
                printf("Enter the data: ");
                scanf("%d", &data);
                addBefore(&head, target, data);
                break;
            case 5:
                deleteFromStart(&head);
                break;
            case 6:
                deleteFromEnd(&head);
                break;
            case 7:
                display(&head);
                break;
            default:
                printf("Please choose the valid choice!\n");
        }
    }
}