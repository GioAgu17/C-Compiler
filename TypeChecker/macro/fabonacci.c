//recursive - Fibonacci number

int fibonacci(int n)
{
	if(n==1)
		return 1;
	if(n==2)
		return 1;
	return(fibonacci(n-1) + fibonacci(n-2));
}


void main(void)
{
	int n;
	int fibonacci_n;
	
	n=12;
	fibonacci_n=fibonacci(n);
return;
}


