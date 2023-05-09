#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int MAX_SIZE = 100;

// Function to compare two integers in ascending order
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void ascendingOrder(char newValue[])
{

    char *token;
    int arr[MAX_SIZE];
    int i = 0;

    // Separates characters and converts them to integers
    token = strtok(newValue, ",");
    while (token != NULL)
    {
        arr[i++] = atoi(token);
        token = strtok(NULL, ",");
    }

    // Sort the array in ascending order
    qsort(arr, i, sizeof(int), cmpfunc);

    // Prints the sorted array
    printf("Sorted Array: ");
    for (int j = 0; j < i; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");
}

void sortedArray(char arrayNew[])
{
    int len = strlen(arrayNew);
    char new_str[MAX_SIZE];
    int j = 0;

    for (int i = 0; i < len; i++)
    {
        if ((arrayNew[i] != '[') && (arrayNew[i] != ']'))
        {                             // checks if the character is different from ':'
            new_str[j] = arrayNew[i]; // copy the character to the new string
            j++;
        }
    }
    ascendingOrder(new_str);
}

int main()
{
    char arrayNew[MAX_SIZE];

    printf("Enter the array to be sorted: ");
    scanf("%s", arrayNew);
    sortedArray(arrayNew);
    return 0;
}