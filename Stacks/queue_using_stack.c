#include <stdbool.h>
#include <stdlib.h>
struct Stack
{
    int top;
    int *arr;
};
bool isEmpty(struct Stack *mystack)
{
    return mystack->top == -1;
}
struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->arr = (int *)malloc(capacity * sizeof(int));
    return stack;
}
void push(struct Stack *mystack, int x)
{
    mystack->arr[++mystack->top] = x;
}
int pop(struct Stack *mystack)
{
    if (isEmpty(mystack))
    {
        return -1;
    }
    int temp = mystack->arr[mystack->top--];
    return temp;
}
int peek(struct Stack *mystack)
{
    if (isEmpty(mystack))
    {
        return -1;
    }
    int temp = mystack->arr[mystack->top];
    return temp;
}
typedef struct
{
    struct Stack *s1;
    struct Stack *s2;

} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
    queue->s1 = createStack(100);
    queue->s2 = createStack(100);
    return queue;
}

void myQueuePush(MyQueue *obj, int x)
{
    push(obj->s1, x);
}

int myQueuePop(MyQueue *obj)
{
    if (isEmpty(obj->s1))
    {
        return -1;
    }
    while (!isEmpty(obj->s1))
    {
        push(obj->s2, pop(obj->s1));
    }
    int temp = pop(obj->s2);
    while (!isEmpty(obj->s2))
    {
        push(obj->s1, pop(obj->s2));
    }
    return temp;
}

int myQueuePeek(MyQueue *obj)
{
    if (isEmpty(obj->s1))
    {
        return -1;
    }
    while (!isEmpty(obj->s1))
    {
        push(obj->s2, pop(obj->s1));
    }
    int temp = peek(obj->s2);
    while (!isEmpty(obj->s2))
    {
        push(obj->s1, pop(obj->s2));
    }
    return temp;
}

bool myQueueEmpty(MyQueue *obj)
{
    return isEmpty(obj->s1);
}

void myQueueFree(MyQueue *obj)
{
    free(obj);
}