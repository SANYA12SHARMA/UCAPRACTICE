#include <stdio.h>
#include <stdbool.h>
typedef struct
{
    int *arr;
    int front;
    int rear;
    int capacity;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k)
{
    MyCircularQueue *queue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    queue->front = 0;
    queue->rear = 0;
    queue->arr = (int *)malloc((k + 1) * sizeof(int));
    queue->capacity = k + 1;
    return queue;
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
    return obj->front == obj->rear;
}

bool myCircularQueueIsFull(MyCircularQueue *obj)
{
    return (obj->rear + 1) % obj->capacity == obj->front;
}
bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
    if (myCircularQueueIsFull(obj))
    {
        return false;
    }
    obj->arr[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->capacity;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    obj->front = (obj->front + 1) % obj->capacity;
    return true;
}

int myCircularQueueFront(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->arr[(obj->rear - 1 + obj->capacity) % obj->capacity];
}
void myCircularQueueFree(MyCircularQueue *obj)
{
    free(obj->arr);
    free(obj);
}