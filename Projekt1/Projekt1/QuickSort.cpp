#include "QuickSort.h"
#include <iostream>

Quicksort::Quicksort(const int MovieContainerSize)
	: DataReader(MovieContainerSize) 
{
    Name = "Quicksort";
    do
    {
        std::cout << "Wybierz element osiowy (0 - pierwszy element, 1 - œrodkowy element, 2 - ostatni element): ";
        std::cin >> PivotChoice;
    } while (PivotChoice != 2 && PivotChoice != 1 && PivotChoice != 0);
}

void Quicksort::Sort(std::vector<Movie>& OutMovieContainer, const int Begin, const int End)
{
	if (Begin < End) 
	{
		int PivotIndex = Partition(OutMovieContainer, Begin, End);
        if (PivotChoice == 1)
        {
            Sort(OutMovieContainer, Begin, PivotIndex);
        }
        else
        {
            Sort(OutMovieContainer, Begin, PivotIndex - 1);
        }
        Sort(OutMovieContainer, PivotIndex + 1, End);
	}
}

int Quicksort::Partition(std::vector<Movie>& OutMovieContainer, const int Begin, const int End)
{
    Movie Pivot;                        // Element osiowy
    int BiggerRatingElement = Begin;   // Liczba elementów o wiêkszej ocenie ni¿ element osiowy
    switch (PivotChoice)                // Wybór elementu osiowego
    {
    case 0:
        Pivot = OutMovieContainer[Begin]; // Pierwszy element jest elementem osiowym

        for (int CurrentElementIndex = BiggerRatingElement + 1; CurrentElementIndex <= End; CurrentElementIndex++)
        {
            if (OutMovieContainer[CurrentElementIndex].Rating >= Pivot.Rating)
            {
                BiggerRatingElement++; //Postinkrementacja przed zamianie
                std::swap(OutMovieContainer[BiggerRatingElement], OutMovieContainer[CurrentElementIndex]); // Zamienia elementy miejscami w kontenerze
            }
        }
        std::swap(OutMovieContainer[Begin], OutMovieContainer[BiggerRatingElement]); // Element osiowy zostaje przestawiony

        return BiggerRatingElement;

    case 1:
    {
        Pivot = OutMovieContainer[(Begin + End) / 2]; // Œrodkowy element jest elementem osiowym

        BiggerRatingElement--;
        int LowerRatingElement = End + 1; // Liczba elementów o mniejszej ocenie ni¿ element osiowy

        while (true)
        {
            do
            {
                BiggerRatingElement++;
            } while (OutMovieContainer[BiggerRatingElement].Rating > Pivot.Rating); // Szukanie pierwszego od lewej elementu o wiêkszej ocenie ni¿ element osiowy 
            do
            {
                LowerRatingElement--;
            } while (OutMovieContainer[LowerRatingElement].Rating < Pivot.Rating); // Szukanie pierwszego od prawej elementu o ni¿szej ocenie ni¿ element osiowy 

            if (BiggerRatingElement >= LowerRatingElement) // Jeœli element o wiêkszej ocenie zosta³ znaleziony póŸniej lub w takim samym czasie
            {
                return LowerRatingElement; // LowerRatingElement podzieli konetner na dwie czêœci, które nastêpnie zostan¹ posortowane
            }
            else
            {
                std::swap(OutMovieContainer[BiggerRatingElement], OutMovieContainer[LowerRatingElement]); // W innym wypadku zamienia elementy w nieodpowiednich miejscach pozycj¹
            }
        }
    }

    case 2:
        Pivot = OutMovieContainer[End]; // Ostatni element jest elementem osiowym

        for (int CurrentElementIndex = BiggerRatingElement; CurrentElementIndex < End; CurrentElementIndex++)
        {
            if (OutMovieContainer[CurrentElementIndex].Rating >= Pivot.Rating)
            {
                std::swap(OutMovieContainer[BiggerRatingElement], OutMovieContainer[CurrentElementIndex]); // Zamienia elementy miejscami w kontenerze
                BiggerRatingElement++; //Postinkrementacja po zamianie
            }
        }
        std::swap(OutMovieContainer[BiggerRatingElement], OutMovieContainer[End]); // Element osiowy zostaje przestawiony

        return BiggerRatingElement;

    default:
        std::cout << "Unknown error has occured" << std::endl;
        exit(1);
    }
}

