#pragma once
#include "DataReader.h"

/** 
 * Klasa sortuj�ca metod� szybkiego sortowania
   Opis: Na pocz�tku wybierany jest tzw. element osiowy. Nast�pnie tablica dzielona jest na dwie podtablice. 
   Pierwsza z nich zawiera elementy mniejsze od elementu osiowego, druga elementy wi�ksze lub r�wne,
   element osiowy znajdzie si� mi�dzy nimi. Proces dzielenia powtarzany jest a� do uzyskania tablic jednoelementowych, 
   nie wymagaj�cych sortowania. W�a�ciwe sortowanie jest tu jakby ukryte w procesie przygotowania do sortowania. 
   Wyb�r elementu osiowego wp�ywa na r�wnomierno�� podzia�u na podtablice (najprostszy wariant � 
   wyb�r pierwszego elementu tablicy � nie sprawdza si� w przypadku, gdy tablica jest ju� prawie uporz�dkowana).
*/
class QuickSort final : public DataReader
{
public:
	/**
	 * Konstruktor
	 * @param MovieContainerSize - rozmiar kontenera na filmy, kt�re program pobiera z pliku
	*/
	QuickSort(const int MovieContainerSize);

	/**
	 * Funkcja sortuj�ca metod� szybkiego sortowania
	 * @param OutMovieContainer - sortowany kontener
	 * @param Begin - element, od kt�rego w��cznie kontener zostaje posortowany
	 * @param End - element, do kt�rego w��cznie kontener zostaje posortowany
	*/
	void Sort(std::vector<Movie>& OutMovieContainer, const int Begin, const int End);

private:
	/**
	 * Funkcja dziel�ca kontener wzgl�dem elementu osiowego
	 * @param OutMovieContainer - sortowany kontener
	 * @param Begin - pierwszy element dzielonego zbioru
	 * @param End - ostatni element dzielonego zbioru
	*/
	int Partition(std::vector<Movie>& OutMovieContainer, const int Begin, const int End);

	/** U�ytkownik wybiera element osiowy */
	int PivotChoice;

};

