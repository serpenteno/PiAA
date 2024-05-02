#pragma once

#include <limits>
#include <stdint.h>
#include <vector>

using namespace std;

const uint32_t MinGeneratedNumber = 1;
const uint32_t MaxGeneratedNumber = 10;

class Edge;

/**
 * Generuje losowe liczby ca�kowite z zakresu [FirstGeneratedNumber, LastGeneratedNumber].
 * 
 * @return Losowa liczba ca�kowita z zakresu [FirstGeneratedNumber, LastGeneratedNumber].
 */
uint32_t GenerateRandomNumber();

/**
 * Generuje losowy graf o okre�lonej g�sto�ci reprezentowany w postaci macierzy s�siedztwa.
 * 
 * @param Verticies Liczba wierzcho�k�w generowanego grafu.
 * @param Density G�sto�� generowanego grafu.
 * @return Graf reprezentowany w postaci macierzy s�siedztwa.
 */
vector<vector<uint32_t>> GenerateRandomGraph_AdjacencyMatrix(uint32_t Vertices, double Density);

/**
 * Generuje losowy graf o okre�lonej g�sto�ci reprezentowany w postaci listy s�siedztwa.
 * 
 * @param Verticies Liczba wierzcho�k�w generowanego grafu.
 * @param Density G�sto�� generowanego grafu.
 * @return Graf reprezentowany w postaci listy s�siedztwa.
 */
vector<vector<Edge>> GenerateRandomGraph_AdjacencyList(uint32_t Vertices, double Density);
