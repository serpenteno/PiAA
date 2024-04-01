#pragma once
#include <string>
#include <vector>

/** Struktura przechowuj¹ca dane dotycz¹ce filmu */
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
	 * @param MovieContainerSize - rozmiar kontenera na filmy, które program pobiera z pliku
	*/
	DataReader(const int MovieContainerSize);

	/** Kontener na filmy */
	std::vector<Movie> Movies;

	/** Odczytuje dane z pliku */
	void ReadDataFromFile();

	/** Wyœwietla zgromadzone filmy */
	void PrintMovies() const;

	/** Iloœæ pobranych danych */
	int Size;

private:
	/** 
	 * Dodaj nowy film do kontenera
	 * @param MovieTitle - tytu³ nowego filmu
	 * @param MovieRating - ocena nowego filmu
	 * @warning MovieIndex i MovieRating musz¹ zostaæ przekonwertowane z typu std::string na int funkcj¹ std::stoi
	 */
	void AddMovie(const std::string MovieTitle, const int MovieRating);
};

