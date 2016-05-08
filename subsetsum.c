// A recursive solution for subset sum problem
//http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
#include <stdio.h>
#define bool int
#define false 0
#define true 1

// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(int set[], int n, int sum, int count, int subset[])
{
	// Base Cases
	if (sum == 0)
	{
		int i;
		for (i=0; i < count; i++)
			printf ("%d ", subset[i]);
		printf ("\n");
		return true;
	}
	if (n == 0 && sum != 0)
		return false;
#if 0 //OPTIMIZATION
	// If last element is greater than sum, then ignore it
	if (set[n-1] > sum)
		return isSubsetSum(set, n-1, sum);
#endif

	/* else, check if sum can be obtained by any of the following
	   (a) including the last element
	   (b) excluding the last element   */
	return isSubsetSum(set, n-1, sum, count, subset) || 
		(subset[count]=set[n-1], count = count+1, sum=sum-set[n-1], n=n-1, isSubsetSum(set, n, sum, count, subset));
}

// Driver program to test above function
int main()
{
	int set[] = {3, 34, 4, 12, 5, 2, 1};
	int sum = 6;
	int n = sizeof(set)/sizeof(set[0]);
	int path[n];
	if (isSubsetSum(set, n, sum, 0, path) == true)
		printf("Found a subset with given sum\n");
	else
		printf("No subset with given sum\n");
	return 0;
}
