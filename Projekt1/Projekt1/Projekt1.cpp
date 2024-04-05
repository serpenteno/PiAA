#include <iostream>
#include <chrono>
#include "MergeSort.h"
#include "QuickSort.h"
#include "BucketSort.h"

long long MeasureTime(const std::chrono::steady_clock::time_point Start, const std::chrono::steady_clock::time_point End)
{
	auto Duration = std::chrono::duration_cast<std::chrono::milliseconds>(End - Start);
	return Duration.count();
}

int main()
{
	setlocale(LC_ALL, "pl_PL");

	int NumberOfData;
	do
	{
		system("cls");
		std::cout << "Wybierz iloúÊ danych:\n1. 10 000\n2. 100 000\n3. 500 000\n4. 1 000 000\n5. Niestandardowa\n6. Wyjdü\n";
		std::cin >> NumberOfData;
	} while (NumberOfData != 1 && NumberOfData != 2 && NumberOfData != 3 && NumberOfData != 4 && NumberOfData != 5 && NumberOfData != 6);

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

	case 5:
		std::cin >> NumberOfData;
		break;

	case 6:
		return 0;

	default:
		system("cls");
		std::cout << "Unknown error has occured" << std::endl;
		return 1;
	}

	char SortingType;
	do
	{
		system("cls");
		std::cout << "Jaki rodzaj sortowania? (M - MergeSort, Q - QuickSort, B - BucketSort): ";
		std::cin >> SortingType;
	} while (SortingType != 'M' && SortingType != 'Q' && SortingType != 'B');

	DataReader* SortingAlgorythm; // Wskaünik na wybrany algorytm

	switch (SortingType)
	{
	case 'M':
	{
		SortingAlgorythm = new MergeSort(NumberOfData);
		break;
	}

	case 'Q':
	{
		SortingAlgorythm = new Quicksort(NumberOfData);
		break;
	}
	case 'B':
	{
		SortingAlgorythm = new BucketSort(NumberOfData);
		break;
	}

	default:
		system("cls");
		std::cout << "Unknown error has occured" << std::endl;
		return 1;
	}

	auto ReadingStart = std::chrono::high_resolution_clock::now();
	SortingAlgorythm->ReadDataFromFile();
	auto ReadingStop = std::chrono::high_resolution_clock::now();

	system("cls");
	std::cout << "-----Przed sortowaniem-----\n";
	std::cout << "Rzeczywista iloúÊ pobranych danych: " << SortingAlgorythm->Size << std::endl;
	std::cout << "Czas odczytywania: " << MeasureTime(ReadingStart, ReadingStop) << " ms" << std::endl;
	std::cout << "årednia ocen: " << SortingAlgorythm->CalculateAverage() << std::endl;
	std::cout << "Mediana ocen: " << SortingAlgorythm->CalculateMedian() << std::endl;

	auto SortingStart = std::chrono::high_resolution_clock::now();
	SortingAlgorythm->Sort(SortingAlgorythm->Movies, 0, SortingAlgorythm->Size - 1);
	auto SortingStop = std::chrono::high_resolution_clock::now();

	std::cout << "-----Po sortowaniu-----\n";
	std::cout << "Typ sortowania: " << SortingAlgorythm->Name << std::endl;
	std::cout << "Czas sortowania: " << MeasureTime(SortingStart, SortingStop) << " ms" << std::endl;

	delete SortingAlgorythm;

	return 0;
}