#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node * prev;
    struct Node * next;
} Node;

typedef struct List {
    Node * head;
    int size;
} List;

void insertOrderedNode (List * list, Node * new) {
    Node * current;

    if (list->head) {
        current = list->head;

        while (current->next != list->head && current->next->key < new->key) {
            current = current->next;
        }

        new->next = current->next;
        new->prev = current;

        current->next->prev = new;
        current->next = new;
    } else {
        new->next = new;
        new->prev = new;
        list->head = new;
    }

}

int main () {
    List * lista = malloc(sizeof(List));
    Node * n1 = malloc(sizeof(Node));

    insertOrderedNode (lista, n1);

    Node * current = lista->head;
    while (current->next !)

    free(lista);
    free(n1);
}