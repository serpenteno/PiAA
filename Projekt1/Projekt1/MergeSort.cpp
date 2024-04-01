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
	const int SizeOfLeftSubarray = Mid - Left + 1;	// Iloœæ elementów w lewej po³owie kontenera
	const int SizeOfRightSubarray = Right - Mid;	// Iloœæ elementów w prawej po³owie kontenera

	std::vector<Movie> LeftSubarray(SizeOfLeftSubarray);	// Tymczasowy kontener na filmy z lewej po³owy
	std::vector<Movie> RightSubarray(SizeOfRightSubarray);	// Tymczasowy kontener na filmy z prawej po³owy

	for (int i = 0; i < SizeOfLeftSubarray; i++)
	{
		LeftSubarray[i] = OutMovieContainer[Left + i]; // Kopiowanie elementów z lewej po³owy oryginalnej tablicy
	}
	for (int i = 0; i < SizeOfRightSubarray; i++)
	{
		RightSubarray[i] = OutMovieContainer[Mid + 1 + i]; // Kopiowanie elementów z prawej po³owy oryginalnej tablicy
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

	while (IndexOfLeftSubarray < SizeOfLeftSubarray) // Kopiuje pozosta³e elementy z lewej podtablicy, jeœli jakieœ zosta³y
	{
		OutMovieContainer[IndexOfMergedArray] = LeftSubarray[IndexOfLeftSubarray];
		IndexOfLeftSubarray++;
		IndexOfMergedArray++;
	}

	while (IndexOfRightSubarray < SizeOfRightSubarray) // Kopiuje pozosta³e elementy z prawej podtablicy, jeœli jakieœ zosta³y
	{
		OutMovieContainer[IndexOfMergedArray] = RightSubarray[IndexOfRightSubarray];
		IndexOfRightSubarray++;
		IndexOfMergedArray++;
	}
}
