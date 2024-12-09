#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}Stack;
void push(Stack** top,int ele){
    Stack* newnode=(Stack*)malloc(sizeof(Stack));
    if(newnode==NULL){
        printf("Stack Overflow");
    }else{
        newnode->data=ele;
        newnode->next=*top;
        *top=newnode;
    }
}
void pop(Stack** top){
  if(*top==NULL){
    printf("Stack underflow");
  } 
  Stack* temp=*top;
  *top=(*top)->next;
  free(temp);
}
void peek(Stack** top){
    if(*top==NULL){
        printf("Stack Underflow");
    }else{
        printf("%d is the peek element\n",(*top)->data);
    }
}   
void printnode(Stack* top){
    if(top==NULL){
        printf("Stack Empty");
    }else{
        Stack* temp=top;
        while(temp!=NULL){
                printf("%d ",temp->data);
                temp=temp->next;
            }
        }
}
int main(){
    Stack* top = NULL;
    push(&top,10);
    push(&top,1);
    push(&top,14);
    push(&top,43);
    push(&top,3);
    push(&top,90);
    pop(&top);
    pop(&top);
    peek(&top);
    push(&top,1000);
    printnode(top);
}