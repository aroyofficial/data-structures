#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *data;
    int tos;
    int size;
} typedef Stack;

int isEmpty(Stack *stack)
{
    return stack->tos == -1;
}

int isFull(Stack *stack)
{
    return stack->tos == stack->size - 1;
}

void push(Stack *stack, int element)
{
    if (isFull(stack))
    {
        printf("\nStack Overflow!");
    }
    else
    {
        stack->tos++;
        stack->data[stack->tos] = element;
        printf("\nElement pushed successfully");
    }
}

void pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("\nStack Underflow!");
    }
    else
    {
        stack->tos--;
        printf("\nElement popped successfully");
    }
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("\nStack is empty!");
        return -1;
    }
    else
    {
        return stack->data[stack->tos];
    }
}

void display(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("\nStack is empty!");
    }
    else
    {
        printf("\nData:");
        for (int i = 0; i <= stack->tos; i++)
        {
            printf(" %d", stack->data[i]);
        }
    }
}

int initStack(Stack *stack, int size)
{
    stack->size = size;
    stack->tos = -1;
    stack->data = (int *) malloc(size * sizeof(int));
    return stack->data != NULL;
}

void release(Stack *stack)
{
    free(stack->data);
    stack->data = NULL;
}

int main()
{
    int size;
    Stack stack;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    if (initStack(&stack, size))
    {
        while (1)
        {
            int choice, element, top;
            printf("\n------------------------------");
            printf("\nPress 0 - Exit");
            printf("\nPress 1 - Push");
            printf("\nPress 2 - Pop");
            printf("\nPress 3 - Peek");
            printf("\nPress 4 - Display");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
                case 0:
                    release(&stack);
                    exit(0);
                case 1:
                    printf("Enter the element: ");
                    scanf("%d", &element);
                    push(&stack, element);
                    break;
                case 2:
                    pop(&stack);
                    break;
                case 3:
                    top = peek(&stack);
                    if (top != -1)
                    {
                        printf("\nTop element: %d", top);
                    }
                    break;
                case 4:
                    display(&stack);
                    break;
                default:
                    printf("\nYou've entered a wrong choice!");
            }
        }
    }
    else
    {
        printf("Something went wrong while initializing stack!");
    }
}