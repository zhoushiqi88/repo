#include "stdio.h"

long long gcd(long long x, long long y);

int main()
{
	int M,A[20];
	int i,j,k;
	long long N,P,s;
	scanf("%lld%d", &N, &M);
	for(i=0;i<M;++i)
		scanf("%d", A+i);
	s=0;
	for(k=1;k<(1<<M);++k)
	{
		P=1;
		for(i=j=0;i<M;++i)
		{
			if(k&(1<<i))
			{
				//printf("%d, ", A[i]);
				j++;
				P=P*(A[i]/gcd(P,A[i]));
			}
			if(P>N)
				P=N+1;
		}
		if(j%2)
		{
			//printf("Add %lld\n", N/P);
			s+=N/P;
		}
		else
		{
			//printf("Sub %lld\n", N/P);
			s-=N/P;
		}
	}
	printf("%lld",s);
	return 0;
}

long long gcd(long long x, long long y)
{
	long long z=x%y;
	while(z)
	{
		x=y;
		y=z;
		z=x%y;
	}
	return y;
}