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
int pop(Stack* mystack){
    if(isEmpty(mystack)){
        return -1;
    }
    return mystack->arr[mystack->top--];
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
char* removeDuplicateLetters(char* s) {
    int charLastIndex[26] = {0};
    bool visited[26] = {false};
    for(int i = 0;i < strlen(s);i++){
        charLastIndex[s[i] - 'a'] = i;
    }
    Stack *mystack = createStack(strlen(s));
    for(int i = 0; i < strlen(s);i++){
        int currentChar = s[i] - 'a';
        if(visited[currentChar]){
            continue;
        }
        visited[currentChar] = true;
        while(!isEmpty(mystack) && top(mystack) > currentChar && charLastIndex[top(mystack)] > i){
            visited[pop(mystack)] = false;
        }
        push(mystack,currentChar);
    }
    int stackSize = mystack->top + 1;
    char *ch = (char*)malloc((stackSize+1)*sizeof(char));
    int i = stackSize-1;
    while(!isEmpty(mystack)){
       ch[i--] = pop(mystack)+'a'; 
    }
    ch[stackSize] = '\0';
    freeObjects(mystack);
    return ch;
}
int main(){
    assert(strcmp(removeDuplicateLetters("bcabc"),"abc")==0);
    assert(strcmp(removeDuplicateLetters("cbacdcbc"), "acdb")==0);
    printf("Test cases running successfully");
}