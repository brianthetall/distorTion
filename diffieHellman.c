#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0
#define LINE 255
#define ARGS 5

unsigned int squareMult(unsigned int, unsigned int,int);

int main(int argc, char *argv[])
{
	char *s;
	int i;
	unsigned int p,alpha,a,b,A,B,commonkey,commonkey2;
	FILE *in,*out;
	if(argc!=ARGS)
		{
			printf("diffieHellman <p> <alpha> <a> <b>\r\n");
			exit(1);
		}
	s=(char *)calloc(LINE,sizeof(char));
	p=(unsigned int)atoi(argv[1]);
	alpha=(unsigned int)atoi(argv[2]);
	a=(unsigned int)atoi(argv[3]);
	b=(unsigned int)atoi(argv[4]);
	printf("s=%u\talpha=%u\ta=%u\tb=%u\r\n",p,alpha,a,b);

	A=squareMult(alpha,a,p);
	B=squareMult(alpha,b,p);
	commonkey=squareMult(A,b,p);
	commonkey2=squareMult(B,a,p);
	printf("A=%u\tB=%u\tkey=%u\tkey2=%u\r\n",A,B,commonkey,commonkey2);
	
	return 0;
}

unsigned int squareMult(unsigned int base, unsigned int exponent,int modulus)
{
  unsigned int retval=0;
  int i,index=(int)(sizeof(unsigned int)*8)-1;
  unsigned int mask=0x80000000;
  if(DEBUG)printf("base=%u exponent=%u modulus=%d index=%d mask=%x\r\n",base,exponent,modulus,index,mask);
  for(i=0;i<sizeof(unsigned int)*8;i++)
    {
      if((exponent&mask)>0)
	{
	  //	  printf(".");
	  if(DEBUG)printf("index=%d\r\n",index);
	  //	  return index;//have found the first non-zero bit in exponent
	  break;
	}
      else
	{
	  index--;
	  mask=mask>>1;
	}
    }
  //index has what i need
  retval=base;//the first 1 from exponent
  if(DEBUG)printf("retval=%u\r\n",retval);
  mask=mask>>1;
  for(i=index-1;i>=0;i--)
    {
      retval=(unsigned int)pow(retval,2);
      //      if(DEBUG)printf("tempretval=%u\r\n",retval);
      retval=retval % modulus;
      if(DEBUG)printf("square mod modulus=%u\r\n",retval);
      if((exponent&mask)>0)
	{
	  //	  if(DEBUG)printf("mask=%x\r\n",mask);
	  retval=retval*base;
	  retval=retval % modulus;
	  if(DEBUG)printf("Mult mod modulus=%u\r\n",retval);
	}
      if(DEBUG)printf("maskForPrevious=%x\r\n",mask);
      mask=mask>>1;
    }
  return retval;
}
