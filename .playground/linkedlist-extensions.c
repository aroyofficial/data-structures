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
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    return currentNode;
}

Node *getSecondLastNode(Node *head)
{
    Node *currentNode = head;
    while (currentNode->next->next != NULL)
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
    }
}

void addAfter(Node **head, int searchData, int data)
{
    Node *searchNode = getNode(head, searchData);    
    if (searchNode != NULL)
    {
        Node *newNode = createNode(data);
        newNode->next = searchNode->next;
        searchNode->next = newNode;
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
            while (currentNode->next != searchNode)
            {
                currentNode = currentNode->next;
            }

            currentNode->next = newNode;
        }
        else
        {
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
            Node *secondLastNode = getSecondLastNode(*head);
            free(secondLastNode->next);
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

void sort(Node **head) {    
    Node *currentNode = *head;

    while (currentNode != NULL && currentNode->next != NULL)
    {  
        Node *nextNode = currentNode->next;

        while (nextNode != NULL)
        {  
            if (currentNode->data > nextNode->data)
            {   
                int temp = currentNode->data;
                currentNode->data = nextNode->data;
                nextNode->data = temp;
            }

            nextNode = nextNode->next;
        }

        currentNode = currentNode->next;
    }
}

void sumIndividualNodes(Node **destList, Node *srcList)
{
    Node *temp1 = *destList, *temp2 = srcList;

    while (temp1 != NULL)
    {
        if (temp2 != NULL)
        {
            temp1->data += temp2->data;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
        {
            break;
        }
    }

    if (temp2 != NULL)
    {
        concat(destList, temp2);
    }
}

void concat(Node **destList, Node *srcList)
{
    if (srcList != NULL && *destList != NULL)
    {
        Node *bridgeNode = getLastNode(*destList);
        bridgeNode->next = srcList;
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

void menu(Node **linkedList1, Node **linkedList2, int select)
{
    int choice, data, target;
    Node **selectedList = select == 1 ? linkedList1 : linkedList2;
    Node *secondaryList = select == 1 ? *linkedList2 : *linkedList1;

    printf("\nPress 1 - Add from start\n");
    printf("Press 2 - Add from end\n");
    printf("Press 3 - Add after\n");
    printf("Press 4 - Add before\n");
    printf("Press 5 - Delete from start\n");
    printf("Press 6 - Delete from end\n");
    printf("Press 7 - Sort\n");
    printf("Press 8 - Concat\n");
    printf("Press 9 - Display\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice)
    {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            addFromStart(selectedList, data);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            addFromEnd(selectedList, data);
            break;
        case 3:
            printf("Enter the node after which you want to add: ");
            scanf("%d", &target);
            printf("Enter the data: ");
            scanf("%d", &data);
            addAfter(selectedList, target, data);
            break;
        case 4:
            printf("Enter the node before which you want to add: ");
            scanf("%d", &target);
            printf("Enter the data: ");
            scanf("%d", &data);
            addBefore(selectedList, target, data);
            break;
        case 5:
            deleteFromStart(selectedList);
            break;
        case 6:
            deleteFromEnd(selectedList);
            break;
        case 7:
            sort(selectedList);
            break;
        case 8:
            concat(selectedList, secondaryList);
            break;
        case 9:
            display(selectedList);
            break;
        default:
            printf("Please choose the valid choice!\n");
    }
}

int main()
{
    int proceed = 1, select = 1;
    Node *linkedList1 = NULL, *linkedList2 = NULL;

    do
    {
        printf("---------------------------------\n");
        printf("Press 1 ---> Select Linked List 1\n");
        printf("Press 2 ---> Select Linked List 2\n");
        printf("Enter your selection: ");
        scanf("%d", &select);

        if (select > 2)
        {
            printf("Selecting the default Linked List as Linked List 1...\n");
            select = 1;
        }
        
        menu(&linkedList1, &linkedList2, select);
        printf("Do you want to continue (1/0)?\n>>> ");
        scanf("%d", &proceed);
    }
    while (proceed);
}