#pragma once
#include <string>
#include <vector>

/** Struktura przechowuj�ca dane dotycz�ce filmu */
struct Movie
{
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

	/** Ilo�� pobranych danych */
	int Size;

private:
	/** 
	 * Dodaj nowy film do kontenera
	 * @param MovieTitle - tytu� nowego filmu
	 * @param MovieRating - ocena nowego filmu
	 * @warning MovieIndex i MovieRating musz� zosta� przekonwertowane z typu std::string na int funkcj� std::stoi
	 */
	void AddMovie(const std::string MovieTitle, const int MovieRating);
};

