#pragma once
#include <string>
#include <vector>

/** Struktura przechowuj�ca dane dotycz�ce filmu */
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
	 * @param MovieContainerSize - rozmiar kontenera na filmy, kt�re program pobiera z pliku
	*/
	DataReader(const int MovieContainerSize);

	/** Kontener na filmy */
	std::vector<Movie> Movies;

	/** Odczytuje dane z pliku */
	void ReadDataFromFile();

	/** Dodaj nowy film do kontenera */
	void AddMovie(int MovieIndex, std::string MovieTitle, int MovieRating);

	/** Wy�wietla zgromadzone filmy */
	void PrintMovies() const;

	/** Ilo�� pobranych danych */
	int Size;
};

