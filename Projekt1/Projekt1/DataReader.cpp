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

		std::getline(File, Line);			// Pomija pierwsz¹ linijkê
		while (std::getline(File, Line))	// Odczytywanie kolejnych linijek
		{
			if (Movies.size() >= Size)
			{
				break; // Koñczy dzia³anie po osi¹gniêciu rz¹danej liczby danych
			}
			else
			{
				std::istringstream SingleLine(Line);

				std::getline(SingleLine, Index, ',');	// Pobiera indeks
				std::getline(SingleLine, Title, ',');	// Pobiera tytu³
				while (Title.front() == '"')			// Jeœli tytu³ zaczyna siê od '"' tzn., ¿e posiada w nazwie ',' i musi zostaæ specjalnie obs³u¿ony
				{
					if (Title.back() == '"')
					{
						break;
					}
					else
					{
						std::string NextTitlePart;

						std::getline(SingleLine, NextTitlePart, ',');
						Title += ',' + NextTitlePart; // Dodaje kolejne czêœci po przecinku do tytu³u
					}
					
				}
				std::getline(SingleLine, Rating);	// Pobiera rating
				if (!Rating.empty())				// Dodaj film tylko jeœli posiada rating
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
