//find 59*e===mod 72
//d*e===mod I(n)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ARGS 3
#define LINE 255
#define DEBUG 1
int main(int argc,char *argv[])
{
  int i=1,modResult=0,given,modulus;
  if(argc!=ARGS)
    {
      printf("inverse [d or e] [I(n)]\r\n");
      exit(-1);
    }
  given=atoi(argv[1]);
  modulus=atoi(argv[2]);
  if(DEBUG)printf("given=%d\tmodulus=%d\r\n",given,modulus);
  while(modResult!=1)
    {
      modResult=(i++*given)%modulus;
    }
  printf("Answer=%d\r\n",i-1);
  return 0;
}
