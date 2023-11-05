#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int arr[100];
    int top;
};

struct Queue {
    struct Stack* stack1;
    struct Stack* stack2;
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}
void push(struct Stack* stack, int data) {
    if (stack->top >= 99) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->arr[++stack->top] = data;
}
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty");
    }
    return stack->arr[stack->top--];
}
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack();
    queue->stack2 = createStack();
    return queue;
}
void enqueue(struct Queue* queue, int data) {
    push(queue->stack1, data);
}
int dequeue(struct Queue* queue) {
    if (queue->stack1->top == -1 && queue->stack2->top == -1) {
        printf(" Cant dequeue.\n");
        return -1;
    }
 if (queue->stack2->top == -1) {
        while (queue->stack1->top != -1) {
            push(queue->stack2, pop(queue->stack1));
        }
    }
return pop(queue->stack2);
}

int main() {
    struct Queue* queue = createQueue();
  enqueue(queue, 78);
    enqueue(queue, 199);
    enqueue(queue, 69);
 printf("Dequeued: %d\n", dequeue(queue));
 printf("Dequeued: %d\n", dequeue(queue));
 printf("Dequeued: %d\n", dequeue(queue));

    return 0;
}