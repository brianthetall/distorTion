#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LINE 255
#define DEBUG 0
#define ARGS 3
int main(int argc,char *argv[])
{
  int i=1,a,m;
  int r[3000],q;
  int s[3000],t[3000];
  s[0]=1; s[1]=0;
  t[0]=0; t[1]=1;
  r[0]=0;r[1]=0;r[2]=0;
  if(argc!=ARGS)
    {
      printf("eea [a] [m]\r\n");
      exit(-1);
    }
  a=atoi(argv[1]);
  m=atoi(argv[2]);//the bigger number
  r[0]=m;
  r[1]=a;
  if(DEBUG)printf("a=%d\tm=%d\r\n",a,m);
  if(DEBUG)printf("r[1]=%d\tr[0]=%d\r\n",r[1],r[0]);
  do
    {
      i++;
      r[i]=r[i-2]%r[i-1];
      q=(r[i-2]-r[i])/r[i-1];
      s[i] = s[i-2] - q * s[i-1];
      t[i] = t[i-2] - q * t[i-1];
    }while(r[i]!=0);
  printf("OUTPUT:\r\nGCD=%d\r\ns=%d\r\nt=%d\r\n",r[i-1],s[i-1],t[i-1]);
  return 0;
}
