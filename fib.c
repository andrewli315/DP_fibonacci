#include <stdio.h>
#include <stdlib.h>
 
int fibonacci(int n);
static int fib[100];

int main(void)
{
	int x,input,i;
	for (i = 0;i<100;i++)
		fib[i] = -1;
	scanf("%d",&input);
	x = fibonacci(input);
	printf("fibonacci level %d is %d\n",input, x);
}
int fibonacci(int n)
{
	if(n == 1 || n ==0 )
	{
		if(fib[n] == -1)
			fib[n] = 1;
		return fib[n];
	}
	else 
	{
		if(fib[n] == -1)
		{
			fib[n] = fibonacci(n-1)+fibonacci(n-2);
		}
		else
		{
			//printf("%d = %d\n", n, fib[n] );
			return fib[n];
		}
	}
	return fib[n];
}