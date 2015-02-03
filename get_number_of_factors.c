#include "hlib.h"

int get_number_of_factors(int x)
{
	Primes pfactors = get_prime_factors(x);
	int indicies[pfactors.n];
	int i, n=0;
	for (i=0;i<pfactors.n;i++)
		indicies[i]=1;
	
	int rec(int x, int n)
	{
		printf("\n=====\n");
		printf("x=%i\n",x);
		printf("n=%i\n",n);
		
		int i;
		for (i=0; i<pfactors.n; i++)
			if(x==pfactors.array[i])
			{
				printf("\n%i is prime!\nindicies[]:\t", x);
				indicies[(pfactors.n)-1]++;
				for (i=0;i<pfactors.n;i++)
					printf("%i^%i\t",pfactors.array[i],indicies[i]);
				int j=1;
				for (i=0;i<pfactors.n;i++)
				{
					j *= indicies[i];
				}
				printf("\nnumber of factors = %i\n", j);
				return j;
			}
		
		if (x % pfactors.array[n] == 0)
		{
			printf("x (%i) is divisible by n (%i)!\n",x,pfactors.array[n]);
			x = x / pfactors.array[n];
			indicies[n]++;
			rec(x,n);
		}
		
		else 
		{
			printf("\nx (%i) is not prime and not divisible by n (%i)!\n",x,pfactors.array[n]);
			n++;
			rec(x,n);
		}
	}
	rec(x,n);
}
int main(void)
{
	int N,x;
	printf("Enter number to factorise: ");
	scanf(" %i",&N);
//	printf("%i has %i factors.\n",N, get_number_of_factors(N));
	get_number_of_factors(N);
	
	return 0;
}
