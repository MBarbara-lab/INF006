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
    // new->items = malloc(tam * sizeof(int));
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

int search (Queue * q, int value) {
    int i = q->front;
    while (i != q->rear) {
        if (q->items[i] == value) return i;
        i = (i + 1) % q->tam;
    }
    printf("Item nao encontrado!\n");
    return -1;
}

void deleteItem (Queue * q, int value) {
    int position = search(q, value);
    if (position == -1) return;

    int current = position;
    int next = (position + 1) % q->tam;

    while (next != q->rear) {
        q->items[current] = q->items[next]; 
        current = next;                     
        next = (next + 1) % q->tam;         
    }

    q->rear = (q->rear - 1 + q->tam) % q->tam;
}

int main()
{
    int vetor [10];

    Queue * q1 = createQueue(5);
    Queue * q2 = createQueue(5);

    q1->items = &vetor[0];
    q2->items = &vetor[5];
    
    enqueue(q1, 12);
    enqueue(q1, 16);
    enqueue(q1, 10);
    enqueue(q1, 4);
    printQueue(q1);

    enqueue(q2, 54);
    enqueue(q2, 66);
    enqueue(q2, 88);
    printQueue(q2);

    dequeue(q1);

    deleteItem(q1, 10);
    printQueue(q1);
}