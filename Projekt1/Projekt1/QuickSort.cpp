#include "QuickSort.h"
#include <iostream>

QuickSort::QuickSort(const int MovieContainerSize)
	: DataReader(MovieContainerSize) 
{
    do
    {
        std::cout << "Wybierz element osiowy (0 = pierwszy element, 1 = ostatni element): ";
        std::cin >> PivotChoice;
    } while (PivotChoice != 1 && PivotChoice != 0);
}

void QuickSort::Sort(std::vector<Movie>& OutMovieContainer, const int Begin, const int End)
{
	if (Begin < End) 
	{
		int PivotIndex = Partition(OutMovieContainer, Begin, End);
		Sort(OutMovieContainer, Begin, PivotIndex - 1);
		Sort(OutMovieContainer, PivotIndex + 1, End);
	}
}

int QuickSort::Partition(std::vector<Movie>& OutMovieContainer, const int Begin, const int End)
{
    Movie Pivot;                        // Element 
    int BiggerRatingElement = Begin;    // Indeks porównywanego elementu 
    switch (PivotChoice)                // Wybór elementu osiowego
    {
    case 0:
        Pivot = OutMovieContainer[Begin];

        for (int CurrentElementIndex = BiggerRatingElement + 1; CurrentElementIndex <= End; CurrentElementIndex++)
        {
            if (OutMovieContainer[CurrentElementIndex].Rating >= Pivot.Rating)
            {
                BiggerRatingElement++; // Postinkrementacja przed zamian¹
                std::swap(OutMovieContainer[BiggerRatingElement], OutMovieContainer[CurrentElementIndex]); // Zamienia elementy miejscami w kontenerze
            }
        }
        std::swap(OutMovieContainer[Begin], OutMovieContainer[BiggerRatingElement]); // Elemet osiowy zostaje przestawiony

        return BiggerRatingElement;

    case 1:
        Pivot = OutMovieContainer[End];

        for (int CurrentElementIndex = BiggerRatingElement; CurrentElementIndex < End; CurrentElementIndex++)
        {
            if (OutMovieContainer[CurrentElementIndex].Rating >= Pivot.Rating)
            {
                std::swap(OutMovieContainer[BiggerRatingElement], OutMovieContainer[CurrentElementIndex]); // Zamienia elementy miejscami w kontenerze
                BiggerRatingElement++; //Postinkrementacja po zamianie
            }
        }
        std::swap(OutMovieContainer[BiggerRatingElement], OutMovieContainer[End]); // Elemet osiowy zostaje przestawiony

        return BiggerRatingElement;

    default:
        std::cout << "Unknown error has occured" << std::endl;
        exit(1);
    }
}

