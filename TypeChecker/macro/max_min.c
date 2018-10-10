//get the maximum and minimum in an array of integers

void main(void)
{
	int group_number[20];
	int i;
	int max;
	int min;
	
	i=0;
	
	while(i!=20)
	{
		group_number[i]=i;
		i=i+1;
	}
	
	max=group_number[0];
	min=group_number[0];
	
	i=0;
	while(i<=19)
	{
		if(max < group_number[i])
			max = group_number[i];
		
		if(min >= group_number[i])
			min = group_number[i];
		
		i=i+1;
	}
return;
}
