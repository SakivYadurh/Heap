#include<stdio.h>
#include<stdlib.h>

typedef struct hstr_node {
    char title[50];
    struct hstr_node *next;
} Hstr_List;

Hstr_List *top = NULL;
Hstr_List *p;

void push(char* s) {
    p = (Hstr_List *)malloc(sizeof(Hstr_List));
    p -> title=s;
    /* For some reason, %[^\n]%*c wont work */
    p -> next = top;
    top = p;
}

int pop() {
    p = top;
    if(p==NULL)
        return 1;
    top = top -> next;
    printf("%s cleared from the history\n",p->title);
    free(p);
    return 0;
}

void display() {
    p = top;
    while(p != NULL) {
        printf("%s\n", p -> title);
        p = p -> next;
    }
    printf("\n");
}
void searching(){
    char search[50];
    scanf("%s",&search);
    push(search);
}

int main() {
    int choice,t=0;
    clrscr();
    printf("1. Search\n2. History\nEnter your choice:");
    scanf("%d",&choice);
    if(choice==1){
        choice=0;
        searching();
        /*Still to be continued*/
    }
    else if(choice==2){
        choice=0;
        if(top==NULL)
            printf("No History\n");
        else{
            printf("Your History\n");
            dispaly();
        }
        printf("1. Clear history\n2. Search\nEnter your choice:");
        scanf("%d",&choice);
        if(choice==1){
            choice=0;
            printf("1. CLear recent history\n2.Clear entire history\nEnter your choice:");
            scanf("%d",&choice);
            if(choice==1)
                pop();
            else if(choice==2){
                choice=0;
                while(1){
                    if(t==1){
                        printf("Entire History Cleared\n")
                        break();
                    }
                    t=pop();
                }
            }
        }
        else if(choice==2){
            choice=0;
            searching();
        }
    }
}
