//given e,n,symbols
//produce the possible outputs from 1 symbol
//being processed at a time.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ARGS 4
#define DEBUG 0
#define LINE 255
int main(int argc,char *argv[])
{
  int i,e,n,symbols;
  long int result;
  char c='A';
  if(argc!=ARGS)
    {
      printf("RSAalphabet [# of symbols] [e] [n]\r\n");
      exit(-1);
    }
  symbols=atoi(argv[1]);
  e=atoi(argv[2]);
  n=atoi(argv[3]);
  if(DEBUG)printf("Sym=%d\te=%d\tn=%d\r\n",symbols,e,n);
  for(i=0;i<symbols;i++)
    {//print 
      result=((long int)pow((i+1),e))%n;
      if(DEBUG)printf("debug=%ld\r\n",(long int)pow((i+1),e));
      printf("%c: %ld\r\n",c++,result);
    }
  return 0;
}
