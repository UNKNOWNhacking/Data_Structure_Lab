#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;
void push(int x) {
    if (top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack[++top] = x;
}
int pop() {
    if (top == -1) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack[top--];
}
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Elements in the stack:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main() {
    int choice, x;

    printf("STACK OPERATIONS USING ARRAY\n");
    printf("----------------------------\n");

    do {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                x = pop();
                if (x != -1) {
                    printf("Popped element: %d\n", x);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
