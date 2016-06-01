#if 0
http://www.crazyforcode.com/maximum-size-square-sub-matrix-1s/
Problem: Given a binary matrix consisting only 0s and 1s, find the maximum size square sub-matrix with all 1s.

Example: Consider the below matrix.

0 1 1 0 1
1 1 0 1 0
0 1 1 1 0
1 1 1 1 0
1 1 1 1 1
0 0 0 0 0

The maximum square sub-matrix with all ’1′ bits is from (2,1) to (4,3)
1 1 1
1 1 1
1 1 1
#endif

#include <stdio.h>
#define min(a,b) (a>b?b:a)

#define MAX 6


int out[MAX][MAX];
int mat[MAX][MAX] = {
	0,1,1,0,1,0,
	1,1,0,1,0,0,
	0,1,1,1,0,0,
	1,1,1,1,0,0,
	1,1,1,1,1,0,
	0,0,0,0,0,0,
};

void dump()
{
	int i, j;
	for (i=0; i<MAX; i++)
	{
		for (j=0; j<MAX; j++)
			printf ("%d ", mat[i][j]);
		printf ("\n");
	}
	printf ("\n");
	for (i=0; i<MAX; i++)
	{
		for (j=0; j<MAX; j++)
			printf ("%d ", out[i][j]);
		printf ("\n");
	}
	printf ("\n");
}

int solve ()
{
	int i, j, max=0;

	for (i=0; i < MAX; i++)
	{
		out[0][i] = mat[0][i];
		out[i][0] = mat[i][0];
	}
	for (i=1; i < MAX; i++)
		for (j=1; j < MAX; j++)
		{
			if(mat[i][j] == 1)
				out[i][j] = min(out[i][j-1], min(out[i-1][j-1], out[i-1][j]))+1;
			else
				out[i][j]=0;
			if (out[i][j] > max)
				max = out[i][j];
		}

	dump();
	return max;
}

int main()
{
	printf ("%d\n", solve());
	return 0;
}
