#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define DEBUG 0
#define LINE 255
#define Z 50
#define ARGS 3
int main(int argc,char *argv[])
{
  int i,m,retVal,fromBuf,Im,math1,math2;
  char *s,*t;
  FILE *buffer;
  if(argc!=ARGS)
    {
      printf("p2 [m] [I(m)]\r\n");
      exit(-1);
    }
  s=(char *)calloc(Z,sizeof(char));
  t=(char *)calloc(Z,sizeof(char));
  m=atoi(argv[1]);
  Im=atoi(argv[2]);
  if(DEBUG)printf("m=%d\tIm=%d\r\n",m,Im);
  for(i=1;i<Z;i++)//for every 'a' determine
    {
      printf("==============================\r\n");
      //      strcat(s,"./euclideanGCD(");
      sprintf(s,"./euclideanGCD %d %d > buffer",i,m);
      //      if(DEBUG)printf("CMD:%s\r\n",s);
      system(s);
      /*
      if(1==(retVal=system(s)))
	{
	  printf("%d is prime?\r\n",i);
	}
      */
      if(NULL==(buffer=fopen("buffer","r")))
	{
	  printf("Error opening buffer\r\n");
	  exit(-69);
	}
      fgets(t,LINE,buffer);
      fromBuf = atoi(t);
      if(DEBUG)printf("fromBuf=%d\r\n",fromBuf);

      if(fromBuf==1)//gcd(a,m)==1
	{
	  printf("%d Should Hold\r\n",i);
	}
      else
	{
	  printf("%d Should NOT Hold\r\n",i);
	}

      //compute a^Im%m.... it should ==1 if should hold was TRUE
      math1=(int)pow(i,Im);
      printf("i^Im=%d\r\n",math1);
      math2=math1%m;
      printf("i^Im MOD m=%d\r\n",math2);
      if(math2==1)
	printf("Euler THM Holds\r\n");
      
      s[0]='\0';
    }

  return 0;
}
