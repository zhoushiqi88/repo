//#include "stdio.h"
//
//#pragma warning(disable:4996)
//
//inline long long pow(int a, int k)
//{
//	long long x = 1;
//	while (k--)
//		x *= a;
//	return x;
//}
//
//int main()
//{
//	long long A, S;
//	int n, i, j, k, x, y, z;
//	scanf("%d", &n);
//	while (n--)
//	{
//		scanf("%lld", &A);
//		S = 0;
//		while (A % 2 == 0) A /= 2;
//		x = y = z = 0;
//		while (A % 3 == 0) { A /= 3; ++x; }
//		while (A % 5 == 0) { A /= 5; ++y; }
//		while (A % 7 == 0) { A /= 7; ++z; }
//		//printf("A=3^%d*5^%d*7^%d\n", x, y, z);
//		for (i = 0; i <= x; ++i)
//			for (j = 0; j <= y; ++j)
//				for (k = 0; k <= z; ++k)
//				{
//					//printf("3^%d*5^%d*7^%d\n", i, j, k);
//					S += pow(3, i) * pow(5, j) * pow(7, k);
//				}
//		printf("%lld\n", S);
//	}
//	return 0;
//}