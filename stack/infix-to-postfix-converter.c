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

int isOperand(char symbol)
{
    for (int ascii = 65; ascii <= 90; ascii++)
    {
        if (ascii == (int)symbol)
        {
            return 1;
        }
    }

    for (int ascii = 97; ascii <= 122; ascii++)
    {
        if (ascii == (int)symbol)
        {
            return 1;
        }
    }

    for (int ascii = 48; ascii <= 57; ascii++)
    {
        if (ascii == (int)symbol)
        {
            return 1;
        }
    }

    return 0;
}

int isOperator(char symbol)
{
    switch (symbol)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '%':
        case '(':
        case ')':
            return 1;
        default:
            return 0;
    }
}

int preecedence(char symbol)
{
    switch (symbol)
    {
        case '^':
            return 4;
        case '%':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
            return 0;
    }
}

char *infixToPostfix(char *infixExpression, Stack *stack)
{
    int i = 0, index = 0;
    char *postfixExpression = (char *) malloc(stack->size * sizeof(char));
    while (infixExpression[i] != '\0')
    {
        char symbol = infixExpression[i];
        if (isOperand(symbol))
        {
            postfixExpression[index++] = symbol;
        }
        else if (isOperator(symbol))
        {
            if (symbol == ')')
            {
                while (!isEmpty(stack) && peek(stack) != '(')
                {
                    char operator = peek(stack);
                    postfixExpression[index++] = operator;
                    pop(stack);
                }
                if (!isEmpty(stack))
                {
                    pop(stack);
                }
            }
            else if (symbol == '(')
            {
                push(stack, symbol);
            }
            else
            {
                while (!isEmpty(stack) && preecedence(peek(stack)) >= preecedence(symbol))
                {
                    postfixExpression[index++] = peek(stack);
                    pop(stack);
                }
                push(stack, symbol);
            }
        }
        else
        {
            printf("Given infix expression is invalid!");
            return NULL;
        }
        i++;
    }

    while (!isEmpty(stack))
    {
        postfixExpression[index++] = peek(stack);
        pop(stack);
    }
    postfixExpression[index] = '\0';
    return postfixExpression;
}

int main()
{
    int size;
    char infixExpression[MAX];
    Stack stack;
    printf("Enter the infix expression: ");
    gets(infixExpression);
    if (initStack(&stack, strlen(infixExpression)))
    {
        char *postfixExpression = infixToPostfix(infixExpression, &stack);
        printf("Equivalent postfix expression: %s", postfixExpression);
        release(&stack);
        return 1;
    }
    else
    {
        printf("Something went wrong while initializing stack!");
        return 0;
    }
}