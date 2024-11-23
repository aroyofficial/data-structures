#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node *prev;
    struct Node *next;
} typedef Node;

struct PriorityQueue {
    struct Node *head;
    int rear;
    int size;
} typedef PriorityQueue;

Node *createNode(int data, int priority)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->priority = priority;
        newNode->prev = NULL;
        newNode->next = NULL;
    }

    return newNode;
}

Node *getLastNode(Node *head)
{
    Node *currentNode = head;

    while (currentNode != NULL && currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    return currentNode;
}

Node *getNodeWithMaxPriority(Node *head)
{
    Node *currentNode = head, *maxPriorityNode = head;

    if (currentNode != NULL)
    {
        int maxPriority = currentNode->priority;

        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;

            if (currentNode->priority > maxPriority)
            {
                maxPriority = currentNode->priority;
                maxPriorityNode = currentNode;
            }
        }
    }

    return maxPriorityNode;
}

void enqueue(PriorityQueue *pq, int data, int priority)
{
    if (pq->rear == pq->size - 1)
    {
        printf("Priority Queue is full!\n");
    }
    else
    {
        Node *newNode = createNode(data, priority);

        if (newNode != NULL)
        {
            if (pq->head == NULL)
            {
                pq->head = newNode;
            }
            else
            {
                Node *lastNode = getLastNode(pq->head);
                lastNode->next = newNode;
                newNode->prev = lastNode;
            }

            pq->rear++;
            printf("Node inserted successfully...\n");
        }
        else
        {
            printf("Node creation failed!\n");
        }
    }
}

void dequeue(PriorityQueue *pq)
{
    if (pq->rear == -1)
    {
        printf("Priority Queue is empty!\n");
    }
    else
    {
        Node *maxPriorityNode = getNodeWithMaxPriority(pq->head);
        Node *preecedingNode = maxPriorityNode->prev;
        Node *succeedingNode = maxPriorityNode->next;
        free(maxPriorityNode);
        
        if (preecedingNode != NULL)
        {
            preecedingNode->next = succeedingNode;
        }

        if (succeedingNode != NULL)
        {
            succeedingNode->prev = preecedingNode;
        }

        if (maxPriorityNode == pq->head)
        {
            pq->head = succeedingNode;
        }
        
        pq->rear--;
        printf("Node deleted successfully...\n");
    }
}

int peek(PriorityQueue *pq)
{
    if (pq->rear == -1)
    {
        printf("Priority Queue is empty!\n");
        return -1;
    }
    else
    {
        Node *maxPriorityNode = getNodeWithMaxPriority(pq->head);
        return maxPriorityNode->data;
    }
}

void deleteAll(PriorityQueue *pq)
{
    printf("Deleting all nodes...\n");
    Node *currentNode = pq->head;

    while (currentNode != NULL)
    {
        Node *nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    pq->head = NULL;
    printf("Nodes deleted successfully...\n");
}

void display(PriorityQueue *pq)
{
    if (pq->rear == -1)
    {
        printf("Priority Queue is empty!\n");
    }
    else
    {
        Node *currentNode = pq->head;
        printf("Priority Queue: ");

        while (currentNode != NULL)
        {
            printf("(%d,%d)--->", currentNode->data, currentNode->priority);
            currentNode = currentNode->next;
        }

        printf("\n");
    }
}

int main()
{
    PriorityQueue pq;
    pq.head = NULL;
    pq.rear = -1;
    printf("Enter the size: ");
    scanf("%d", &pq.size);

    while (1)
    {
        int choice, element, data, priority;
        printf("------------------------------");
        printf("\nPress 0 - Exit");
        printf("\nPress 1 - Enqueue");
        printf("\nPress 2 - Dequeue");
        printf("\nPress 3 - Peek");
        printf("\nPress 4 - Display");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 0:
                deleteAll(&pq);
                return 0;
            case 1:
                printf("Enter the element: ");
                scanf("%d", &data);
                printf("Enter the priority: ");
                scanf("%d", &priority);
                enqueue(&pq, data, priority);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                element = peek(&pq);
                if (element != -1)
                {
                    printf("Peeked element: %d\n", element);
                }
                break;
            case 4:
                display(&pq);
                break;
            default:
                printf("You've entered a wrong choice!\n");
        }
    }
    return 0;
}