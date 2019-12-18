#include <stdio.h>

//Compiler version gcc  6.3.0

int main()
{
  char s[1000],d[100];
  int a[100][100],i=0,j=0,k=0,r,dec,d1,d2,c,n;
  long long int b,bi[100];
  gets(s);
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
         i++;
         k=0;
      }
      j++;
  }
  d1=i-1;
  d2=i-1;
  for(i=0;d1>=0;i++){
  c=k-1,b=1;
  while(c>=0){
    b*=10*a[i][c];
    c--;
  }
  bi[i]=b;
  d1--;
  }
  j=0;
  while(d2>=0){
    dec=0,i=0;
    n=bi[j];
    while (n!=0){
        r= n % 10;
        n /= 10;
        dec += r * pow(2, i);
        ++i;
    }
    d[j]=dec;
    j++;
    d2--;
  }
  puts(d);
  return 0;
}
