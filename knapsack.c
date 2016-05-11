#include <stdio.h>
#define max(a,b) (a > b ? a : b)

#define MAX 100
#define MAX_INDEX 4
    
int knapsackSize = 10;
int nItems = MAX_INDEX;
int matrix[MAX][MAX] = {0};
int weights[MAX_INDEX] = {5,4,6,3};
int values[MAX_INDEX] = {10,40,30,50};

void dump()
{
	int i, j;
	printf ("Wei->\t");
	for (j=1; j < knapsackSize+1; j++)
		printf ("%d\t", j);
	printf ("\n");
	for (i=0; i < MAX_INDEX; i++)
	{
		printf ("%d(%d):\t", values[i], weights[i]);
		for (j=1; j < knapsackSize+1; j++)
			printf ("%d\t", matrix[i][j]);
		printf ("\n");
	}
	printf ("\n");
}

int knapsack(int index, int size)
{
    int take,dontTake;

    take = dontTake = 0;

    if (matrix[index][size] != 0) //Already computed for this index for this size
	{
		printf ("Already computed for index %d size %d\n", index, size);
        return matrix[index][size];
	}

    if (index==0)
	{
        if (weights[index] <= size)
		{
            matrix[index][size] = values[index];
            return values[index];
        }
        else
		{
            matrix[index][size] = 0;
            return 0;
        }
    }

	//Including the index
    if (weights[index]<=size)
        take = values[index] + knapsack(index-1, size-weights[index]);

	//Excluding the index
    dontTake = knapsack(index-1, size);

    matrix[index][size] = max (take, dontTake);
	dump();

    return matrix[index][size];

}

int main()
{

    printf("Max value = %d\n",knapsack(nItems-1,knapsackSize));
	dump();

    return 0;
}
