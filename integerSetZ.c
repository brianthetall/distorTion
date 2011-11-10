/*
take in an integer
find information about its Z* set.
Find the elements that are co-prime/PhiFunction()
the order of each element
Identify if any of the elements are generators.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 1
#define LINE 255
#define ARGS 2

int main(int argc, char *argv[])
{
	char *s;
	unsigned int i,value;
	unsigned int phi,*elements,*backup,*generators;
	FILE *in,*out;
	if(argc!=ARGS)
		{
			printf("integerSetZ <positive integer>\r\n");
			exit(1);
		}
	s=(char *)calloc(LINE,sizeof(char));
	value=atoi(argv[1]);
	if(DEBUG)printf("Z%d* Set\r\n",value);
	elements=(unsigned int *)calloc(value,sizeof(unsigned int));
	backup=elements;//backup the base pointer of the elements array.
	for(i=1;i<value;i++)
	  {
	    if(i==1)
	      *(elements++)=i;
	    else if(value%i!=0)//modulus is not divided by i
	      {//then i is co-prime & an element in the Z* set
		*(elements++)=i;
	      }
	  }
	for(i=0;backup[i]!='\0';i++)
	  {
	    if(DEBUG)printf("Element: %d\r\n",backup[i]);
	    //for every element find the set of exponent values & resulting values mod p that exist.
	    //if the value is 1, this element is in the generator set.
	  }
	return 0;
}

