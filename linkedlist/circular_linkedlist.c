#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} typedef Node;

Node *createNode(int data)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node *getLastNode(Node *head)
{
    Node *currentNode = head;
    while (currentNode->next != head)
    {
        currentNode = currentNode->next;
    }
    return currentNode;
}

Node *getSecondLastNode(Node *head)
{
    Node *currentNode = head;
    while (currentNode->next->next != head)
    {
        currentNode = currentNode->next;
    }
    return currentNode;
}

void addFromStart(Node **head, int data)
{
    if (*head == NULL)
    {
        *head = createNode(data);
        (*head)->next = *head;
    }
    else
    {
        Node *newNode = createNode(data);
        newNode->next = *head;
        *head = newNode;
        Node *lastNode = getLastNode(*head);
        lastNode->next = *head;
    }
}

void addFromEnd(Node **head, int data)
{
    if (*head == NULL)
    {
        *head = createNode(data);
        (*head)->next = *head;
    }
    else
    {
        Node *newNode = createNode(data);
        Node *lastNode = getLastNode(*head);
        lastNode->next = newNode;
        lastNode = newNode;
        lastNode->next = *head;
    }
}

void deleteFromStart(Node **head)
{
    if (*head != NULL)
    {
        Node *secondNode = (*head)->next;
        free(*head);
        *head = secondNode;

        if (*head != NULL)
        {
            Node *lastNode = getLastNode(*head);
            lastNode->next = *head;
        }
    }
}

void deleteFromEnd(Node **head)
{
    if (*head != NULL)
    {
        if ((*head)->next == head)
        {
            free(*head);
            *head = NULL;
        }
        else
        {
            Node *secondLastNode = getSecondLastNode(*head);
            free(secondLastNode->next);
            secondLastNode->next = *head;
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
            printf(" %d --->", currentNode->data);
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
        int choice, data;
        printf("-----------------------------\n");
        printf("Press 0 - Exit\n");
        printf("Press 1 - Add from start\n");
        printf("Press 2 - Add from end\n");
        printf("Press 3 - Delete from start\n");
        printf("Press 4 - Delete from end\n");
        printf("Press 5 - Display\n");
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
                deleteFromStart(&head);
                break;
            case 4:
                deleteFromEnd(&head);
                break;
            case 5:
                display(&head);
                break;
            default:
                printf("Please choose the valid choice!\n");
        }
    }
}