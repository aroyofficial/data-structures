#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

struct Stack {
    char *data;
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

void push(Stack *stack, char element)
{
    if (isFull(stack))
    {
        printf("\nStack Overflow!");
    }
    else
    {
        stack->tos++;
        stack->data[stack->tos] = element;
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
    }
}

char peek(Stack *stack)
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

int initStack(Stack *stack, int size)
{
    stack->size = size;
    stack->tos = -1;
    stack->data = (char *) malloc(size * sizeof(char));
    return stack->data != NULL;
}

void release(Stack *stack)
{
    free(stack->data);
    stack->data = NULL;
}

char *reverse(char *str, Stack *stack)
{
    int index = 0, i = 0;
    const int capacity = (strlen(str) + 1) * sizeof(char);
    char *result = (char *) malloc(capacity);
    while (str[index] != '\0')
    {
        push(stack, str[index]);
        index++;
    }
    while (!isEmpty(stack))
    {
        result[i++] = peek(stack);
        pop(stack);
    }
    result[i] = '\0';
    return result;
}

int main()
{
    int size;
    char str[MAX];
    Stack stack;
    printf("Enter the string: ");
    gets(str);
    if (initStack(&stack, strlen(str)))
    {
        char *reverseStr = reverse(str, &stack);
        printf("Reverse: %s", reverseStr);
        release(&stack);
        return 1;
    }
    else
    {
        printf("Something went wrong while initializing stack!");
        return 0;
    }
}