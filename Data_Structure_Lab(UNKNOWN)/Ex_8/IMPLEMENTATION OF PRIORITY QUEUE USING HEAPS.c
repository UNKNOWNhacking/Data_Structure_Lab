#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct MinHeap {
    int size; 
    int array[MAX]; 
};

struct MinHeap* createMinHeap() {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    return minHeap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void minHeapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < heap->size && heap->array[left] < heap->array[smallest])
        smallest = left;

    if (right < heap->size && heap->array[right] < heap->array[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap->array[i], &heap->array[smallest]);
        minHeapify(heap, smallest);
    }
}

void insertMinHeap(struct MinHeap* heap, int value) {
    if (heap->size == MAX) {
        printf("Heap overflow!\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = value;

    while (i != 0 && heap->array[parent(i)] > heap->array[i]) {
        swap(&heap->array[i], &heap->array[parent(i)]);
        i = parent(i);
    }
}

int extractMin(struct MinHeap* heap) {
    if (heap->size <= 0)
        return INT_MAX;

    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }
    
    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    
    minHeapify(heap, 0);

    return root;
}

void display(struct MinHeap* heap) {
    if (heap->size == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Priority Queue: ");
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->array[i]);
    printf("\n");
}

int main() {
    struct MinHeap* heap = createMinHeap();

    insertMinHeap(heap, 10);
    insertMinHeap(heap, 20);
    insertMinHeap(heap, 5);
    insertMinHeap(heap, 30);
    insertMinHeap(heap, 2);

    printf("After insertion:\n");
    display(heap);

    printf("Extracted minimum element: %d\n", extractMin(heap));
    printf("After extraction:\n");
    display(heap);

    return 0;
}
