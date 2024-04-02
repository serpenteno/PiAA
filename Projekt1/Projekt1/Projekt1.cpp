#include <iostream>
#include <chrono>
#include "MergeSort.h"
#include "QuickSort.h"
#include "BucketSort.h"

long long MeasureTime(const std::chrono::steady_clock::time_point Start, const std::chrono::steady_clock::time_point End)
{
	std::chrono::microseconds Duration = std::chrono::duration_cast<std::chrono::milliseconds>(End - Start);
	return Duration.count();
}

int main()
{
	setlocale(LC_ALL, "pl_PL");

	int NumberOfData;
	do
	{
		system("cls");
		std::cout << "Wybierz iloœæ danych:\n1. 10 000\n2. 100 000\n3. 500 000\n4. 1 000 000\n";
		std::cin >> NumberOfData;
	} while (NumberOfData < 1 && NumberOfData > 4);

	switch (NumberOfData)
	{
	case 1:
		NumberOfData = 10000;
		break;

	case 2:
		NumberOfData = 100000;
		break;

	case 3:
		NumberOfData = 500000;
		break;

	case 4:
		NumberOfData = 1000000;
		break;
	}

	char SortingType;
	do
	{
		system("cls");
		std::cout << "Jaki rodzaj sortowania? (M - MergeSort, Q - QuickSort, B - BucketSort): ";
		std::cin >> SortingType;
	} while (SortingType != 'M' && SortingType != 'Q' && SortingType != 'B');

	switch (SortingType)
	{
	case 'M':
	{
		MergeSort* MergeSortedDatabase = new MergeSort(NumberOfData);

		std::chrono::steady_clock::time_point ReadingStart = std::chrono::high_resolution_clock::now();
		MergeSortedDatabase->ReadDataFromFile();
		std::chrono::steady_clock::time_point ReadingStop = std::chrono::high_resolution_clock::now();

		system("cls");
		std::cout << "-----Przed sortowaniem-----\n";
		std::cout << "Iloœæ danych: " << NumberOfData << std::endl;
		std::cout << "Czas odczytywania: " << MeasureTime(ReadingStart, ReadingStop) << std::endl;
		std::cout << "Œrednia ocen: " << MergeSortedDatabase->CalculateAverage() << std::endl;
		std::cout << "Mediana ocen: " << MergeSortedDatabase->CalculateMedian() << std::endl;

		std::chrono::steady_clock::time_point SortingStart = std::chrono::high_resolution_clock::now();
		MergeSortedDatabase->Sort(MergeSortedDatabase->Movies, 0, MergeSortedDatabase->Size - 1);
		std::chrono::steady_clock::time_point SortingStop = std::chrono::high_resolution_clock::now();

		std::cout << "-----Po sortowaniu-----\n";
		std::cout << "Typ sortowania: " << SortingType << std::endl;
		std::cout << "Czas sortowania: " << MeasureTime(SortingStart, SortingStop) << " ms" << std::endl;
		break;
	}

	case 'Q':
	{
		QuickSort* QuickSortedDatabase = new QuickSort(NumberOfData);

		std::chrono::steady_clock::time_point ReadingStart = std::chrono::high_resolution_clock::now();
		QuickSortedDatabase->ReadDataFromFile();
		std::chrono::steady_clock::time_point ReadingStop = std::chrono::high_resolution_clock::now();

		system("cls");
		std::cout << "-----Przed sortowaniem-----\n";
		std::cout << "Iloœæ danych: " << NumberOfData << std::endl;
		std::cout << "Czas odczytywania: " << MeasureTime(ReadingStart, ReadingStop) << std::endl;
		std::cout << "Œrednia ocen: " << QuickSortedDatabase->CalculateAverage() << std::endl;
		std::cout << "Mediana ocen: " << QuickSortedDatabase->CalculateMedian() << std::endl;

		std::chrono::steady_clock::time_point SortingStart = std::chrono::high_resolution_clock::now();
		QuickSortedDatabase->Sort(QuickSortedDatabase->Movies, 0, QuickSortedDatabase->Size - 1);
		std::chrono::steady_clock::time_point SortingStop = std::chrono::high_resolution_clock::now();

		std::cout << "-----Po sortowaniu-----\n";
		std::cout << "Typ sortowania: " << SortingType << std::endl;
		std::cout << "Czas sortowania: " << MeasureTime(SortingStart, SortingStop) << " ms" << std::endl;
		break;
	}

	case 'B':
	{
		BucketSort* BucketSortedDatabase = new BucketSort(NumberOfData);

		std::chrono::steady_clock::time_point ReadingStart = std::chrono::high_resolution_clock::now();
		BucketSortedDatabase->ReadDataFromFile();
		std::chrono::steady_clock::time_point ReadingStop = std::chrono::high_resolution_clock::now();

		system("cls");
		std::cout << "-----Przed sortowaniem-----\n";
		std::cout << "Iloœæ danych: " << NumberOfData << std::endl;
		std::cout << "Czas odczytywania: " << MeasureTime(ReadingStart, ReadingStop) << std::endl;
		std::cout << "Œrednia ocen: " << BucketSortedDatabase->CalculateAverage() << std::endl;
		std::cout << "Mediana ocen: " << BucketSortedDatabase->CalculateMedian() << std::endl;

		std::chrono::steady_clock::time_point SortingStart = std::chrono::high_resolution_clock::now();
		BucketSortedDatabase->Sort(BucketSortedDatabase->Movies);
		std::chrono::steady_clock::time_point SortingStop = std::chrono::high_resolution_clock::now();

		std::cout << "-----Po sortowaniu-----\n";
		std::cout << "Typ sortowania: " << SortingType << std::endl;
		std::cout << "Czas sortowania: " << MeasureTime(SortingStart, SortingStop) << " ms" << std::endl;;
	}
	}
}