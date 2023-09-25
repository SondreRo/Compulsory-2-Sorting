#include "QuickSort.h"

/// \brief Swap two ints
/// \param a 
/// \param b 
void QuickSort::swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int QuickSort::partition(std::vector<int> &inVector, int low, int high)
{
	int pivot = inVector[high];

	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (inVector[j] < pivot)
		{
			i++;
			swap(&inVector[i], &inVector[j]);
		}
	}
	swap (&inVector[i + 1], &inVector[high]);
	return (i + 1);
}

void QuickSort::Sort(std::vector<int> &inVector, int low, int high)
{
	if (low <= high)
	{
		int pi = partition(inVector, low, high);

		Sort(inVector, low, pi -1);
		Sort(inVector, pi+1, high);
	}
}
