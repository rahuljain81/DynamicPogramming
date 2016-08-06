// Q: http://www.spoj.com/problems/MARTIAN/
// Answer:
// https://www.quora.com/How-do-I-solve-SPOJ-com-Problem-MARTIAN
// http://abitofcs.blogspot.in/2014/11/spoj-martian.html


#include <stdio.h>

#define MAX 500
#define INDEX_Y 0
#define INDEX_B	1

#define max(a,b) ((a>b)?a:b)
#define DEBUG

int sum[MAX][MAX][2];
int dp[MAX][MAX];
int R, C;

void dump_sum()
{
	int i, j;
	printf ("First Index to Left, Second Index to Top\n");
	for (i=0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if (j > 0)
				printf ("[%d,", sum[i][j][INDEX_Y] - sum[i][j-1][INDEX_Y]);
			else
				printf ("[%d,", sum[i][j][INDEX_Y]);
			if (i > 0)
				printf ("%d]", sum[i][j][INDEX_B] - sum[i-1][j][INDEX_B]);
			else
				printf ("%d]", sum[i][j][INDEX_B]);
		}
		printf ("\n");
	}
	printf ("\n");

	for (i=0; i < R; i++)
	{
		for (j = 0; j < C; j++)
			printf ("[%d,%d]", sum[i][j][INDEX_Y], sum[i][j][INDEX_B]);
		printf ("\n");
	}
	printf ("\n");
}
void dump_dp()
{
	int i, j;

	for (i=0; i < R; i++)
	{
		for (j = 0; j < C; j++)
			printf ("%d ", dp[i][j]);
		printf ("\n");
	}
}
void solve()
{
	int i,j;
	int tmp1, tmp2;
    for(i=0;i<R;++i)
	{
        for(j=0;j<C;++j)
		{
            tmp1 = sum [i][j][INDEX_Y];
            tmp2 = sum [i][j][INDEX_B];
            if(i>0) 
				tmp1 += dp[i-1][j];
            if(j>0) 
				tmp2 += dp[i][j-1];
            dp[i][j] = max(tmp1, tmp2);
        }
    }
#ifdef DEBUG
	dump_dp();
#endif
    printf("%d\n", dp[R-1][C-1]);
}


int main()
{
    while(scanf("%d %d", &R, &C), R+C!=0)
	{
        int s;
        for(int i=0;i<R;++i)
		{
            for(int j=0;j<C;++j)
			{
                scanf("%d", &s);
                sum [i][j][INDEX_Y] = s;
				dp[i][j] = 0;
                if(j>0) //sum of Y of complete row 
					sum [i][j][INDEX_Y] += sum[i][j-1][INDEX_Y];
            }
        }
        for(int i=0;i<R;++i)
		{
            for(int j=0;j<C;++j)
			{
                scanf("%d", &s);
                sum[i][j][INDEX_B] = s;
                if(i>0) //sum of B of complete column
					sum [i][j][INDEX_B] += sum [i-1][j][INDEX_B];
            }
        }
#ifdef DEBUG
		dump_sum();
#endif
        solve();
    }
    return 0;
}
