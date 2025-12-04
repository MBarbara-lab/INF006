#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *items;
    int front;
    int rear;
    int tam;
} Queue;

Queue *createQueue(int tam)
{
    Queue *new = malloc(sizeof(Queue));
    new->items = malloc(tam * sizeof(int));
    new->front = new->rear = 0;
    new->tam = tam;
    return new;
}

bool isEmpty(Queue * queue) { 
    return (queue->front == queue->rear); 
}

bool isFull(Queue * queue) {
    return (queue->front == ((queue->rear + 1) % queue->tam)); 
}

void enqueue(Queue * queue, int value)                          // adiciona um valor à fila
{
    if (isFull(queue))
    {
        printf("Queue is full!\n");
        return;
    }
    queue->items[queue->rear] = value;

    queue->rear = (queue->rear + 1) % queue->tam;               // V1 - verificação com %
}

void dequeue(Queue * queue)                                     // retira um valor da fila
{
    if (isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return;
    }

    if (queue->front + 1 == queue->tam) queue->front = 0;       // V2 - verificação com if/else
    else queue->front++;                                          
}

int peek(Queue * queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[queue->front];
}

void printQueue(Queue * queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Current Queue: ");
    int i = queue->front;
    while (i != queue->rear)
    {
        printf("%d ", queue->items[i]);
        i = (i + 1) % queue->tam;
    }
    printf("\n");
}

int main()
{
    Queue * q = createQueue(10);

    enqueue(q, 10);
    printQueue(q);

    enqueue(q, 20);
    printQueue(q);

    enqueue(q, 30);
    printQueue(q);

    printf("Front element: %d\n", peek(q));

    dequeue(q);
    printQueue(q);

    printf("Front element after dequeue: %d\n", peek(q));

    free(q->items); free(q);            // liberar espaço após malloc
    return 0;
}