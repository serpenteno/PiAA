#pragma once
#include "DataReader.h"

/** Klasa sortuje filmy przez scalanie */
class MergeSort : public DataReader
{
public:
	/**
	 * Konstruktor
	 * @param MovieContainerSize - rozmiar kontenera na filmy, kt�re program pobiera z pliku
	*/
	MergeSort(const int MovieContainerSize);

	/**
	 * Funkcja scalaj�ca lew� i praw� cz�� kontenera na filmy
	 * @param OutMovieContainer - kontener na filmy, kt�rego dane s� scalane
	 * @param Left - element kontenera znajduj�cy si� na pocz�tku
	 * @param Mid - element kontenera znajduj�cy si� w �rodku
	 * @param Right - element kontenera znajduj�cy si� na ko�cu
	*/
	void Merge(std::vector<Movie>& OutMovieContainer, const int Left, const int Mid, const int Right);

	/** 
	 * Funkcja sortuj�ca przez scalanie
	 * @param OutMovieContainer - kontener sortowany przez scalanie
	 * @param Begin - element, od kt�rego w��cznie kontener zostaje posortowany
	 * @param End - element, do kt�rego w��cznie kontener zostaje posortowany
	*/
	void Sort(std::vector<Movie>& OutMovieContainer, const int Begin, const int End);
};

