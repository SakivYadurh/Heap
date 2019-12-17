#include<stdio.h>
#include<string.h>

int count(FILE *fp){
    char c;
    int f;
    while((c=getc(fp))!=EOF){
          f++;
    }
    return f;
}
void write(FILE *fp){
     int c;
     while((c=getchar()!='\n'){
           putc(c,fp);
     }
}
int main(){
    int c;
    char p1[100],p2[100],f1[100];
    FILE *fp;
    p1={'p','a','s','s','c','r','y','p','t'};
    p2={'d','e','w','o','r','d'};
    filename:
    printf("enter filename:");
    gets(f1);
    if(!strcmp(f1,"file1"))
       fp=fopen(f1,"r");
    else if(!strcmp(f1,"file2"))
       fp=fopen(f1,"r");
    else if(!strcmp(f1,"file3"))
       fp=fopen(f1,"r");
    else if(!strcmp(f1,"file4"))
       fp=fopen(f1,"r");
    else{ 
       printf("File doesn't exist.\nEnter a valid filename.");
       goto filename;
    }
    c=count(fp);
    if(c=0){
      printf("File is empty.\nEnter some data.");
      fclose(fp);
      fp=fopen(f1,"w");
      write(fp);
    }
}
