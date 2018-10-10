//get the average value the integers from 0 to 29

void main(void)
{
	int i;
	int ave;
	int total;
	
	i=0;
	total=0;
	
	while(i!=29)
	{
		total = total + i;
		i=i+1;
	}

	ave = total / 30;
return;
}