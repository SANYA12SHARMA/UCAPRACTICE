#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
typedef struct{
    int top;
    char *arr;
    int capacity;
}Stack;
Stack* createStack(int maxSize){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = maxSize;
    stack->arr = (char*)malloc(maxSize*sizeof(char));
    return stack;
}
bool isFull(Stack *mystack)
{
    return mystack->top == mystack->capacity - 1;
}

bool isEmpty(Stack *mystack)
{
    return mystack->top == -1;
}

void push(char element, Stack *mystack)
{
    if (isFull(mystack))
    {
        return;
    }
    mystack->arr[++mystack->top] = element;
}

void pop(Stack *mystack)
{
    if (isEmpty(mystack))
    {
        return;
    }
    mystack->top--;
}

char top(Stack *mystack)
{
    if (isEmpty(mystack))
    {
        return '0';
    }
    return mystack->arr[mystack->top];
}

bool isValid(char *s){
    int len = strlen(s);
    Stack *myStack = createStack(len);
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            push(s[i],myStack);
        }
        else
        {
            if (isEmpty(myStack))
            {
                return false;
            }
            else
            {
                char topEle = top(myStack);
                if ((topEle == '{' && s[i] == '}') ||
                    (topEle == '(' && s[i] == ')') ||
                    (topEle == '[' && s[i] == ']'))
                {
                    pop(myStack);
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if (isEmpty(myStack))
    {
        return true;
    }
    return false;
}
int main()
{
    assert(isValid("()[]{}") == true);
    assert(isValid("(])") == false);
    printf("Test cases running successfully");
}