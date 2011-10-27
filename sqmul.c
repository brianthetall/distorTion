//NOT FINISHED
//Need to parse from MSB bit by bit of the exponent...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ARGS 4
#define DEBUG 1
#define LINE 255
int main(int argc,char *argv[])
{
  int i,number,exponent,modulus;
  if(argc!=ARGS)
    {
      printf("sqmul [x] [power] [modulus]\r\n");
      exit(-1);
    }
  number=atoi(argv[1]);
  exponent=atoi(argv[2]);
  modulus=atoi(argv[3]);
  if(DEBUG)printf("n=%d\texp=%d\tmod=%d\r\n",number,exponent,modulus);
  
  return 0;
}
