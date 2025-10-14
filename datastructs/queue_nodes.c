#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Node *head;
    Node *tail;
} Queue;

Queue *create() {
    return malloc(sizeof(Queue));
}

void enqueue(Queue *queue, int item) {
    Node *tmp = malloc(sizeof(Node));
    tmp->data = item;
    
    if(queue->head == NULL) {
        queue->head = tmp;
        queue->tail = tmp;
    } else {
        queue->head->next = tmp;
        queue->head = tmp;
    }
}

int dequeue(Queue *queue, int *out) {
    if(queue->head == NULL) {
        return 0;
    }

    if(queue->tail == NULL) {
        *out = queue->head->data;
        queue->head = NULL;
    } else {
        *out = queue->tail->data;
        queue->tail = queue->tail->next;
    }

    return 1;
}

int isempty(Queue *queue) {
    if(queue->head == NULL) {
        return 1;
    }

    return 0;
}

void print_queue(Queue *queue) {
    Node *p = queue->tail;
    while(p != NULL) {
        printf("<-(%i)", p->data);
        p = p->next;
    }

    printf("<-NULL\n");
}

int main() {
    Queue *q = create();
    enqueue(q, 3);
    enqueue(q, 2);
    enqueue(q, 1);
    enqueue(q, 0);

    print_queue(q);
    printf("%i %i\n", q->head->data, q->tail->data);
    
    int out;
    dequeue(q, &out);
    dequeue(q, &out);
    dequeue(q, &out);

    print_queue(q);
    printf("%i %i\n", q->head->data, q->tail->data);
    
    dequeue(q, &out);
    dequeue(q, &out);
    dequeue(q, &out);

    print_queue(q);
    printf("%s %s\n", q->head, q->tail);
    
    enqueue(q, 3);
    enqueue(q, 2);
    printf("%i %i\n", q->head->data, q->tail->data);
    dequeue(q, &out);
    enqueue(q, 0);

    print_queue(q);
    printf("%i %i\n", q->head->data, q->tail->data);
    
    return 1;
}
