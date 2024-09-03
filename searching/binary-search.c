#include <stdio.h>
#define MAX 100

int find(int arr[], int size, int s)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (s == arr[mid])
        {
            return mid;
        }
        else if (s > arr[mid])
        {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[MAX], size, s;
    printf("Enter the size: ");
    scanf("%d", &size);
    printf("Enter elements (space separated in ascending order): ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the search element: ");
    scanf("%d", &s);
    int index = find(arr, size, s);
    index == -1 ? printf("Search not found") : printf("Search found at index %d", index);
}