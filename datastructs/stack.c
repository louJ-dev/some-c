#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct {
    Node* top;
} Stack;

Stack* create_stack();
int stack_isempty(Stack* stack);
void push_stack(Stack* stack, int item);
int peek_stack(Stack* stack, int *out);
int pop_stack(Stack* stack, int *out);
void destroy_stack(Stack* stack);
void print_stack(Stack* stack);

int main() {
    Stack* stack = create_stack();
    push_stack(stack, 0);
    push_stack(stack, 1);
    push_stack(stack, 2);
    push_stack(stack, 3);
    push_stack(stack, 4);

    print_stack(stack);

    int out;
    pop_stack(stack, &out);
    print_stack(stack);
    pop_stack(stack, &out);
    print_stack(stack);
    pop_stack(stack, &out);
    print_stack(stack);
    push_stack(stack, 2);
    push_stack(stack, 3);
    push_stack(stack, 4);
    print_stack(stack);

    destroy_stack(stack);
    print_stack(stack);
}


Stack* create_stack() {
    Stack* stack = malloc(sizeof(Stack));
    return stack;
}

int stack_isempty(Stack* stack) {
    if(stack->top == NULL) {
        return 1;
    }

    return 0;
}

void push_stack(Stack* stack, int item) {
    if(stack_isempty(stack)) {
        stack->top = malloc(sizeof(Node));
        stack->top->data = item;
    } else {
        Node* tmp = stack->top;
        stack->top = malloc(sizeof(Node));
        stack->top->data = item;
        stack->top->next = tmp;
    }
}

int peek_stack(Stack* stack, int *out) {
    if(stack->top == NULL) {
        return 0;
    }
    
    *out = stack->top->data;
    return 1;
}

int pop_stack(Stack* stack, int *out) {
    if(stack->top == NULL) {
        return 0;
    }

    *out = stack->top->data;
    stack->top = stack->top->next;
    return 1;
}

void destroy_stack(Stack* stack) {
    Node* p = stack->top;
    while(p != NULL) {
        Node* tmp = p->next;
        free(p);
        p = tmp;
    }

    free(stack);
}

void print_stack(Stack* stack) {
    Node* p = stack->top;
    printf("[");
    while(p != NULL) {
        printf("%i, ", p->data);
        p = p->next;
    }
    printf("]\n");
}

