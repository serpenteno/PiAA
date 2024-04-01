#include <iostream>
#include "MergeSort.h"
#include "QuickSort.h"
#include "BucketSort.h"

int main()
{

	int NumberOfData;

	do
	{
		std::cout << "Ile danych?: ";
		std::cin >> NumberOfData;
	} while (NumberOfData <= 0);

	/* MergeSort MergeSortedDatabase(NumberOfData);

	MergeSortedDatabase.ReadDataFromFile();
	MergeSortedDatabase.Sort(MergeSortedDatabase.Movies, 0, MergeSortedDatabase.Size - 1);
	std::cout << "Po sortowaniu: " << std::endl;
	MergeSortedDatabase.PrintMovies(); */

	/* QuickSort QuickSortedDatabase(NumberOfData);

	QuickSortedDatabase.ReadDataFromFile();
	QuickSortedDatabase.Sort(QuickSortedDatabase.Movies, 0, QuickSortedDatabase.Size - 1);
	std::cout << "Po sortowaniu: " << std::endl;
	QuickSortedDatabase.PrintMovies(); */

	BucketSort BucketSortedDatabase(NumberOfData);

	BucketSortedDatabase.ReadDataFromFile();
	BucketSortedDatabase.Sort(BucketSortedDatabase.Movies);
	std::cout << "Po sortowaniu: " << std::endl;
	BucketSortedDatabase.PrintMovies();
}