/* A program to compute gcd */

int gcd(int u, int v){

	if (v == 0) return u;
	else return gcd(v, u-v/v*v);
	/* u - u/v*v = u mod v*/
}

int input(void)
{
}

void main(void){
	int x;
	int y;
	x = input();
	y = input();
	output(gcd(x,y));	
}

