#include<stdio.h>
#define MAX_SIZE 10
int array[MAX_SIZE], n,  i;
void insert(){
    if(n<MAX_SIZE){
        printf("\nEnter The Element : ");
        scanf("%d", &array[n++]);
    }else
        printf("\nArray Maximum Limit Reached  !");
}
void display(){
    printf("\nElements in this Array are:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", array[i]);
}
void del(){
    if(n>0){
        int choice;
        printf("\nEnter A Array Element Index : ");
        scanf("%d", &choice);
        for(i=choice-1;i<n;i++)
            array[i] = array[i+1];
        n = n -1;
    }else
        printf("\nNo Elements presents in Array !");
}
void search(){
    int choice;printf("\nEnter The Element :");
    scanf("%d", &choice);
    for(i=0;i<n;i++){
        if(choice==array[i])
            printf("\nArray Element Found at : %d index", i);
    }
}
void main(){
    int choice, x;
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Search\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insert();break;
            case 2: del();break;
            case 3: display();break;
            case 4: search();break;
            case 5: printf("Exiting.\n");break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 5);
    return 0;
}
