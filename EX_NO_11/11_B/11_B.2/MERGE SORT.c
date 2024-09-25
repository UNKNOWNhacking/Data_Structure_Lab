#include <stdio.h>
#include <conio.h>

void merge(int arr[], int left, int mid, int right);
void part(int arr[], int left, int right);

void main() {
    int arr[30];
    int i, size;

    printf("\n\t------- Merge Sorting Method ------- \n\n");
    printf("Enter total number of elements: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    part(arr, 0, size - 1);

    printf("\n\t------- Merge Sorted Elements ------- \n\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    getch();
}

void part(int arr[], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        part(arr, left, mid);
        part(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int tmp[30];
    int i, j, k, m;
    j = left;
    m = mid + 1;

    for (i = left; j <= mid && m <= right; i++) {
        if (arr[j] <= arr[m]) {
            tmp[i] = arr[j];
            j++;
        } else {
            tmp[i] = arr[m];
            m++;
        }
    }

    if (j > mid) {
        for (k = m; k <= right; k++) {
            tmp[i] = arr[k];
            i++;
        }
    } else {
        for (k = j; k <= mid; k++) {
            tmp[i] = arr[k];
            i++;
        }
    }

    for (k = left; k <= right; k++) {
        arr[k] = tmp[k];
    }
}
