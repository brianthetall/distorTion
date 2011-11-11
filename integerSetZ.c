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
#include <math.h>
#define DEBUG 1
#define LINE 255
#define ARGS 2

unsigned int squareMult(unsigned int, unsigned int, int);
int main(int argc, char *argv[])
{
	char *s;
	unsigned int i,j,value;
	unsigned int phi=0,*elements,*backup,*generators,*generatorsBase,**elementOrders,**elementOrdersBase;
	unsigned int temp,orderElementCount,*possibleElementOrders,*possibleElementOrdersBase;
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
	    if(i==1){
	      *(elements++)=i;
	      phi=1;
	    }
	    else if(value%i!=0)//modulus is not divided by i
	      {//then i is co-prime & an element in the Z* set
		*(elements++)=i;
		phi++;
	      }
	  }
	if(DEBUG)printf("PHI=%d\r\n",phi);
	//given the phi is the number of elements in the Z* set,
	generators=(unsigned int*)calloc(phi,sizeof(unsigned int));//this is MAX number of generators
	generatorsBase=generators;
	elementOrders=(unsigned int **)calloc(phi,sizeof(unsigned int*));//alloc elementOrders[phi][phi]
	elementOrdersBase=elementOrders;
	possibleElementOrders=(unsigned int*)calloc(phi,sizeof(unsigned int));
	possibleElementOrdersBase=possibleElementOrders;
	for(i=0;backup[i]!='\0';i++)
	  {
	    *(elementOrders++)=(unsigned int*)calloc(phi,sizeof(unsigned int));
	    if(DEBUG)printf("Element: %d\r\n",backup[i]);
	    //for every element find the set of exponent values & resulting values mod p that exist.
	    orderElementCount=0;
	    for(j=1;j<=phi;j++)
	      {
		if(backup[i]==1)
		  {
		    printf("%d is the identity of the Group\r\n\r\n",backup[i]);
		    break;
		  }
		else{
		  orderElementCount++;
		  temp=(unsigned int)pow(backup[i],j)%value;//need to write the sum-square function, i am suffering from overflowing values before the mod can take place.
		  //HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		  if(DEBUG)printf("%d^%d mod %d = Order Element:%d\r\n",backup[i],j,value,temp);
		  *((*(elementOrders-1))+(j-1))=temp;
		  if(temp==1&&j!=1&&orderElementCount==phi)
		    {
		      *(generators++)=backup[i];//if the value is 1, this element is in the generator set.
		      if(DEBUG)printf("Generator:%d; Z*%d is cyclic group\r\n",backup[i],value);
		      if(phi%orderElementCount==0)
			{
			  *(possibleElementOrders++)=orderElementCount;//add orderElementCount to a possibleElementOrders[]
			  printf("%d is an element order. %d in possibleElementOrders[]\r\n",orderElementCount,*(possibleElementOrders-1));
			}
		      if(DEBUG)printf("Order(%d)=%d\r\n\r\n",backup[i],orderElementCount);
		      break;//break from loop
		    }
		  else if(temp==1)
		    {
		      if(phi%orderElementCount==0)
			{
			  *(possibleElementOrders++)=orderElementCount;//add orderElementCount to a possibleElementOrders[]
			  printf("%d is an element order. %d in possibleElementOrders[]\r\n",orderElementCount,*(possibleElementOrders-1));
			}
		      if(DEBUG)printf("Order(%d)=%d\r\n\r\n",backup[i],orderElementCount);
		      break;//this element of G is not a generator
		    }
		}
		
	      }
	    
	  }
	printf("PossibleElementOrders:\r\n");
	printf("1\r\n");
	for(i=0;possibleElementOrdersBase[i]!='\0';i++)
	  {
	    printf("%d\r\n",possibleElementOrdersBase[i]);
	  }
	/*
	if(DEBUG)printf("debug squareMult=%x\r\n",squareMult(2,1,value));
	if(DEBUG)printf("debug squareMult=%x\r\n",squareMult(2,2,value));
	if(DEBUG)printf("debug squareMult=%x\r\n",squareMult(2,3,value));
	if(DEBUG)printf("debug squareMult=%x\r\n",squareMult(2,4,value));
	if(DEBUG)printf("debug squareMult=%x\r\n",squareMult(2,5,value));
	*/
	if(DEBUG)printf("math.h=%u\tdebug squareMult=%u\r\n",(unsigned int)pow(3,4)%11,squareMult(3,4,value));
	if(DEBUG)printf("math.h=%u\tdebug squareMult=%u\r\n",(unsigned int)pow(2,16)%11,squareMult(2,16,value));
	if(DEBUG)printf("math.h=%u\tdebug squareMult=%u\r\n",(unsigned int)pow(2,64)%11,squareMult(2,64,value));
	if(DEBUG)printf("math.h=%u\tdebug squareMult=%u\r\n",(unsigned int)pow(2,199)%11,squareMult(2,199,value));
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
	  printf(".");
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
      retval=pow(retval,2);
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
