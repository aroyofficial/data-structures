#include <stdio.h>
#define MAX 100

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[MAX], size;
    printf("Enter the size: ");
    scanf("%d", &size);
    printf("Enter elements (space separated in ascending order): ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(&arr[0], size);
    printf("Sorted array (in ascending order): ");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
}