/*
   The knapsack problem or rucksack problem is a problem in combinatorial optimization: 
   Given a set of items, each with a weight and a value,
   determine the number of each item to include in a collection 
   so that the total weight is less than or equal to a given limit 
   and the total value is as large as possible.
   */


#include <stdio.h>
#define max(a,b) (a > b ? a : b)

#define MAX 100
#define MAX_INDEX 4
    
int knapsackSize = 10;
int nItems = MAX_INDEX;
int matrix[MAX][MAX] = {0};
int weights[] = {5,4,6,3};
int values[] = {10,40,30,50};

void dump()
{
	int i, j;
	printf ("Wei->\t\t");
	for (j=1; j < knapsackSize+1; j++)
		printf ("%d\t", j);
	printf ("\n");
	for (i=0; i < MAX_INDEX; i++)
	{
		printf ("(v%d,w%d):\t", values[i], weights[i]);
		for (j=1; j < knapsackSize+1; j++)
			printf ("%d\t", matrix[i][j]);
		printf ("\n");
	}
	printf ("\n");
}

int knapsack(int index, int size)
{
    int take,dontTake;
	printf ("[%d,%d]\n", index, size);

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
			printf ("[%d,%d]=[%d]\n", index, size, matrix[index][size]);
            return values[index];
        }
        else
		{
            matrix[index][size] = 0;
			printf ("[%d,%d]=[%d]\n", index, size, matrix[index][size]);
            return 0;
        }
    }

	//Including the index
    if (weights[index]<=size)
        take = values[index] + knapsack(index-1, size-weights[index]);

	//Excluding the index
    dontTake = knapsack(index-1, size);

	printf ("[%d,%d] %d,%d\n", index, size, take, dontTake);
    matrix[index][size] = max (take, dontTake);
	printf ("[%d,%d]=[%d]\n", index, size, matrix[index][size]);
	//dump();

    return matrix[index][size];

}

int main()
{

    knapsack(nItems-1,knapsackSize);
	dump();
    printf("Max value = %d\n",matrix[MAX_INDEX-1][knapsackSize]);

    return 0;
}
