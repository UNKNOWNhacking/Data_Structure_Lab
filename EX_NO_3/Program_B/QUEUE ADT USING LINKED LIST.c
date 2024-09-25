#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
} *front = NULL, *rear = NULL;

void insert();
void delet();
void display();
int item;

int main() {
    int ch;
    do {
        printf("\n\n1.\tEnqueue\n2.\tDequeue\n3.\tDisplay\n4.\tExit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                delet();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\n\nInvalid choice. Please try again...\n");
        }
    } while (1);

    getch();
    return 0;
}

void insert() {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("\n\nEnter ITEM: ");
    scanf("%d", &item);
    temp->info = item;
    temp->link = NULL;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->link = temp;
        rear = temp;
    }
}

void delet() {
    struct node *ptr;
    if (front == NULL) {
        printf("\n\nQueue is empty.\n");
        return;
    }
    ptr = front;
    item = front->info;
    front = front->link;
    free(ptr);
    printf("\nItem deleted: %d\n", item);
    if (front == NULL) {
        rear = NULL;
    }
}

void display() {
    struct node *ptr = front;
    if (rear == NULL) {
        printf("\n\nQueue is empty.\n");
        return;
    }
    printf("\n\n");
    while (ptr != NULL) {
        printf("%d\t", ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}
