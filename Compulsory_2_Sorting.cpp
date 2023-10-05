#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>

//Sorting Algorithms
#include "QuickSort.h"
#include "BubbleSort.h"
#include "SelectionSort.h"



enum SortingMethod {Bubble, Quick, Selection};
SortingMethod SelectedSortingMethod;

// Create Vector and size
std::vector<int> myVector;
int Size = 10;
int MaxNumberSize = 100;
bool PrintVectorB = false;

void SortFunction();


void fillVector(std::vector<int> &inVector, int arr_size, int inMaxNumberSize)
{
	for (int i{}; i < arr_size; i++)
	{
		inVector.push_back(rand());
		// % inMaxNumberSize + 1
	}
}

void printVector(std::vector<int> &inVector)
{
	int Size = inVector.size();
	for (int i{}; i < Size; i++)
	{
		std::cout << inVector[i] << " ";
	}
	std::cout << std::endl;
}

//userInput
void getInputForVector()
{
	
	//Size of vector
	while (true)
	{
		std::string inputString;
		std::cout << "Enter size of vector: ";
		std::cin >> Size;
		if (Size >= 1)
		{
			break;
		}
		else
		{
			std::cout << "Invalid input " << "(Has to be int higher than 0)" << std::endl;
		}
	}
	
	//Max number size
	while (true)
	{
		std::string inputString;
		std::cout << "Enter Max number: ";
		std::cin >> MaxNumberSize;
		if (MaxNumberSize >= 1)
		{
			break;
		}
		else
		{
			std::cout << "Invalid input " << "(Has to be int higher than 0)" << std::endl;
		}
	}
	
	//Print numbers?
	while (true)
	{
		std::string inputString;
		std::cout << "Print values?: (true/false) ";
		std::cin >> inputString;
		std::transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
		if (inputString == "true" || inputString == "t" || inputString == "1")
		{
			PrintVectorB = true;
			break;
		}
		else if (inputString == "false" || inputString == "f" || inputString == "0")
		{
			PrintVectorB = false;
			break;
		}
		else
		{
			std::cout << "Invalid input " << "(Has to be true or false)" << std::endl;
		}
	}
	//Fill vector with numbers
	fillVector(myVector, Size, MaxNumberSize);
	SortFunction();
}

void SortFunction()
{
	//Create N
	int n;
	
	
	//Print vector
	if(PrintVectorB)
	{
		printVector(myVector);
	}
	
	//Create sorting objects
	QuickSort quick_sort;
	BubbleSort bubble_sort;
	SelectionSort selection_sort;
	
	//Sorting
	std::cout << std::endl << "Sorting..." << std::endl << std::endl;
	
	auto start = std::chrono::high_resolution_clock::now();
	
	switch (SelectedSortingMethod)
	{
	case Bubble:
		std::cout << "Sorting Method: BubbleSort" << std::endl;
		bubble_sort.Sort(myVector);
		break;
	case Quick:
		std::cout << "Sorting Method: QuickSort" << std::endl;
		n = myVector.size();
		quick_sort.Sort(myVector, 0, n -1);
		break;
	case Selection:
		std::cout << "Sorting Method: SelectionSort" << std::endl;
		selection_sort.Sort(myVector, myVector.size(), 0);
		break;
	default:
		std::cout << "No sorting method selected" << std::endl;
		break;
	}
	
	auto stop = std::chrono::high_resolution_clock::now();
	
	std::cout << std::endl << "Sorting complete" << std::endl << std::endl;
	
	
	//Print vector
	if(PrintVectorB)
	{
		printVector(myVector);
	}
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	
	std::cout << std::endl << "Elements: " << Size << std::endl;
	std::cout << "Duration: " << duration.count() << " Ms" << std::endl;
}
int main()
{
	//set seed to random number
	srand(time(NULL));
	
	while (true)
	{
		while (true)
		{
			std::cout << "Select sorting method: QuickSort (1), SelectionSort (2), Bubblesort (3)" << std::endl;
			std::string inputString;
			std::cin >> inputString;
			std::transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
		
			if (inputString == "quick" || inputString == "quicksort" || inputString == "quick sort" || inputString == "q" || inputString == "1")
			{
				SelectedSortingMethod = Quick;
				std::cout << "Quicksort selected" << std::endl;
				break;
			}
			else if (inputString == "selection" || inputString == "selectionsort" || inputString == "selection sort" || inputString == "s" || inputString == "2")
			{
				SelectedSortingMethod = Selection;
				std::cout << "SelectionSort selected" << std::endl;
				break;
			}
			else if (inputString == "bubble" || inputString == "bubblesort" || inputString == "bubble sort" || inputString == "b" || inputString == "3")
			{
				SelectedSortingMethod = Bubble;
				std::cout << "BubbleSort selected" << std::endl;
				break;
			}
			else
			{
				std::cout << "Invalid input" << std::endl;
			}
		}
		getInputForVector();
		break;
	}
	
	
	
	
	
	
	return 1; 
}