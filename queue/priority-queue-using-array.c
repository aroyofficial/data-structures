#include <stdio.h>
#define MAX 1000

struct Item {
    int value;
    int priority;
} typedef Item;

struct PriorityQueue {
    Item data[MAX];
    int size;
    int rear;
} typedef PriorityQueue;

void enqueue(PriorityQueue *pq, Item item)
{
    if (pq->rear == pq->size - 1)
    {
        printf("Priority Queue is full!\n");
    }
    else
    {
        pq->rear++;
        pq->data[pq->rear] = item;
        printf("Element inserted successfully...\n");
    }
}

int getMaxPriorityIndex(PriorityQueue *pq)
{
    int maxPriority = pq->data[0].priority, maxIndex = 0;
    
    for (int i = 1; i <= pq->rear; i++)
    {
        if (pq->data[i].priority > maxPriority)
        {
            maxPriority = pq->data[i].priority;
            maxIndex = i;
        }
    }
    
    return maxIndex;
}

void dequeue(PriorityQueue *pq)
{
    if (pq->rear == -1)
    {
        printf("Priority Queue is empty!\n");
    }
    else
    {
        int index = getMaxPriorityIndex(pq); 

        for (int i = index + 1; i <= pq->rear; i++)
        {
            pq->data[i - 1] = pq->data[i];
        }

        pq->rear--;
        printf("Element removed successfully...\n");
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
        int index = getMaxPriorityIndex(pq);
        return pq->data[index].value;
    }
}

void display(PriorityQueue *pq)
{
    if (pq->rear == -1)
    {
        printf("Priority Queue is empty!");
    }
    else
    {
        printf("Priority Queue:");

        for (int i = 0; i <= pq->rear; i++)
        {
            printf(" (%d,%d)", pq->data[i].value, pq->data[i].priority);
        }
    }
}

int main()
{
    PriorityQueue pq;
    printf("Enter the size: ");
    scanf("%d", &pq.size);
    pq.rear = -1;

    while (1)
    {
        int choice, element;
        Item item;
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
                return 0;
            case 1:
                printf("Enter the element: ");
                scanf("%d", &item.value);
                printf("Enter the priority: ");
                scanf("%d", &item.priority);
                enqueue(&pq, item);
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