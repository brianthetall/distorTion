#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define DEBUG 1
#define LINE 255
#define ARGS 4
int main(int argc,char *argv[])
{
  int val=0,a,Im,modVal=0,m;
  if(argc!=ARGS)
    {
      printf("eulerTHM [a] [I(m)] [m]\r\n");
      exit(-1);
    }
  a=atoi(argv[1]);
  Im=atoi(argv[2]);
  m=atoi(argv[3]);
  if(DEBUG)printf("a=%d\tIm=%d\tm=%d\r\n",a,Im,m);
  val=(int)pow(a,Im);
  if(DEBUG)printf("VAL=%d\r\n",val);
  modVal=val%m;
  printf("OUTPUT=%d\r\n",modVal);
  return 0;
}
