#include "SelectionSort.h"

int SelectionSort::findMin(std::vector<int> &inVector, int i, int j)
{
	int minpos;
	if (i == j){
		return i;
	}
	minpos = findMin(inVector, i + 1, j);
	if(inVector[i]<inVector[minpos]){
		minpos=i;
	}
	return (minpos);
}

void SelectionSort::Sort(std::vector<int> &inVector, int len1, int pos1)
{
	int temp;
	int minpos1;
	if (pos1 == len1){
		return;
	}
	minpos1 = findMin(inVector, pos1, len1-1);
	if (minpos1 != pos1){
		temp=inVector[pos1];
		inVector[pos1]=inVector[minpos1];
		inVector[minpos1]=temp;
	}
	Sort(inVector, len1, pos1 + 1);
}
