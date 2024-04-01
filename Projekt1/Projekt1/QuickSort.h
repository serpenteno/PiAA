#pragma once
#include "DataReader.h"

/** 
 * Klasa sortuj¹ca metod¹ szybkiego sortowania
   Opis: Na pocz¹tku wybierany jest tzw. element osiowy. Nastêpnie tablica dzielona jest na dwie podtablice. 
   Pierwsza z nich zawiera elementy mniejsze od elementu osiowego, druga elementy wiêksze lub równe,
   element osiowy znajdzie siê miêdzy nimi. Proces dzielenia powtarzany jest a¿ do uzyskania tablic jednoelementowych, 
   nie wymagaj¹cych sortowania. W³aœciwe sortowanie jest tu jakby ukryte w procesie przygotowania do sortowania. 
   Wybór elementu osiowego wp³ywa na równomiernoœæ podzia³u na podtablice (najprostszy wariant – 
   wybór pierwszego elementu tablicy – nie sprawdza siê w przypadku, gdy tablica jest ju¿ prawie uporz¹dkowana).
*/
class QuickSort final : public DataReader
{
public:
	/**
	 * Konstruktor
	 * @param MovieContainerSize - rozmiar kontenera na filmy, które program pobiera z pliku
	*/
	QuickSort(const int MovieContainerSize);

	/**
	 * Funkcja sortuj¹ca metod¹ szybkiego sortowania
	 * @param OutMovieContainer - sortowany kontener
	 * @param Begin - element, od którego w³¹cznie kontener zostaje posortowany
	 * @param End - element, do którego w³¹cznie kontener zostaje posortowany
	*/
	void Sort(std::vector<Movie>& OutMovieContainer, const int Begin, const int End);

private:
	/**
	 * Funkcja dziel¹ca kontener wzglêdem elementu osiowego
	 * @param OutMovieContainer - sortowany kontener
	 * @param Begin - pierwszy element dzielonego zbioru
	 * @param End - ostatni element dzielonego zbioru
	*/
	int Partition(std::vector<Movie>& OutMovieContainer, const int Begin, const int End);

	/** U¿ytkownik wybiera element osiowy */
	int PivotChoice;

};

