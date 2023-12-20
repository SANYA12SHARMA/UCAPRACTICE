#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
typedef struct{
    int top;
    int *arr;
    int capacity;
}Stack;
Stack* createStack(int size){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = size;
    stack->arr = (int*)malloc(size*sizeof(int));
    return stack;
}
void push(Stack* mystack,int val){
    if(mystack->top == mystack->capacity - 1){
        return;
    }
    mystack->arr[++mystack->top] = val;
}
bool isEmpty(Stack* mystack){
    return (mystack->top == -1);
}
void pop(Stack* mystack){
    if(isEmpty(mystack)){
        return ;
    }
    mystack->top--;
}
int top(Stack* mystack){
    if(isEmpty(mystack)){
        return -1;
    }
    return mystack->arr[mystack->top];
}
void freeObjects(Stack* mystack){
    free(mystack->arr);
    free(mystack);
}
int longestValidParentheses(char* s) {
    int len = strlen(s);
    Stack *myStack = createStack(len);
    push(myStack,-1);
    int maxLen = 0;
    for(int i = 0; i < len; i++){
        char ch = s[i];
        if(ch == '('){
            push(myStack,i);
        }else{
            if(!isEmpty(myStack)){
                pop(myStack);
            }
            if(!isEmpty(myStack)){
                int currLen = i - top(myStack);
                if( currLen > maxLen){
                    maxLen = currLen;
                }
            }
            else{
                push(myStack,i);
            }
        }
    }
    return maxLen;
}
int main(){
    assert(longestValidParentheses("(()") == 2);
    assert(longestValidParentheses(")(()))()") == 4);
    printf("Test cases running successfully");
}