#if 0
http://www.crazyforcode.com/triangle-find-minimum-path-sum-top-bottom/
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
#endif

#include <stdio.h>

#define MAX 4
#define min(a,b) (a>b?b:a)

int mat[MAX][MAX] = { {2},{3,4},{6,5,7},{4,1,8,3}};
int size[MAX] = {1,2,3,4};
int minSum[MAX][MAX] = {0};

void dump()
{
	int i, j;

	for (i=0; i < MAX; i++)
	{
		for (j=0; j < size[i]; j++)
			printf ("%d\t", mat[i][j]);
		printf ("\n");
	}
	printf ("\n");
	for (i=0; i < MAX; i++)
	{
		for (j=0; j < size[i]; j++)
			printf ("%d\t", minSum[i][j]);
		printf ("\n");
	}
	printf ("\n");
}

int solve()
{
	int rows = MAX;
	int i, j, res;
	
	minSum[0][0] = mat[0][0];

	for (i=1; i < rows; i++)
		for (j=0; j < size[i]; j++)
		{
			if (j==0) //first element
				minSum[i][j] = minSum[i-1][j]+mat[i][j];
			else if (j == size[i]-1) //last element of row: sum of current index + 
				minSum[i][j] = minSum[i-1][j-1]+mat[i][j];
			else
				minSum[i][j] = mat[i][j] + min(minSum[i-1][j], minSum[i-1][j-1]);
		}

	dump();
	res = minSum[rows-1][0];
	for (i=1; i < rows; i++)
		if (minSum[rows-1][i] < res)
			res = minSum[rows-1][i];

	return res;
}

int main()
{
	printf ("%d\n", solve());
	return 0;
}

	

						
