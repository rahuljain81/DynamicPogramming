#if 0
http://www.crazyforcode.com/robot-mxn-grid/
Problem: A robot is located at the top-left corner of a m x n grid.
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid .
How many possible unique paths are there?
#endif

#include <stdio.h>

int m=4, n=4;
#define MAX 100
// Create a 2D table to store results of subproblems
int count[MAX][MAX];

void dump()
{
	int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
			printf ("%d\t", count[i][j]);
		printf ("\n");
	}
}

int numberOfPaths()
{
	int i, j;
  
    // Count of paths to reach any cell in first column is 1
    for (i = 0; i < m; i++)
        count[i][0] = 1;
  
    // Count of paths to reach any cell in first row is 1
    for (j = 0; j < n; j++)
        count[0][j] = 1;

    // Calculate count of paths for other cells in bottom-up manner using
    // the recursive solution
    for (i = 1; i < m; i++)
    {
        for (j = 1; j < n; j++)
  
            // By uncommenting the last part of the code calculates the total
            // possible paths if the diagonal Movements are allowed
            count[i][j] = count[i-1][j] + count[i][j-1]; //+ count[i-1][j-1];
  
    }
	dump();
    return count[m-1][n-1];
}


int main()
{
	printf ("%d\n", numberOfPaths());
	return 0;
}
