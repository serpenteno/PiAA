#pragma once
#include <string>
#include <vector>

/** Struktura przechowuj¹ca dane dotycz¹ce filmu */
struct Movie
{
	unsigned int Index;
	std::string Title;
	int Rating;
};

/** Klasa odczytuje i zapisuje filmy z pliku do kontenera na filmy */
class DataReader
{
public:
	/** 
	 * Konstruktor
	 * @param MovieContainerSize - rozmiar kontenera na filmy, które program pobiera z pliku
	*/
	DataReader(const int MovieContainerSize);

	/** Kontener na filmy */
	std::vector<Movie> Movies;

	/** Odczytuje dane z pliku */
	void ReadDataFromFile();

	/** Dodaj nowy film do kontenera */
	void AddMovie(int MovieIndex, std::string MovieTitle, int MovieRating);

	/** Wyœwietla zgromadzone filmy */
	void PrintMovies() const;

	/** Iloœæ pobranych danych */
	int Size;
};

