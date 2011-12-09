//NOT FINISHED
//Need to parse from MSB bit by bit of the exponent...STARTING WITH THE FIRST 1-BIT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ARGS 4
#define DEBUG 1
#define LINE 255

int findFirst1(int exp);//return the first MSB-position that is a 1
int squareMultiply(int number,int exp,int mod);
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
  //  printf("DEBUG find first=%d\r\n",findFirst1(exponent));
  squareMultiply(number,exponent,modulus);
  return 0;
}

int squareMultiply(int number,int exp,int mod)
{
  int i,retval,first1;
  first1=findFirst1(exp);
  if(DEBUG)
    printf("Num=%d\tExp=%d\tMod=%d\tfirst1=%d\r\n",number,exp,mod,first1);
  retval=number;//the first bit
  for(i=first1-1;i>=0;i--)//the rest of the bits
    {
      retval = (int)pow(retval,2);//always square
      retval%=mod;
      if(DEBUG)
	printf("AfterSquare=%d\r\n",retval);
      if((exp&(1<<i)) > 0)//only multiply if the bit is a 1
	{
	  retval*=number;
	  printf("AfterMultiply=%d\r\n",retval);
	}
    }
  return retval;
}

int findFirst1(int exp)
{
  int i,retval=0;
  for(i=0;i<(8*sizeof(int));i++)
    {
      //      printf("%d ",exp & (1<<i));
      if((exp&(1<<i)) > 0)
	retval=i;
    }
  return retval;
}
