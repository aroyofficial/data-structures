#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *data;
    int front;
    int rear;
    int size;
} typedef Queue;

void enqueue(Queue *queue, int element)
{
    if (queue->rear == queue->size - 1)
    {
        printf("Queue is full!");
    }
    else
    {
        if (queue->front == -1)
        {
            queue->front = 0;
        }
        queue->rear++;
        queue->data[queue->rear] = element;
        printf("Enqueue operation successfull");
    }
}

void dequeue(Queue *queue)
{
    if (queue->front == -1 || queue->front == queue->rear + 1)
    {
        printf("Queue is empty!");
    }
    else
    {
        queue->front++;
        printf("Dequeue operation successfull");
    }
}

int peek(Queue *queue)
{
    if (queue->front == -1 || queue->front == queue->rear + 1)
    {
        printf("Queue is empty!");
        return -1;
    }
    else
    {
        return queue->data[queue->front];
    }
}

void display(Queue *queue)
{
    if (queue->front == -1 || queue->front == queue->rear + 1)
    {
        printf("Queue is empty!");
    }
    else
    {
        printf("Queue:");
        for (int i = 0; i < queue->size; i++)
        {
            if (queue->front <= i && i <= queue->rear)
            {
                printf(" %d", queue->data[i]);
            }
            else
            {
                printf(" _");
            }
        }
    }
}

int initQueue(Queue *queue, int size)
{
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;
    queue->data = (int *) malloc(size * sizeof(int));
    return queue->data != NULL;
}

void release(Queue *queue)
{
    free(queue->data);
    queue->data = NULL;
}

int main()
{
    int size;
    Queue queue;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    if (initQueue(&queue, size))
    {
        while (1)
        {
            int choice, element, top;
            printf("\n------------------------------");
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
                    release(&queue);
                    exit(0);
                case 1:
                    printf("Enter the element: ");
                    scanf("%d", &element);
                    enqueue(&queue, element);
                    break;
                case 2:
                    dequeue(&queue);
                    break;
                case 3:
                    top = peek(&queue);
                    if (top != -1)
                    {
                        printf("Front element: %d", top);
                    }
                    break;
                case 4:
                    display(&queue);
                    break;
                default:
                    printf("You've entered a wrong choice!");
            }
        }
    }
    else
    {
        printf("Something went wrong while initializing queue!");
    }
}