#pragma once
#include "DataReader.h"

/**
 * Klasa sortuj¹ca metod¹ kube³kow¹
   Opis: Na pocz¹tku tablica dzielona jest na kilka podtablic o równej d³ugoœci. 
*/
class BucketSort : public DataReader
{
public:
	/**
	 * Konstruktor
	 * @param MovieContainerSize - rozmiar kontenera na filmy, które program pobiera z pliku
	*/
	BucketSort(const int MovieContainerSize);

	/**
	 * Funkcja dziel¹ca kontener na podzbiory/kube³ki
	 * @param OutMovieContainer - sortowany kontener
	*/
	void Sort(std::vector<Movie>& OutMovieContainer);
};

