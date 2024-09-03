#include <stdio.h>
#define MAX 100

int find(int arr[], int size, int s)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == s)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[MAX], size, s;
    printf("Enter the size: ");
    scanf("%d", &size);
    printf("Enter elements (space separated): ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the search element: ");
    scanf("%d", &s);
    int index = find(arr, size, s);
    index == -1 ? printf("Search not found") : printf("Search found at index %d", index);
}