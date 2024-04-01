#pragma once
#include "DataReader.h"

/**
 * Klasa sortuj�ca metod� kube�kow�
   Opis: Na pocz�tku tablica dzielona jest na kilka podtablic o r�wnej d�ugo�ci. 
*/
class BucketSort : public DataReader
{
public:
	/**
	 * Konstruktor
	 * @param MovieContainerSize - rozmiar kontenera na filmy, kt�re program pobiera z pliku
	*/
	BucketSort(const int MovieContainerSize);

	/**
	 * Funkcja dziel�ca kontener na podzbiory/kube�ki
	 * @param OutMovieContainer - sortowany kontener
	*/
	void Sort(std::vector<Movie>& OutMovieContainer);
};

