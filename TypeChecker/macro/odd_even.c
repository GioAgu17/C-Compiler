//split an interger array into two arrays, one for odds, the other for evens
int odd_or_even(int number)
{
int x;
	if(number==(number/2*2))
		x=0;
	else x=1;

return (x);
}

void main(void)
{
	int number[20];
	int odds[20];
	int evens[20];
	int number_p;
	int odds_p;
	int evens_p;
	int i;

	i=0;
	
	while(i!=20)
	{
		number[i]=i;
		i=i+1;
	}
	
	number_p=0;
	odds_p=0;
	evens_p=0;
	
	
	while(number_p<=19)
	{
		if(odd_or_even(number[number_p])==1)
		 {
			odds[odds_p]=number[number_p];
			odds_p=odds_p+1;
		}
		else
		{
			evens[evens_p]=number[number_p];
			evens_p=evens_p+1;
		}
		number_p=number_p+1;
	}
return;
}

