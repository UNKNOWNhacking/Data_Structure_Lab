#include <stdio.h>
#include <conio.h>

void qsort(int arr[], int low, int high);
void main() {
    int arr[30];
    int i, size;

    printf("Enter total number of elements: ");
    scanf("%d", &size);
    printf("Enter %d elements:\n", size);

    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, 0, size - 1);

    printf("Quick sorted elements are:\n");
    for (i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }

    getch();
}

void qsort(int arr[], int low, int high) {
    int i, j, pivot, tmp;
    if (low < high) {
        pivot = low;
        i = low;
        j = high;

        while (i < j) {
            while (arr[i] <= arr[pivot] && i < high)
                i++;
            while (arr[j] > arr[pivot])
                j--;
            if (i < j) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }

        tmp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = tmp;

        qsort(arr, low, j - 1);
        qsort(arr, j + 1, high);
    }
}
