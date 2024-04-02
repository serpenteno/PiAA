#include "BucketSort.h"

BucketSort::BucketSort(const int MovieContainerSize)
	: DataReader(MovieContainerSize) { }

void BucketSort::Sort(std::vector<Movie>& OutMovieContainer, const int Begin, const int End)
{
	int MaxValue = Movies[0].Rating; // Maksymalna ocena w podanym kontenerze
	int MinValue = Movies[0].Rating; // Minimalna ocena w podanym kontenerze

	for (int Index = 1; Index < Movies.size(); Index++)
	{
		if (Movies.at(Index).Rating > MaxValue)
		{
			MaxValue = Movies.at(Index).Rating;
		}
		if (Movies.at(Index).Rating < MinValue)
		{
			MinValue = Movies.at(Index).Rating;
		}
	}

	const int Range = MaxValue - MinValue + 1;

	std::vector<Movie>* Buckets = new std::vector<Movie>[Range]; // Kube�ki na elementy

	for (int BucketIndex = 0; BucketIndex < Range; BucketIndex++)
	{
		Buckets[BucketIndex] = std::vector<Movie>(); // Ka�dy kube�ek jest kontenerem przechowuj�cym filmy
	}

	for (int Index = 0; Index < OutMovieContainer.size(); Index++) // Wstawianie element�w z tak� sam� ocen� do tych samych kube�k�w
	{
		const int BucketIndex = MaxValue - OutMovieContainer.at(Index).Rating;
		Buckets[BucketIndex].push_back(OutMovieContainer.at(Index));
	}

	int Index = 0; // Przechodzenie po oryginalnym kontenerze od pocz�tku

	for (int Bucket = 0; Bucket < Range; Bucket++)
	{
		size_t BucketSize = Buckets[Bucket].size(); // Rozmiar obecnego kube�ka
		if (BucketSize > 0)
		{
			for (int BucketIndex = 0; BucketIndex < BucketSize; BucketIndex++)
			{
				OutMovieContainer.at(Index) = Buckets[Bucket][BucketIndex]; // Ka�dy kolejny element z kube�ka zostaje wpisany w oryginalny kontener
				Index++;
			}
		}
	}
}
