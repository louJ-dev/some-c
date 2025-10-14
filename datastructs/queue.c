#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int size;
    int capacity;
    int *collection;
} Queue;

Queue *create_queue(int capacity); 
int queue_isempty(Queue *queue);
int queue_isfull(Queue *queue);
void enqueue(Queue *queue, int item);
int dequeue(Queue *queue, int *out);
int seek(Queue *queue, int *out);
void delete_queue(Queue *queue);
void print_queue(Queue *queue);

int main() {
    Queue *q = create_queue(4);
    
    print_queue(q);
    
    for(int i = 0; i < 4; i++) {
        enqueue(q, i);
        print_queue(q);
    }

    int out;
    for(int i = 0; i < 4; i++) {
        dequeue(q, &out);
        print_queue(q);
    }

    for(int i = 0; i < 16; i++) {
        enqueue(q, i);
        print_queue(q);
    }

    delete_queue(q);
    // print_queue(q);

    return 0;
}

Queue *create_queue(int capacity) {
    Queue *queue = malloc(sizeof(Queue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->collection = malloc(sizeof(int) * capacity);

    return queue;
}

int queue_isempty(Queue *queue) {
    if(queue->size == 0) {
        return 1;
    }

    return 0;
}

int queue_isfull(Queue *queue) {
    if(queue->size >= queue->capacity) {
        return 1;
    }

    return 0;
}

void enqueue(Queue *queue, int item) {
    if(queue_isfull(queue)) {
        queue->capacity += 8;
        queue->collection = realloc(queue->collection, sizeof(int) * queue->capacity);
    }

    queue->collection[queue->size] = item;
    queue->size++;
}

int dequeue(Queue *queue, int *out) {
    if(queue_isempty(queue)) {
        return 0;
    }
    
    out = &queue->collection[0];
    
    for(int i = 0; i < queue->size; i++) {
        queue->collection[i] = queue->collection[i + 1]; 
    }

    //queue->collection++;
    queue->size--;

    return 1;
}

int seek(Queue *queue, int *out) {
    if(queue_isempty(queue)) {
        return 0;
    }

    out = &queue->collection[queue->size - 1];

    return 1;
}

void delete_queue(Queue *queue) {
    free(queue->collection);
    free(queue);
    queue = NULL;
}

void print_queue(Queue *queue) {
    if(queue_isempty(queue)){
        printf("queue is empty\n");
        return;
    }

    printf("[");

    for(int i = 0; i < queue->size - 1; i++) {
        printf("%i, ", queue->collection[i]);
    }

    printf("%i]\n", queue->collection[queue->size - 1]);
}
