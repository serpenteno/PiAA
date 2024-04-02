#pragma once
#include "DataReader.h"

/** 
 * Klasa sortuje filmy przez scalanie 
   Opis: Sortowana tablica dzielona jest rekurencyjnie na dwie podtablice a¿ do uzyskania tablic jednoelementowych. 
   Nastêpnie podtablice te s¹ scalane w odpowiedni sposób, daj¹cy w rezultacie tablicê posortowan¹. 
   Wykorzystana jest tu metoda podzia³u problemu na mniejsze, ³atwiejsze do rozwi¹zania zadania („dziel i rz¹dŸ”).
 */
class MergeSort final : public DataReader
{
public:
	/**
	 * Konstruktor
	 * @param MovieContainerSize - rozmiar kontenera na filmy, które program pobiera z pliku
	*/
	MergeSort(const int MovieContainerSize);

	/**
	 * Funkcja sortuj¹ca przez scalanie
	 * @param OutMovieContainer - sortowany kontener
	 * @param Begin - element, od którego w³¹cznie kontener zostaje posortowany
	 * @param End - element, do którego w³¹cznie kontener zostaje posortowany
	*/
	virtual void Sort(std::vector<Movie>& OutMovieContainer, const int Begin, const int End) override;

private:
	/**
	 * Funkcja scalaj¹ca lew¹ i praw¹ czêœæ kontenera na filmy
	 * @param OutMovieContainer - kontener na filmy, którego dane s¹ scalane
	 * @param Left - element kontenera znajduj¹cy siê na pocz¹tku
	 * @param Mid - element kontenera znajduj¹cy siê w œrodku
	 * @param Right - element kontenera znajduj¹cy siê na koñcu
	*/
	void Merge(std::vector<Movie>& OutMovieContainer, const int Left, const int Mid, const int Right);
};

