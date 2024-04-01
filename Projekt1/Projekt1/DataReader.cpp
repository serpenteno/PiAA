#include "DataReader.h"
#include <iostream>
#include <fstream>
#include <sstream>

DataReader::DataReader(const int MovieContainerSize)
{
	Size = MovieContainerSize;
}

void DataReader::ReadDataFromFile()
{
	std::ifstream File; // Otwieranie pliku
	File.open("../PAA.projekt1.dane.csv");

	if (File.is_open())
	{	
		std::string Line;
		std::string Index;
		std::string Title;
		std::string Rating;

		std::getline(File, Line);			// Pomija pierwsz� linijk�
		while (std::getline(File, Line))	// Odczytywanie kolejnych linijek
		{
			if (Movies.size() >= Size)
			{
				break; // Ko�czy dzia�anie po osi�gni�ciu rz�danej liczby danych
			}
			else
			{
				std::istringstream SingleLine(Line);

				std::getline(SingleLine, Index, ',');	// Pobiera indeks
				std::getline(SingleLine, Title, ',');	// Pobiera tytu�
				while (Title.front() == '"')			// Je�li tytu� zaczyna si� od '"' tzn., �e posiada w nazwie ',' i musi zosta� specjalnie obs�u�ony
				{
					if (Title.back() == '"')
					{
						break;
					}
					else
					{
						std::string NextTitlePart;

						std::getline(SingleLine, NextTitlePart, ',');
						Title += ',' + NextTitlePart; // Dodaje kolejne cz�ci po przecinku do tytu�u
					}
					
				}
				std::getline(SingleLine, Rating);	// Pobiera rating
				if (!Rating.empty())				// Dodaj film tylko je�li posiada rating
				{
					AddMovie(Title, std::stoi(Rating));
				}
			}
		}
	}
	else
	{
		std::cout << "Nie znaleziono podanej sciezki." << std::endl;
	}

}

void DataReader::AddMovie(const std::string MovieTitle, const int MovieRating)
{
	Movie Movie;
	Movie.Title = MovieTitle;
	Movie.Rating = MovieRating;

	Movies.push_back(Movie);
}

void DataReader::PrintMovies() const
{
	for (const Movie Movie : Movies)
	{
		std::cout << "Tytul: " << Movie.Title << ", Ocena : " << Movie.Rating << std::endl;
	}
}
