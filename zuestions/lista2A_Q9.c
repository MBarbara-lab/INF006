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

typedef struct PriorityQueue
{
    Queue * p1;
    Queue * p2;
} PriorityQueue;

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
    PriorityQueue * listaPrioridade = malloc(sizeof(PriorityQueue));
    listaPrioridade->p1 = createQueue(10);
    listaPrioridade->p2 = createQueue(10);

    int valor, prioridade;

    printf("Indique o valor e a prioridade de insercao: \n");
    scanf("%d %d", &valor, &prioridade);
    while (valor)
    {
        if (prioridade == 1) {
            enqueue(listaPrioridade->p1, valor);
            printQueue(listaPrioridade->p1);
        } else if (prioridade == 2) {
            enqueue(listaPrioridade->p2, valor);
            printQueue(listaPrioridade->p2);
        }

        printf("Indique o valor e a prioridade de insercao: \n");
        scanf("%d %d", &valor, &prioridade);
    }
}