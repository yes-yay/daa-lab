//sri rama jayam 
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

struct Stack {
    struct Queue* queue1;
    struct Queue* queue2;
};

// Function to initialize a queue
void initializeQueue(struct Queue* queue) {
    queue->front = queue->rear = -1;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Function to enqueue an element to the queue
void enqueue(struct Queue* queue, int data) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    
    if (queue->front == -1) {
        queue->front = 0;
    }
    
    queue->arr[++queue->rear] = data;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return some error value
    }
    
    int data = queue->arr[queue->front];
    
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    
    return data;
}

// Function to initialize a stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->queue1 = (struct Queue*)malloc(sizeof(struct Queue));
    stack->queue2 = (struct Queue*)malloc(sizeof(struct Queue));
    initializeQueue(stack->queue1);
    initializeQueue(stack->queue2);
    return stack;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    enqueue(stack->queue1, data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isQueueEmpty(stack->queue1)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return some error value
    }
    
    while (!isQueueEmpty(stack->queue1) && stack->queue1->front != stack->queue1->rear) {
        enqueue(stack->queue2, dequeue(stack->queue1));
    }
    
    int data = dequeue(stack->queue1);
    
    struct Queue* temp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = temp;
    
    return data;
}

int main() {
    struct Stack* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));

    return 0;
}