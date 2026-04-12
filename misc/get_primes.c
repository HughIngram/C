/*
Program demonstrating the get_primes function.
get_primes() takes an int limit, and returns a struct of type Primes, which contains a pointer  
to an array of prime numbers, as well as an int of the number of primes in the array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int *array;
	int n;
} Primes;
Primes get_primes(int limit)
{
	limit +=1;
	Primes x;
	int *ar, i, j;
	x.n=0;
	ar = (int *)malloc(limit * sizeof(int));
	//initialise the array to all 1 (except 0 and 1 - they are not prime.)
	ar[0]=0;
	ar[1]=0;
	for (i=2;i<limit;i++)
	{
		ar[i]=1; 
	}
	//sieve of Eratosthenes
	for (i=2;i<limit;i++)
	{
		if (ar[i])
			for(j=(2*i);j<limit;j+=i)
				ar[j]=0;
	}
	//count the number of primes in the array
	for (i=0;i<limit;i++)
	{
		if (ar[i])
			x.n++;
	}
	//fill array x.array[] with prime numbers only
	x.array = (int *)malloc(x.n * sizeof(int));
	for (i=0,j=0;i<limit;i++)
	{
		if(ar[i])
		{
			x.array[j]=i;
			j++;
		}
	}
	free(ar);
	return x;
}
int main(void)
{
	int N, i;
	printf("Enter limit: ");
	scanf(" %i", &N);
	Primes y = get_primes(N);
	for (i=0;i<y.n;i++)
		printf("%i\n",y.array[i]);
	printf("Number of primes = %i\n", y.n);
	return 0;
}
