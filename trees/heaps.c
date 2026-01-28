#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Código tá totalmente 0-based
// Implementação de um heap de máximo

// Structure to represent a Heap (Max Heap)
typedef struct Heap {
    int *array;
    int size;
    int capacity;
} Heap;

Heap *createHeap(int capacity) {
    Heap *heap = malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = malloc(capacity * sizeof(int));
    return heap;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the node at index i
// Complexity: O(log n)
// n = heap->size
void heapify(Heap *heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;

    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;

    if (largest != i)
    {
        swap(&heap->array[i], &heap->array[largest]);
        heapify(heap, largest);
    }
}

// Function to build a max heap from an existing array
// Complexity: O(n * log n)
void buildHeap(Heap *heap)
{
    int n = heap->size;
    for (int i = (n - 1) / 2; i >= 0; i--)
        heapify(heap, i);
}

// Function to insert a new value into the heap
void insertHeap(Heap *heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = value;

    // Fix the heap property if it is violated
    while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the root (maximum element)
int extractMax(Heap *heap)
{
    if (heap->size <= 0) return INT_MIN;
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return root;
}

void printHeap(Heap *heap)
{
    for (int i = 0; i < heap->size; ++i)
        printf("%d ", heap->array[i]);
    printf("\n");
}

int main()
{
    Heap *heap = createHeap(10);

    insertHeap(heap, 3);
    insertHeap(heap, 2);
    insertHeap(heap, 15);
    insertHeap(heap, 5);
    insertHeap(heap, 4);
    insertHeap(heap, 45);

    printf("Max Heap array: ");
    printHeap(heap);

    printf("Extracted max value: %d\n", extractMax(heap));
    printf("Max Heap array after extraction: ");
    printHeap(heap);

    free(heap->array);
    free(heap);
    return 0;
}