#include "BubbleSort.h"

void BubbleSort::Sort(std::vector<int> &inVector, int n)
{
	bool swapped;
	for (int i{0}; i < n - 1; i++)
	{
		swapped = false;
		for (int j{0}; j < n - i - 1; j++)
		{
			if (inVector[j] > inVector[j + 1])
			{
				swap(&inVector[j], &inVector[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
		{
			break;
		}
	}
}
void BubbleSort::Sort(std::vector<int> &inVector)
{
	int size = inVector.size() - 1;
	bool swapped;
	for (int step{0}; step < size; step++)
	{
		for (int i{0}; i < size - step; i++)
		{
			if (inVector[i] > inVector[i + 1])
			{
				swap(&inVector[i], &inVector[i + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
		{
			break;
		}
	}
}
void BubbleSort::swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
