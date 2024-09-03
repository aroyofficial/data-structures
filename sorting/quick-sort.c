#include <stdio.h>
#define MAX 100

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;
    for (int j = 0; j < right; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void quicksort(int *arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quicksort(arr, left, pivot - 1);
        quicksort(arr, pivot + 1, right);
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
    quicksort(&arr[0], 0, size - 1);
    printf("Sorted array (in ascending order): ");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", arr[i]);
    }
}