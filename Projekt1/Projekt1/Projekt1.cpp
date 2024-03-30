#include <iostream>
#include "MergeSort.h"

int main()
{

	int NumberOfData;

	do
	{
		std::cout << "Ile danych?: ";
		std::cin >> NumberOfData;
	} while (NumberOfData <= 0);

	MergeSort MergeSortedDatabase(NumberOfData);

	MergeSortedDatabase.ReadDataFromFile();
	MergeSortedDatabase.Sort(MergeSortedDatabase.Movies, 0, MergeSortedDatabase.Size - 1);
	std::cout << "Po sortowaniu: " << std::endl;
	MergeSortedDatabase.PrintMovies();
}