//==================================================//
//				SEQUENTIAL QUICK SORT				//
//==================================================//
#include <stdio.h>
#include <stdlib.h>

#define ITEMS 10
#define DEBUG 1

static int* v;

static void InitArray(void);
static void QuickSort(int*, unsigned, unsigned);
static unsigned Partition(int*, unsigned, unsigned, unsigned);
static void Swap(int*, unsigned, unsigned);
static void PrintArray(void);

int main(int argc, char **argv)
{
	// Initialize the array.
    InitArray();

	// Print data if in debug mode.
	if(DEBUG)
	{
		printf("===== BEFORE QUICK SORT (SEQ) =====\n\n");
		PrintArray();
		printf("===================================\n\n\n");
	}

	// Quick sort the array.
    QuickSort(v, 0, (ITEMS - 1));

	// Print data if in debug mode.
	if(DEBUG)
	{
		printf("===== AFTER QUICK SORT (SEQ) ======\n\n");
		PrintArray();
		printf("===================================\n\n");
	}

	system("pause");
}

// Initialization of array.
static void InitArray(void)
{
	int i;

	v = (int*)malloc(ITEMS * sizeof(int));
	
    for (i = 0; i < ITEMS; i++)
	{
        v[i] = rand();
	}
}

// Sorting function.
static void QuickSort(int *v, unsigned low, unsigned high)
{
    unsigned pivot_index;
    
    // No need to sort a vector of zero or one element.
    if (low >= high)
	{
        return;
	}

    // Select the pivot value.
    pivot_index = (low + high) / 2;

    // Partition the array.
    pivot_index = Partition(v, low, high, pivot_index);

    // Sort the two sub arrays.
    if (low < pivot_index)
	{
        QuickSort(v, low, (pivot_index - 1));
	}

    if (pivot_index < high)
	{
        QuickSort(v, (pivot_index + 1), high);
	}
}

// Array partitioning function.
static unsigned Partition(int *v, unsigned low, unsigned high, unsigned pivot_index)
{
    // Move pivot to the bottom of the vector.
    if (pivot_index != low)
	{
        Swap(v, low, pivot_index);
	}

    pivot_index = low;
    low++;

    // Move elements into place.
    while (low <= high) 
	{
        if (v[low] <= v[pivot_index])
		{
            low++;
		}

        else if (v[high] > v[pivot_index])
		{
            high--;
		}

        else
		{
            Swap(v, low, high);
		}
    }

    // Put pivot back between two groups.
    if (high != pivot_index)
	{
        Swap(v, pivot_index, high);
	}

    return high;
}

// Swap function.
static void Swap(int* v, unsigned a, unsigned b) 
{
	unsigned tmp; 
	tmp = v[a]; 
	v[a] = v[b]; 
	v[b] = tmp;
}

// Print function.
static void PrintArray(void)
{
    int i;

	printf("[");

    for (i = 0; i < (ITEMS - 1); i++)
	{
        printf("%d, ", v[i]);
	}

	printf("%d]\n\n", v[ITEMS]);
}