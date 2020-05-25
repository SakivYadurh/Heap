#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/***************** GLOBAL VARIABLE ------------ PATH TO THE ARCHIVE DIRECTORY *****************/

char glo_path[100] = "D:\\Files\\Workspace - C\\SEM 2 - Course Project\\Archives\\";

/********* !! DO NOT FORGET TO CHANGE THE DIRECTORIES OR ADDRESSES ABOVE ACCORDINGLY **********/
/* DIRECTORY MUST HAVE "titles.txt" CONTAINING TITLES OF THE DOCUMENTS FOR THE SEARCH TO WORK */


// Structure of nodes which form a BST, whose inorder traversal gives a priority order
typedef struct node {
    int data;
    char title[50];
    struct node *left, *right;
} NODE;
NODE *root = NULL;

// Structure of nodes which form a queue of search results
typedef struct q_node{
    int words;
    char title[50];
    struct q_node *next;
} Access_Queue;
Access_Queue *r=NULL, *f=NULL, *q, *t;

// Structure of nodes which store history of visited titles in a stack
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


/******************** QUEUE OPERATIONS ******************/
void insert(int n, char s[]){
    q=(Access_Queue *)malloc(sizeof(Access_Queue));
    strcpy(q -> title, s);
    q -> words = n;
    q -> next = NULL;
    if(r==NULL || f==NULL)
        f = r = q;
    else{
        r -> next = q;
        r = q;
    }
}
void delete(){
    q = f;
    f = f -> next;
    free(q);
    if(f==NULL)
        r = NULL;
}
void q_display(){
    int i = 1, choice;
    char filename[50], temp[50], ch;
    char rel_path[100];
    strcpy(rel_path, glo_path);
    FILE *fp;
    if(f==NULL || r==NULL){
        printf("Your search did not match any documents\n Suggestions:\n");
        printf("1. Make sure all the words are spelled correctly.\n2. Try more general keywords.\n");
    }
    else{
        t = q = f;
        while(q != NULL){
            printf("%d. %s\n\tTotal number of words in this document - %d\n\n",i++, q -> title, q -> words);
            q = q -> next;
        }
        printf("\nEnter the number corresponding to the document to access it: ");
        scanf("%d",&choice);
        system("cls");
        if(choice>=i)
            printf("WRONG CHOICE SELECTED\n");
        else if(choice==1)
            strcpy(filename, t -> title);
        else{
            while(choice!=1){
                t = t -> next;
                choice--;
            }
            strcpy(filename, t -> title);
        }
        strcpy(temp, filename);
        fp = fopen(strcat(rel_path, strcat(temp, ".txt")),"r");
        while((ch=getc(fp))!=EOF)
            printf("%c",ch);
        strcpy(rel_path, glo_path);
    }
}
/****************** QUEUE OPERATIONS END ******************/


/****************** BST OPERATIONS ******************/
void bst_for_sorting(int words, char s[]) {
    int flag;
    NODE *new, *current;
    flag = 1;
    current = root;
    new = (NODE*)malloc(sizeof(NODE));
    new -> left = NULL;
    new -> right = NULL;
    new -> data = words;    
    strcpy(new -> title, s);
    if(root == NULL) {
        root = new;
        flag = 0;
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
    insert(ptr -> data, ptr -> title);
    if(ptr -> right != NULL)
        inorder(ptr -> right);
}

void clear_bst(NODE *ptr) {
    if(ptr -> left != NULL)
        clear_bst(ptr -> left);
    if(ptr -> right != NULL)
        clear_bst(ptr -> right);
    free(ptr);
}
/****************** BST OPERATIONS END ******************/


// WORD COUNT FINDER
void count(FILE *fp, char s[]){
    int words=1;
    char ch;
    while((ch=getc(fp))!=EOF){
        if(ch==' ')
            words++;
    }
    bst_for_sorting(words, s);
}


// SEARCH OPERATIONS
void searching(){
    char rel_path[100];
    strcpy(rel_path, glo_path); 
    char search[50],title[50], temp[50],ch, ch1;
    int i=0,l,j=0;
    printf("Enter any keyword related to the document you are searching for.\nKeyword: ");
    scanf("%s",search);
    push(search);
    system("cls");
    printf("Search Keyword: \"%s\"\n\n\n",search);
    l=strlen(search);
    FILE *fp1,*fp2;
    fp1=fopen(strcat(rel_path, "titles.txt") ,"r");
    strcpy(rel_path, glo_path);
    while((ch=getc(fp1))!=EOF){
        if(ch!='\n')
            title[j++]=ch;
        if(ch==search[i]&&i<l)
            i++;
        else if(i==l){
            if(ch!='\n') {
                while((ch1=getc(fp1))!='\n')
                    title[j++]=ch1;
            }
            title[j]='\0';
            i=0;
            j=0;
            strcpy(temp, title);
            fp2=fopen(strcat(rel_path, strcat(temp, ".txt")),"r");
            count(fp2,title);
            strcpy(rel_path, glo_path);
        }
        else
            i=0;
        if(ch=='\n'){
            i=j=0;
        }
    }
    if(root!=NULL)
        inorder(root);
    q_display();
    while(f!=NULL || r!=NULL)
        delete();
    if(root!=NULL)
        clear_bst(root);
    root = NULL;
    printf("\n\nTo Go back to main menu, ");
        system("pause");
    system("cls");
}


// HISTORY
void history() {
    int choice = 0, t = 0;
    if(top==NULL){
        printf("No History\n");
        system("pause");
    }
    else{
        printf("YOUR HISTORY\n\n");
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


// MAIN FUNCTION
int main() {
    int choice;
    char change_dir[100];
    //clrscr();
    do {
        printf("MAIN MENU\n\n");
        printf("1. Search\n2. History\n\nAny other number to exit\n\nEnter your choice: ");
        scanf("%d",&choice);
        system("cls"); // Console screen is CLEARED. i.e., Main screen instructions disappear and Search/History instructions appear
        if(choice==1) {
            searching();
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
