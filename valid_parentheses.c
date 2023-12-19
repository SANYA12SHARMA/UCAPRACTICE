#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct Stack
{
    int top;
    char arr[10000];
};

bool isFull(struct Stack *mystack, int size)
{
    return mystack->top == size - 1;
}

bool isEmpty(struct Stack *mystack)
{
    return mystack->top == -1;
}

void push(char element, struct Stack *mystack, int size)
{
    if (isFull(mystack, size))
    {
        return;
    }
    mystack->arr[++mystack->top] = element;
}

void pop(struct Stack *mystack)
{
    if (isEmpty(mystack))
    {
        return;
    }
    mystack->top--;
}

char top(struct Stack *mystack)
{
    if (isEmpty(mystack))
    {
        return '0';
    }
    return mystack->arr[mystack->top];
}

bool isValid(char *s)
{
    struct Stack myStack;
    myStack.top = -1;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            push(s[i], &myStack, len);
        }
        else
        {
            if (isEmpty(&myStack))
            {
                return false;
            }
            else
            {
                char topEle = top(&myStack);
                if ((topEle == '{' && s[i] == '}') ||
                    (topEle == '(' && s[i] == ')') ||
                    (topEle == '[' && s[i] == ']'))
                {
                    pop(&myStack);
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if (isEmpty(&myStack))
    {
        return true;
    }
    return false;
}
int main()
{
    printf("Enter Input String:\n");
    // input string
    char s[10000];

    scanf("%s", s);
    bool ans = isValid(s);
    if (ans)
    {
        printf("Valid Parentheses");
    }
    else
    {
        printf("Not Valid Parentheses");
    }
}