//returns:
//<0 for error
//(int)GCD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 255
#define DEBUG 0
#define ARGS 3

int main(int argc,char *argv[])
{
  int i,r0,r1,t0,t1;
  if(argc!=ARGS){
    printf("euclideanGCD #0 #1\r\n");
    exit(-1);
  }
  r0=atoi(argv[1]);
  r1=atoi(argv[2]);
  if(DEBUG)printf("ARGS: %d,%d\r\n",r0,r1);
  {
    while(1)
      {
	if(DEBUG)printf("r0,r1=%d,%d\r\n",r0,r1);
	t0=r1;
	t1=r0%r1;
	if(t1==0)
	  {
	    printf("%d\r\n",t0);
	    return(t0);
	  }
	if(t1<0)
	  {
	    if(DEBUG)printf("Error: t1=%d\r\n",t1);
	    exit(-2);
	  }
	r0=t0;
	r1=t1;
      }
  }
  return 0;
}
