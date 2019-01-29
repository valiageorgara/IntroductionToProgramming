/* the code for finding subquences was taken from lists */

#include<stdio.h>
#define MAXNUM   100000000

int prime(int); /* function for finding prime numbers */

int main(void) /* starting main */
{
	int flag,digits,i,y,max,save,j,x,mask; 
	
	for(i=11 ; i<=MAXNUM ; i++) /*starting from 11 to Maxnum and checking only odd mumbers because even numbers are not primes */
	{
		save = i; /*saving value of i for later use*/
		if(i % 10 == 1 || i % 10 == 9) /*if the last digit of i is 0,2,4,6 or 8 then i is even, so not a prime*/
									   /*if the last digit of i is 3,5 or 7 ,these are prime subquences of i, so not a minimal prime */
		
		{
			if ( prime(i) ) /* if i is prime */
			{
				digits = 0; /* variable for the digits of save = i */
			
				while ( save != 0 ) /*counting the digits of save = i */
				{
					save /= 10;
				
					digits++;
				}
				max = 1; 
				for ( j = 1; j <= digits; j++ )  /* calculating max */
				{
					max *= 2;
				}
				flag = 0; /*if at least one subquence is a prime number, this variable helps terminate the loop and save time*/
				for ( j = 1; (j < max - 1)&& flag==0  ; j++ ) /*finding subquences of i */
				{ 				

					mask = j;
					x = 1;
					save = i;
					y=0;
		
					while (  save!= 0 ) 
					{ 				

						if ( mask % 2 == 1 )
				 		{
							y += save % 10 * x;				
							x *= 10; 
						}
						save /= 10;
						mask /= 2;
					} 
					
					if ( prime(y) ) {flag = 1;} /* if a subquence is prime terminate the loop, and i is not a minimal prime */
					
				} 
				if (flag==0)	printf("%d\n", i);	/* if you have not found a prime subquence, print the i */
			}
		}
	}
	return 0;

}


int prime(int i) /*function for finding prime numbers */
{
	int j;
	
	if (i==0 || i==1) return 0;
	if (i==2) return 1; /* 2 is a prime number */
	if (i%2==0) return 0;
	for (j=3 ; j*j<=i ; j+=2)
		if (i%j == 0) return 0;
	return 1;
}
