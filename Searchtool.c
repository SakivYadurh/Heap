#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int data;
    struct node *left, *right;
} NODE;
NODE *root = NULL;

// Structure of nodes storing history of visited titles in a stack
typedef struct hstr_node {
    char title[50];
    struct hstr_node *next;
} Hstr_List;

Hstr_List *top = NULL;
Hstr_List *p;


/******************** STACK OPERATIONS ********************/
void push(char s[]) {
    p = (Hstr_List *)malloc(sizeof(Hstr_List));
    strcpy(p -> title, s);
    p -> next = top;
    top = p;
}

int pop() {
    p = top;
    if(p==NULL)
        return 1;
    top = top -> next;
    printf(" \"%s\" cleared from the history\n",p->title);
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

NODE *bst_for_sorting(int words) {
    int flag;
    NODE *new, *current;
        flag = 1;
        current = root;
        new = (NODE*)malloc(sizeof(NODE));
        new -> left = NULL;
        new -> right = NULL;
        new -> data = words;
        if(root == NULL) {
            root = new;
            //continue;
        }
        while(flag) {
            if(new -> data > current -> data) {
                if(current -> right == NULL) {
                    current -> right = new;
                    flag = 0;
                }
                else
                    current = current -> right;
            }
            else {
                if(current -> left == NULL) {
                    current -> left = new;
                    flag = 0;
                }
                else
                    current = current -> left;
            }
        }
}
void inorder(NODE *ptr) {
    if(ptr -> left != NULL)
        inorder(ptr -> left);
    printf("%d ", ptr -> data);     //Should change this to push the data into QUEUE
    if(ptr -> right != NULL)
        inorder(ptr -> right);
}

void count(FILE *fp){
    int words=1;
    char ch;
    while((ch=getc(fp))!=EOF){
        if(ch==' ')
            words++;
    }
    bst_for_sorting(words);
}


// SEARCH OPERATIONS
void searching(){
    char search[50],ch;
    int i=0,l,f=1;
    printf("Enter Statement: ");
    scanf("%s",search);
    push(search);
    system("cls");
    l=strlen(search);
    FILE *fp1,*fp2;
    fp1=fopen("titles","r");
    while((ch=getc(fp1))!=EOF){
        if(ch==search[i]&&i<l)
            i++;
        else if(i==l){
            if(f==1)
                fp2=fopen("f1","r");
            if(f==2)
                fp2=fopen("f2","r");
            if(f==3)
                fp2=fopen("f3","r");
            if(f==4)
                fp2=fopen("f4","r"); 
            if(f==5)
                fp2=fopen("f5","r");
            if(f==6)
                fp2=fopen("f6","r");            
            if(f==7)
                fp2=fopen("f7","r");
            if(f==8)
                fp2=fopen("f8","r");
            if(f==9)
                fp2=fopen("f9","r");
            if(f==10)
                fp2=fopen("f10","r");
            count(fp2);
        }
        else
            i=0;
        if(ch=='\n')
            f++;
    }
    inorder(root);
    //To be continued
}


// HISTORY
void history() {
    int choice = 0, t = 0;
    if(top==NULL){
        printf("No History\n");
        system("pause");
    }
    else{
        printf("Your History\n");
        display();
        printf("1. Clear recent history\n2. Clear entire history\n3. Go back to main menu\n\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice==1){
            pop();
            system("pause");
        }
        else if(choice==2){
            choice=0;
            while(1){
                if(t==1){
                    printf("\nEntire History Cleared . . .\n");
                    system("pause");
                    break;
                }
                t=pop();
            }
        }
        else if(choice==3){
            system("cls");
            return;
        }
    }
    system("cls"); // Console screen is CLEARED. i.e., History instructions disappear and Main Menu instructions appear
}

int main() {
    int choice;
    //clrscr();
    do {
        printf("MAIN MENU\n\n1. Search\n2. History\n\nAny other number to exit\n\nEnter your choice:");
        scanf("%d",&choice);
        system("cls"); // Console screen is CLEARED. i.e., Main screen instructions disappear and Search/History instructions appear
        if(choice==1){
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
