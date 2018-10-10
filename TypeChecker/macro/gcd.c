/* A program to compute gcd */

int gcd(int u, int v){
	int x;
	if (v == 0)  x=u;
	else  x=gcd(v, u-v/v*v);
	/* u - u/v*v = u mod v*/
	return x;
}

int myinput(void)
{
	return(1);
}

void main(void){
	int x;
	int y;
	x = myinput();
	y = myinput();
	gcd(x,y);
return;	
}

