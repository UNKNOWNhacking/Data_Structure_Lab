#include <stdio.h>
#include <conio.h>

int main() {
    int n, i, j, temp, a[100];

    printf("Enter the total integers you want to enter (make it less than 100):\n");
    scanf("%d", &n);
    printf("Enter the %d integer array elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j + 1] < a[j]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("The sorted numbers are:");
    for (i = 0; i < n; i++) {
        printf("%3d", a[i]);
    }

    return 0;
}
