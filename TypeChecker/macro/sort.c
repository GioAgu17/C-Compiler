//sort an array

int number[20];

void initialization(void)
{
	int i;
	i=0;
	
	while(i!=20)
	{
		number[i]=i;
		i=i+1;
	}
return;
}

void swap(int i, int j)
{
	int temp;
	temp=number[i];
	number[j]=number[i];
	number[i]=temp;
return;
}

void main(void)
{
	int i;
	int j;
	initialization();
	
	
	i=0;
	while(i<=18)
	{
		j=0;
		while(j<20-i-1)
		{
			if(number[j]>number[j+1])
				swap(j,j+1);
			j=j+1;	
		}
		i=i+1;
	}
	return;
	
}
