#include<stdio.h>
#include<stdlib.h>

// Structure of nodes storing history of visited titles in a stack
typedef struct hstr_node {
    char* title;
    struct hstr_node *next;
} Hstr_List;

Hstr_List *top = NULL;
Hstr_List *p;


/******************** STACK OPERATIONS ********************/
void push(char* s) {
    p = (Hstr_List *)malloc(sizeof(Hstr_List));
    p -> title=s;
    /* ERROR - LINE 17 : assignment to expression with array type. idk what and why atleast for now */
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
/****************** STACK OPERATIONS END ******************/


// SEARCH OPERATIONS
void searching(){
    char search[50];
    scanf("%s",search);
    push(search);
}


// HISTORY
void history() {
    int choice = 0, t = 0;
    if(top==NULL)
        printf("No History\n");
    else{
        printf("Your History\n");
        display();
        printf("1. Clear recent history\n2. Clear entire history\n3. Go back to main menu\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice==1){
            pop();
            printf("Recent History Cleared...\nPress any key to go back to main menu... \n");
            t = getchar();
        }
        else if(choice==2){
            choice=0;
            while(1){
                if(t==1){
                    printf("Entire History Cleared...\nPress any key to go back to main menu... \n");
                    t = getchar();
                    break;
                }
                t=pop();
            }
        }
        else if(choice==3){
            return;
        }
    }
    system("cls"); // Console screen is CLEARED. i.e., History instructions disappear and Main Menu instructions appear
}

int main() {
    int choice;
    clrscr();
    do {
        printf("MAIN MENU\n\n1. Search\n2. History\n\nAny other number to exit\n\nEnter your choice:");
        scanf("%d",&choice);
        system("cls"); // Console screen is CLEARED. i.e., Main screen instructions disappear and Search/History instructions appear
        if(choice==1){
            choice=0;
            searching();
            /*Still to be continued*/
        }
        else if(choice==2) {
            history();
        }
        else{
            printf("Exiting Application...\n");
        }
    } while(choice > 0 && choice <3);
    return 0;
}
