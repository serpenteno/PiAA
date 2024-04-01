#include "MergeSort.h"

MergeSort::MergeSort(const int MovieContainerSize)
	: DataReader(MovieContainerSize) { }

void MergeSort::Sort(std::vector<Movie>& OutMovieContainer, const int Begin, const int End)
{
	if (Begin < End)
	{
		int Mid = Begin + (End - Begin) / 2;

		Sort(OutMovieContainer, Begin, Mid);
		Sort(OutMovieContainer, Mid + 1, End);
		Merge(OutMovieContainer, Begin, Mid, End);
	}
}

void MergeSort::Merge(std::vector<Movie>& OutMovieContainer, const int Left, const int Mid, const int Right)
{
	const int SizeOfLeftSubarray = Mid - Left + 1;	// Ilo�� element�w w lewej po�owie kontenera
	const int SizeOfRightSubarray = Right - Mid;	// Ilo�� element�w w prawej po�owie kontenera

	std::vector<Movie> LeftSubarray(SizeOfLeftSubarray);	// Tymczasowy kontener na filmy z lewej po�owy
	std::vector<Movie> RightSubarray(SizeOfRightSubarray);	// Tymczasowy kontener na filmy z prawej po�owy

	for (int i = 0; i < SizeOfLeftSubarray; i++)
	{
		LeftSubarray[i] = OutMovieContainer[Left + i]; // Kopiowanie element�w z lewej po�owy oryginalnej tablicy
	}
	for (int i = 0; i < SizeOfRightSubarray; i++)
	{
		RightSubarray[i] = OutMovieContainer[Mid + 1 + i]; // Kopiowanie element�w z prawej po�owy oryginalnej tablicy
	}

	int IndexOfLeftSubarray = 0;
	int IndexOfRightSubarray = 0;
	int IndexOfMergedArray = Left;

	while ((IndexOfLeftSubarray < SizeOfLeftSubarray) && (IndexOfRightSubarray < SizeOfRightSubarray)) // Scala obie podtablice w posortowany kontener
	{
		if (LeftSubarray[IndexOfLeftSubarray].Rating >= RightSubarray[IndexOfRightSubarray].Rating) 
		{
			OutMovieContainer[IndexOfMergedArray] = LeftSubarray[IndexOfLeftSubarray];
			IndexOfLeftSubarray++;
		}
		else
		{
			OutMovieContainer[IndexOfMergedArray] = RightSubarray[IndexOfRightSubarray];
			IndexOfRightSubarray++;
		}
		IndexOfMergedArray++;
	}

	while (IndexOfLeftSubarray < SizeOfLeftSubarray) // Kopiuje pozosta�e elementy z lewej podtablicy, je�li jakie� zosta�y
	{
		OutMovieContainer[IndexOfMergedArray] = LeftSubarray[IndexOfLeftSubarray];
		IndexOfLeftSubarray++;
		IndexOfMergedArray++;
	}

	while (IndexOfRightSubarray < SizeOfRightSubarray) // Kopiuje pozosta�e elementy z prawej podtablicy, je�li jakie� zosta�y
	{
		OutMovieContainer[IndexOfMergedArray] = RightSubarray[IndexOfRightSubarray];
		IndexOfRightSubarray++;
		IndexOfMergedArray++;
	}
}
