#pragma once

#include <vector>

using namespace std;

/** 
 * Klasa reprezentuj¹ca krawêdŸ grafu. 
 *
 * Klasa opisuje jedn¹ z krawêdzi wierzcho³ka prowadz¹c¹ do kolejnego wierzcho³ka wraz z kosztem przejœcia.
 */
class Edge
{
public:
	/**
	 * Konstruktor klasy Edge.
	 * 
	 * @param TargetVertex Wierzcho³ek, do którego prowadzi krawêdŸ.
	 * @param Weight Koszt przejœcia przez krawêdŸ.
	 */
	Edge(const uint32_t TargetVertex, const uint32_t Weight);

	uint32_t GetTargetVertex() const				{ return TargetVertex; }
	void SetTargetVertex(uint32_t NewTargetVertex)	{ TargetVertex = NewTargetVertex; }

	uint32_t GetWeight() const					{ return Weight; }
	void SetTargetWeight(uint32_t NewWeight)	{ Weight = NewWeight; }

private:
	uint32_t TargetVertex;
	uint32_t Weight;
};

/** 
 * Klasa reprezentuj¹ca algorytmu Dijkstry.
 * 
 * Klasa szukaj¹ca najkrótszej œcie¿ki do ka¿dego wierzcho³ka w grafie przy pomocy algorytmu Dijkstry.
 */
class Dijkstra
{
public:
	/** 
	 * Konstruktor klasy Dijkstra.
	 * 
	 * Reprezentacja grafu w postaci macierzy s¹siedzwta.
	 * 
	 * @param Graph Graf w postaci macierzy s¹siedztwa.
	 * @param StartingVertex Wierzcho³ek, dla którego wyznaczane s¹ najkrótsze œcie¿ki do wszystkich pozosta³ych wierzcho³ków.
	 */
	Dijkstra(const vector<vector<uint32_t>>& Graph, const uint32_t StartingVertex);

	/**
	 * Konstruktor klasy Dijkstra.
	 *
	 * Reprezentacja grafu w postaci listy s¹siedztwa.
	 *
	 * @param Graph Graf w postaci listy s¹siedztwa.
	 * @param StartingVertex Wierzcho³ek, dla którego wyznaczane s¹ najkrótsze œcie¿ki do wszystkich pozosta³ych wierzcho³ków.
	 */
	Dijkstra(const vector<vector<Edge>>& Graph, const uint32_t StartingVertex);

private:
	uint32_t Vertices;
};

