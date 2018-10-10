//reverse an array

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

//bubble sort
void main(void)
{
	int i;
	int j;
	initialization();
	
	
	i=0;
	j=19;
	
	while(j>i)
	{
		swap(i,j);
		i=i+1;
		j=j-1;
	}
return;
}
