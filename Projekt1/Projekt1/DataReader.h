#pragma once
#include <string>
#include <vector>

/** Struktura przechowuj�ca dane dotycz�ce filmu */
struct Movie
{
	int Index;
	std::string Title;
	int Rating;
};

/** Klasa odczytuje i zapisuje filmy z pliku do kontenera na filmy */
class DataReader
{
public:
	/** 
	 * Konstruktor
	 * @param MovieContainerSize - rozmiar kontenera na filmy, kt�re program pobiera z pliku
	*/
	DataReader(const int MovieContainerSize);

	/** Kontener na filmy */
	std::vector<Movie> Movies;

	/** Odczytuje dane z pliku */
	void ReadDataFromFile();

	/** Wy�wietla zgromadzone filmy */
	void PrintMovies() const;

	/** Liczba pobranych danych podana przez u�ytkownika */
	int Size;

	/** Zwraca �redni� ocen kontenera */
	float CalculateAverage() const { return float(SumOfRatings) / float(Size); }

	/** Zwraca median� ocen kontenera */
	float CalculateMedian() const;

	/**
	 * Funkcja sortuj�ca metod� szybkiego sortowania
	 * @param OutMovieContainer - sortowany kontener
	 * @param Begin - element, od kt�rego w��cznie kontener zostaje posortowany
	 * @param End - element, do kt�rego w��cznie kontener zostaje posortowany
	*/
	virtual void Sort(std::vector<Movie>& OutMovieContainer, const int Begin, const int End) = 0;

protected:
	/** Suma ocen z kontenera */
	int SumOfRatings;

private:
	/** 
	 * Dodaj nowy film do kontenera
	 * @param MovieIndex - indeks nowego filmu
	 * @param MovieTitle - tytu� nowego filmu
	 * @param MovieRating - ocena nowego filmu
	 * @warning MovieIndex i MovieRating musz� zosta� przekonwertowane z typu std::string na int funkcj� std::stoi
	 */
	void AddMovie(const int MovieIndex, const std::string MovieTitle, const int MovieRating);
};

