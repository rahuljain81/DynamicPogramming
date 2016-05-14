#if 0
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, 
how many ways can we make the change? The order of coins doesn’t matter.

For example, 
For N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
So output should be 4.
For N = 10 and S = {2, 5, 3, 6}, 
there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
So the output should be 5.
#endif

#include <stdio.h>
#include <string.h>

//int arr[] = {1, 2, 3};
int arr[] = {2, 5, 3, 6};
int arrSz = sizeof(arr)/sizeof(arr[0]);


int count( int m, int n )
{
    // If n is 0 then there is 1 solution (do not include any coin)
    if (n == 0)
        return 1;
     
    // If n is less than 0 then no solution exists
    if (n < 0)
        return 0;
 
    // If there are no coins and n is greater than 0, then no solution exist
    if (m <=0 && n >= 1)
        return 0;
 
    // count is sum of solutions 
	// (i) including S[m-1] 
	// (ii) excluding S[m-1]
    return count( m - 1, n ) + count( m, n-arr[m-1] );
}
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int dp_mine(int Sum)
{
#define MAX	100
#define INF -1
#if 0
	0	1	2	3	4	5	6	7	8	9	10
0	1	0	0	0	0	0	0	0	0	0	0
2	1	0	1	0	1	0	1	0	1	0	1
5	1	0	1	0	1	1	1	1	1	1	2
3	1	0	1	1	1	2	2	2	3	3	4
6	1	0	1	1	1	2	3	2	4	4	5
#endif
	unsigned int sum[MAX]={0};
	int i, j;

	sum[0] = 1;
	for (i=1; i <= Sum; i++)
		sum[i] = 0;

	for (i=0; i < arrSz; i++)
	{
		//for (j=1; j <= Sum; j++)
		for (j=arr[i]; j <= Sum; j++)
			//if (j >= arr[i])
			{
				sum[j] +=  sum[j-arr[i]]; 
			}

		for (j=0; j <= Sum; j++)
			printf ("%d ", sum[j]);
		printf ("\n");
	}
	return sum[Sum];
}
int dp_geeks( int Sum )
{
    // table[i] will be storing the number of solutions for
    // value i. We need n+1 rows as the table is consturcted
    // in bottom up manner using the base case (n = 0)
    int table[Sum+1];
 
    // Initialize all table values as 0
    memset(table, 0, sizeof(table));
 
    // Base case (If given value is 0)
    table[0] = 1;
 
    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for(int i=0; i<arrSz; i++)
	{
        for(int j=arr[i]; j<=Sum; j++)
            table[j] += table[j-arr[i]];
#define DEBUG
#ifdef DEBUG
        for(int j=0; j<=Sum; j++)
			printf ("%d ", table[j]);
		printf ("\n");
#endif
	}
 
    return table[Sum];
}

// Driver program to test above function
int main()
{
    int i, j;
	int sum = 10;
    printf("%d \n", count(arrSz, sum));
    printf("%d \n", dp_geeks(sum));
    printf("%d \n", dpi_mine(sum));
    return 0;
}
