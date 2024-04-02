#pragma once
#include "DataReader.h"

/** 
 * Klasa sortuje filmy przez scalanie 
   Opis: Sortowana tablica dzielona jest rekurencyjnie na dwie podtablice a� do uzyskania tablic jednoelementowych. 
   Nast�pnie podtablice te s� scalane w odpowiedni spos�b, daj�cy w rezultacie tablic� posortowan�. 
   Wykorzystana jest tu metoda podzia�u problemu na mniejsze, �atwiejsze do rozwi�zania zadania (�dziel i rz�d��).
 */
class MergeSort final : public DataReader
{
public:
	/**
	 * Konstruktor
	 * @param MovieContainerSize - rozmiar kontenera na filmy, kt�re program pobiera z pliku
	*/
	MergeSort(const int MovieContainerSize);

	/**
	 * Funkcja sortuj�ca przez scalanie
	 * @param OutMovieContainer - sortowany kontener
	 * @param Begin - element, od kt�rego w��cznie kontener zostaje posortowany
	 * @param End - element, do kt�rego w��cznie kontener zostaje posortowany
	*/
	virtual void Sort(std::vector<Movie>& OutMovieContainer, const int Begin, const int End) override;

private:
	/**
	 * Funkcja scalaj�ca lew� i praw� cz�� kontenera na filmy
	 * @param OutMovieContainer - kontener na filmy, kt�rego dane s� scalane
	 * @param Left - element kontenera znajduj�cy si� na pocz�tku
	 * @param Mid - element kontenera znajduj�cy si� w �rodku
	 * @param Right - element kontenera znajduj�cy si� na ko�cu
	*/
	void Merge(std::vector<Movie>& OutMovieContainer, const int Left, const int Mid, const int Right);
};

