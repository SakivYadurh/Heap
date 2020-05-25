#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>

int count(FILE *fp){
    char c;
    int f = 0;
    while((c=getc(fp))!=EOF){
        f++;
    }
    rewind(fp);
    return f;
}
void write(FILE *fp){
     char a, c, s[1000];
     int i=0,j=0,k=1, n, r;
     while((c=getchar())!=EOF){
           s[i++]=c;
           s[i++]='|';
     }
     s[i]='\0';
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
    rewind(fp);
}
void read(FILE *fp, char *s){
    char c;
    int i=0;
    while((c=getc(fp))!=EOF)
        s[i++]=c;
    s[i]='\0';
}
int password(void){
     char pword[100];
     int flag=0;
     char p1[20]="passcrypt";
     char p2[20]="deword";
     check:
      printf("Enter password:");
      gets(pword);
      if(!strcmp(pword,p1))
          flag=1;
      else if(!strcmp(pword,p2))
          flag=2;
      else{
          printf("Password invalid.\nPlease re-enter the password.\n");
          goto check;
      }
      return flag;
}
void choice(FILE *fp, char *f1){
     int n;
	 choice:
         printf("\n1-Append\n2-Re-write\n3-Exit\nEnter your choice:");
         scanf("%d",&n);
         if(n==2){
            fclose(fp);
            fp=fopen(f1,"w");
            write(fp);
         }
         else if(n==3){
            fclose(fp);
            exit(0);
         }
         else if(n==1){
            fclose(fp);
            fp=fopen(f1,"a");
            write(fp);
         }
         else{
          printf("Invalid key");
          goto choice;
         }
}
void decrypt(char *s){
  int a[100][1000],i=0,j=0,k=0,d,c,o,p;
  while(s[j]!='\0'){
      if(s[j]=='.'){
         a[i][k]=0;
         k++;
         }
      else if(s[j]==','){
         a[i][k]=0;
         k++;
         }
      else if(s[j]=='-'){
         a[i][k]=1;
         k++;
         }
      else if(s[j]=='/'){
         a[i][k]=1;
         k++;
         }
      else{
      	 a[i][k]=5;
         i++;
         k=0;
      }
      j++;
  }
  d=i-1;
  for(i=0;d>=0;i++){
    k=0;
    while(a[i][k]==0||a[i][k]==1)
        k++;
    c=k-1;
    k=0;
    o=0;
    p=1;
    while(k<=c){
        o+=a[i][k]*p;
        p*=2;
        k++;
    }
    s[i]=o;
    d--;
  }
  s[i]='\0';
}
int main(){
    int c,flag,n;
    char f1[100],s[1000];
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
       printf("File doesn't exist.\nEnter a valid filename.\n");
       goto filename;
    }
    c=count(fp);
    if(c==0){
      printf("File is empty.");
      choice(fp, f1);
    }
    else{
        read(fp, s);
        if(flag==1){
            puts(s);
            choice(fp, f1);
        }
        else if(flag==2){
            decrypt(s);
            puts(s);
            choice(fp, f1);
        }
    }
}
