#include <stdio.h>
#include <stdlib.h>

struct Polynomial
{
    int coefficient;
    int exponent;
    struct Polynomial *nextTerm;
} typedef Polynomial;

Polynomial *getLastTerm(Polynomial *firstTerm)
{
    Polynomial *currentTerm = firstTerm;
    while (currentTerm->nextTerm != NULL)
    {
        currentTerm = currentTerm->nextTerm;
    }
    return currentTerm;
}

Polynomial *createPolynomialTerm(int coefficient, int exponent)
{
    Polynomial *term = (Polynomial*) malloc(sizeof(Polynomial));
    term->coefficient = coefficient;
    term->exponent = exponent;
    term->nextTerm = NULL;
    return term;
}

void addTerm(Polynomial **firstTerm, int coefficient, int exponent)
{
    if (*firstTerm == NULL)
    {
        *firstTerm = createPolynomialTerm(coefficient, exponent);
    }
    else
    {
        Polynomial *newTerm = createPolynomialTerm(coefficient, exponent);
        Polynomial *lastTerm = getLastTerm(*firstTerm);
        lastTerm->nextTerm = newTerm;
    }
}

void createPolynomial(Polynomial **polynomial)
{
    int choice;
    do
    {
        int coefficient, exponent;
        printf("Enter coefficient: ");
        scanf("%d", &coefficient);
        printf("Enter exponent: ");
        scanf("%d", &exponent);
        addTerm(polynomial, coefficient, exponent);
        printf("Press 1 --- Add another term to the polynomial\n");
        printf("Press any key --- Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }
    while (choice == 1);
}

void add(Polynomial **result, Polynomial *polynomial1, Polynomial *polynomial2)
{
    Polynomial *expr1Term = polynomial1, *expr2Term = polynomial2;
    while (expr1Term != NULL && expr2Term != NULL)
    {
        int coefficient = expr1Term->coefficient + expr2Term->coefficient;
        addTerm(result, coefficient, expr1Term->exponent);
        expr1Term = expr1Term->nextTerm;
        expr2Term = expr2Term->nextTerm;
    }
}

void printPolynomial(Polynomial *firstTerm)
{
    Polynomial *currentTerm = firstTerm;
    while (currentTerm != NULL)
    {
        switch (currentTerm->exponent)
        {
            case 0:
                printf("%d", currentTerm->coefficient);
                break;
            case 1:
                printf("%dx", currentTerm->coefficient);
                break;
            default:
                printf("%dx^%d", currentTerm->coefficient, currentTerm->exponent);
        }

        currentTerm = currentTerm->nextTerm;
        currentTerm != NULL ? printf(" + ") : printf("\n");
    }
}

void freePolynomial(Polynomial **firstTerm)
{
    Polynomial *currentTerm = *firstTerm;

    while (currentTerm != NULL)
    {
        free(currentTerm);
        currentTerm = currentTerm->nextTerm;
    }

    *firstTerm = NULL;
}

int main()
{
    Polynomial *polynomial1 = NULL, *polynomial2 = NULL, *result = NULL;

    printf("---------------------------------\n");
    printf("Enter the polynomial expression 1\n");
    createPolynomial(&polynomial1);
    printf("Given polynomial expression 1: ");
    printPolynomial(polynomial1);

    printf("---------------------------------\n");
    printf("Enter the polynomial expression 2\n");
    createPolynomial(&polynomial2);
    printf("Given polynomial expression 2: ");
    printPolynomial(polynomial2);

    printf("---------------------------------\n");
    add(&result, polynomial1, polynomial2);
    printf("Resultant polynomial expression: ");
    printPolynomial(result);

    freePolynomial(&polynomial1);
    freePolynomial(&polynomial2);
    freePolynomial(&result);
    printf("Deallocated dynamic memory successfully...");
}