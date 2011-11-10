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

int main(int argc, char *argv[])
{
	char *s;
	unsigned int i,j,value;
	unsigned int phi=0,*elements,*backup,*generators,*generatorsBase,**elementOrders,**elementOrdersBase;
	unsigned int temp,orderElementCount;
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
		    printf("%d is the identity of the Group\r\n",backup[i]);
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
		      break;//break from loop
		    }
		}
		
	      }
	    
	    
	  }
	return 0;
}
