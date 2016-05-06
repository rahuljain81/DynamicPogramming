// Program to count number of paths with maximum  k turns allowed
//http://www.geeksforgeeks.org/count-number-of-paths-with-k-turns/

#include <stdio.h>
#include <string.h>

#define MAX 100
 
// table to store to store results of subproblems
int dp[MAX][MAX][MAX][2];

#define SIZE 5
int m = SIZE, n = SIZE, k = 2;

int path[MAX][2];
 
// Returns count of paths to reach (i, j) from (0, 0)
// using at-most k turns. d is current direction
// d = 0 indicates along row
// d = 1 indicates along column.

int countPathsUtil(int i, int j, int k, int d, int count)
{
    // If invalid row or column indexes
    if (i == m || j == n || k < 0)
        return 0;

    // If current cell is destination itself
    if (i == m-1 && j == n-1 && k == 0)
	{
		int tmp;
		path[count][0] = i;
		path[count][1] = j;
		for (tmp=0; tmp < count+1; tmp++)
			printf ("[%d,%d]\t", path[tmp][0], path[tmp][1]);
		printf ("\n");

        return 1;
	}

#if 0 //OPTIMIZATION
    // If this subproblem is already evaluated
    if (dp[i][j][k][d] != -1)
        return dp[i][j][k][d];
#endif
	path[count][0] = i;
	path[count][1] = j;
 
	// A movement is considered turn, 
	// if we were moving along row and now move along column. 
	// OR we were moving along column and now move along row. 
    // If current direction is row, then count paths for two cases
    // 1) We reach here through previous row.
    // 2) We reach here through previous column, so number of 
    //    turns k reduce by 1.
    if (d == 0)//row
      return dp[i][j][k][d] = countPathsUtil(i, j+1, k, d, count+1) + //moving to next column in direction of row, So no decrement of turn
                              countPathsUtil(i+1, j, k-1, !d, count+1);//moving to next row on same column, it is a turn
 
    // Similar to above if direction is column
    return dp[i][j][k][d] =  countPathsUtil(i+1, j, k, d, count+1) +
                             countPathsUtil(i, j+1, k-1, !d, count+1);
}
 
// This function mainly initializes 'dp' array as -1 and calls
// countPathsUtil()
int countPaths(int i, int j, int k)
{
	path[0][0] = i;
	path[0][1] = j;

    // Initialize 'dp' array
    memset(dp, -1, sizeof dp);

    // Recur for two cases: moving along row and along column

	//When moving along column, row needs to be decremented
	//When moving along row, column needs to be decremented
 
    return countPathsUtil(i, j+1, k, 1, 1) +	// Moving along row
           countPathsUtil(i+1, j, k, 0, 1);		// Moving along column
}
 
// Driver program
int main()
{
    printf ( "Number of paths is %d\n", countPaths(0, 0, k));
    return 0;
}
