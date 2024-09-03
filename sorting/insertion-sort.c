#include <stdio.h>
#define MAX 100

int sort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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