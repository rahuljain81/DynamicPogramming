// Q: http://www.spoj.com/problems/SQRBR/
// A: http://web.iiit.ac.in/~mayank.natani/SPOJ/SQRBR.cpp
// Explanation:-
//	Location of opening brackets [ is given
//  Closing Branckets ] can come next to open brackets
//  or [ can come at next pos
// Example: n=2, k=2, [ = 1
// 2n = 1,2,3,4
// Valid Output: 3 Combinations: []34,[[]],[][]

#include <stdio.h>
#include <string.h>

//#define DEBUG
#define MAX 38

int f[MAX];
int dp[MAX][MAX], n;

void dump_dp()
{
	int i, j;

	for (i=0; i < n; i++)
	{
		for (j=0; j < n; j++)
			printf ("%d\t", dp[i][j]);
		printf ("\n");
	}
	printf ("\n");
}

int solve(int pos, int open) 
{
	if(open < 0) 
		return 0; // invalid

	if(pos == n) 
		return open == 0; // must for being valid
	
	if (dp[pos][open] != -1)
		return dp[pos][open];

	if(f[pos])  //found an opening bracket [
		dp[pos][open] = solve(pos+1, open+1); // must put a [ here
	else	// try [ at pos, so open increments with 1 and try ] at pos, so
			// open decrements with 1
			// try [ and ] both
		dp[pos][open] = solve(pos+1, open+1) + solve(pos+1, open-1);

	return dp[pos][open];
}

int main() {
	int t, k, m, i;
	scanf("%d", &t);
	while(t--) 
	{
		scanf("%d%d", &n, &k);

		n <<= 1; //Multitply by 2 so it makes it 2*n
		memset (f, 0, sizeof(f));
		memset (dp, -1, sizeof (dp));

		for(i = 0; i < k; i++) 
		{
			scanf("%d", &m);
			f[m-1] = 1;
		}
		printf("%d\n", solve(0, 0));
#ifdef DEBUG
		dump_dp();
#endif
	}
	return 0;
}
