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
     char c,s1[100];
     int i=0,j=0,k=1;
     while((c=getchar())!=EOF){
           s1[i++]=c;
           s1[i++]='|';
     }
     s1[i]='\0';
     s1=encrypt(s1);
     while ((c=s[j])!='\0'){
    n=c;
    while (n != 0) {
        r = n % 2;
        n /= 2;
        if(k%2==0){
          if(r==1)
             a='/';
          else
             a=',';
        }
        else{
            if(r==1)
             a='-';
          else
             a='.';
        }
        k++;
        putc(a,fp);
        if(n==0){
          putc('|',fp);
          k=1;
        }
    }
    j+=2;
 }
}
char read(FILE *fp){
     char c,s[100];
     int i=0;
     while((c=getc(fp))!=EOF)
           s[i++]=c;
    s[i]='\0';
    return s;
}
int password(void){
     char pword[100];
     int flag=0;
     char p1={'p','a','s','s','c','r','y','p','t'};
     char p2={'d','e','w','o','r','d'};
     check:
      printf("Enter password:");
      gets(pword);
      if(!strcmp(pword,p1))
          flag=1;
      else if(!strcmp(pword,p2))
          flag=2;
      else{
          printf("Password invalid.\nPlease re-enter the password.");
          goto check;
      }
      return flag;
}
void choice(FILE *fp){
     choice:
         printf("\n1-Rewrite\n2-Exit\nEnter your choice:");
         scanf("%d",&n);
         if(n==1){
            fclose(fp);
            fp=fopen(f1,"w");
            write(fp);
         }
         else if(n==2){
            fclose(fp);
            exit();
         }
         else{
          printf("Invalid key");
          goto choice;
         } 
}
char decrypt(char s){
    
    
     return s;
}
int main(){
    int c,flag,n;
    char f1[100],s[100];
    FILE *fp;
    filename:
    printf("enter filename:");
    gets(f1);
    if(!strcmp(f1,"file1")){
       flag=password();
       fp=fopen(f1,"r");
    }
    else if(!strcmp(f1,"file2")){
       flag=password();
       fp=fopen(f1,"r");
    }
    else if(!strcmp(f1,"file3")){
       flag=password();
       fp=fopen(f1,"r");
    }
    else if(!strcmp(f1,"file4")){
       flag=password();
       fp=fopen(f1,"r");
    }
    else{ 
       printf("File doesn't exist.\nEnter a valid filename.");
       goto filename;
    }
    c=count(fp);
    if(c=0){
      printf("File is empty.");
      choice(fp);
    }
    else{
        s=read(fp);
        if(flag==1){
            puts(s);
            choice(fp);
        }
        else if(flag==2){
            s=decrypt(fp);
            puts(s);
            choice(fp);
        }
    }   
}
