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

int isBalancedParantheses(char *expression, Stack *stack)
{
    int index = 0;
    while (expression[index] != '\0')
    {
        char symbol = expression[index];
        if (symbol == '(')
        {
            push(stack, symbol);
        }
        else if (symbol == ')')
        {
            if (!isEmpty(stack))
            {
                pop(stack);
            }
            else
            {
                return 0;
            }
        }
        index = index + 1;
    }

    return isEmpty(stack);
}

int main()
{
    int size;
    char expression[MAX];
    Stack stack;
    printf("Enter the string: ");
    gets(expression);
    if (initStack(&stack, strlen(expression)))
    {
        int isValid = isBalancedParantheses(expression, &stack);
        isValid ? printf("Valid expression") : printf("Invalid expression");
        release(&stack);
        return 1;
    }
    else
    {
        printf("Something went wrong while initializing stack!");
        return 0;
    }
}