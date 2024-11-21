#include <stdio.h>
#define MAX 1000

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void maxHeapify(int *arr, int n, int i)
{
    int p = i, l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && arr[l] > arr[p])
    {
        p = l;
    }

    if (r < n && arr[r] > arr[p])
    {
        p = r;
    }

    if (p != i)
    {
        swap(arr, i, p);
        maxHeapify(arr, n, p);
    }
}

void printHeap(int *arr, int n)
{
    printf("Heap:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
}

int main()
{
    int arr[MAX], n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter nodes (space separated): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(&arr[0], n, i);
    }

    printHeap(&arr[0], n);
    return 0;
}