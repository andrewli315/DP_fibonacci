#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

__int64 fibonacci(int n);
static __int64 fib[100];

int main(void)
{
	__int64 x;
	int input,i;
	for (i = 0;i<100;i++)
		fib[i] = -1;
	scanf("%d",&input);
	LARGE_INTEGER t1, t2, ts;
    QueryPerformanceFrequency(&ts);
    QueryPerformanceCounter(&t1);
	x = fibonacci(input);
	QueryPerformanceCounter(&t2);
	printf("fibonacci level %d is %lld\n",input, x);
	printf("Lasting Time: %lf\n",(t2.QuadPart-t1.QuadPart)/(double)(ts.QuadPart));
}
__int64 fibonacci(int n)
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
		else if (n >= 100)
		{
			return fibonacci(n-1)+fibonacci(n-2);
		}
		else
		{
			//printf("%d = %d\n", n, fib[n] );
			return fib[n];
		}
	}
	return fib[n];
}