#if 0
http://www.crazyforcode.com/overlapping-maximum-subsequence/

Given n sequences, and starting and stopping point of every sequence with its score. 
For eg.
no of sequences = 5
start stop score
0 4 4
3 10 11
6 8 8
7 15 10
11 15 4

All scores are positive. 
You have to find the maximum subset of non overlapping sequences 
having maximum total sum of scores.

In above example, maximum total of non overlapping sub-sequence is 16. 
[{0,4,4},{6,8,8},11,15,4}]
#endif

#include <stdio.h>
#include <stdlib.h>
  
// Structure for a seq
struct seq
{
  int start;
  int stop;
  int score;
};

void dump(int N, int *L, int *prev)
{
	int i;
	for (i=0; i < N; i++)
		printf ("[%d, %d] ", L[i], prev[i]);
	printf ("\n");
}

  
int maxSequenceSum( struct seq arr[], int n)
{
	int i, j,bestEnd, maxLength = 1,sum = 0;
	int *LIS = (int*) calloc ( sizeof( int ) * n, 1 );
	int *prev = (int*) calloc ( sizeof( int ) * n, 1 );

	LIS[0] = 1;
	prev[0]=-1;
	printf ("current [%d, %d, %d] \n", arr[0].start, arr[0].stop, arr[0].score);
	printf ("%d:", 0); dump(n, LIS, prev);

	for ( i = 1; i < n; i++ )
	{
		printf ("current [%d, %d, %d] \n", arr[i].start, arr[i].stop, arr[i].score);
		LIS[i]=1;
		prev[i]=-1;  
		for ( j = 0; j < i; j++ )
		{
			if ( arr[i].start > arr[j].stop && LIS[i] < LIS[j] + 1)
			{
				LIS[i] = LIS[j] + 1;
				prev[i]=j;
			}
		}       
		if ( maxLength < LIS[i] )
		{
			maxLength = LIS[i];
			bestEnd = i;
		}
		printf ("%d:", i); dump(n, LIS, prev);
	}

	for(i = bestEnd;i>=0;)
	{      
		sum+=arr[i].score;
		i = prev[i];
	}

	/* Free memory to avoid memory leak */
	free( LIS );
	free( prev );

	return sum;
}

int main()
{
	struct seq arr[] = {{0,4,4},{3,10,11},{6,8,8},{7,15,10},{11,15,4}};
	int n = sizeof(arr)/sizeof(arr[0]);

	printf ("%d\n", maxSequenceSum( arr, n ));
	return 0;
}

