// Q: http://www.spoj.com/problems/MIXTURES/
// A: https://codinghangover.wordpress.com/2014/02/16/spojmixtures-mixtures-dynamic-programming/
// Matrix Chain Multiplication

#include <stdio.h>

#define MAX	100
int arr[MAX];
int dp[MAX][MAX];
int N;

int sum (int a, int b)
{
	int i, add=0;
	for (i=a; i<=b; i++)
		add += arr[i];

	return add%100;
}


int solve (int a, int b)
{
	if (dp[a][b] != -1)
		return dp[a][b];

	if (a == b)
		return 0;

	for (int i=a; i+1 <= b; i++)
	{
		int temp  = solve (a,i) + solve (i+1,b) + sum(a, i) * sum (i+1, b);
		if (dp[a][b] == -1 || temp < dp[a][b])
			dp[a][b] =  temp;
	}
	return dp[a][b];
}


int main()
{
	int i, j;
	while (scanf ("%d", &N) > 0)
	{
		for (i=0; i < N; i++)
		{
			scanf ("%d", &arr[i]);
			for (j=0; j < N; j++)
				dp[i][j] = -1;
		}
		printf ("%d\n", solve (0,N-1));
	}
	return 0;
}
