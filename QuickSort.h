#pragma once
#include <vector>

class QuickSort
{
public:
	void swap(int* a, int* b);
	int partition(std::vector<int> &inVector, int low, int high);
	void Sort(std::vector<int> &inVector, int low, int high);
	
};
