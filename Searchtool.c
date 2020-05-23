#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    char[40] title;
    struct node *next;
} NODE;

NODE *top = NULL;
NODE *p;

void push() {
    p = (NODE *)malloc(sizeof(NODE));
    printf("Enter the String : ");
    scanf("%[^\n]%*c", &p -> title);
    p -> next = top;
    top = p;
}

void pop() {
    p = top;
    top = top -> next;
    free(p);
}

void display() {
    p = top;
    while(p != NULL) {
        printf("%s\n", p -> title);
        p = p -> next;
    }
    printf("\n");
}

int main() {
    int choice;
    printf("1 - Push\n2 - Pop\n3 - Display\nAny other number to EXIT\n");
    do {
        printf("\nEnter the choice : ");
        scanf("%d", &choice);
        if(top == NULL && (choice == 2 || choice == 3)) {
            printf("Stack is empty\n");
            continue;
        }
        switch(choice) {
            case 1 : push();
                     break;
            case 2 : pop();
                     break;
            case 3 : display();
                     break;
            default : printf("Program Terminated\n");
                      exit(0); 
        }
    }
    while(choice > 0 && choice < 4);
    return 0;
}
