#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int *main;
    int top;
    int size;
}stack;
stack* createstack(stack* Stack,int max){
    Stack->main=(int*)malloc(max*sizeof(int));
    Stack->top=-1;
    Stack->size=max;
}
stack* push(stack* Stack,int num){
    if(Stack->top==Stack->size-1){
        printf("Stack Overflow");
    }else{
        Stack->main[++Stack->top]=num;
    }
    return Stack;
}
stack* pop(stack* Stack){
    if(Stack->top==-1){
        printf("Stack underflow");
    }else{
        Stack->top--;
    }
    return Stack;
}
void peek(stack* Stack){
    if(Stack->top==-1){
        printf("Stack is empty");
        return;
    }
    printf("%d is the peek\n",Stack->main[Stack->top]);
}
void printstack(stack* Stack){
    int index=0;
    while(index!=Stack->top){
        printf("%d ",Stack->main[index]);
        index++;
    }
}
int main(){
    stack* Newstack=(stack*)malloc(sizeof(stack));
    Newstack=createstack(Newstack,10);
    Newstack=push(Newstack,10);
    Newstack=push(Newstack,12);
    Newstack=push(Newstack,113);
    Newstack=push(Newstack,1);
    Newstack=push(Newstack,9);
    Newstack=push(Newstack,13);
    Newstack=pop(Newstack);
    Newstack=pop(Newstack);
    peek(Newstack);
    Newstack=push(Newstack,3);
    printstack(Newstack);
}