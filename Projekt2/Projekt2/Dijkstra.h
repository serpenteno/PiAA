#pragma once

#include <vector>

using namespace std;

/** 
 * Klasa reprezentuj�ca kraw�d� grafu. 
 *
 * Klasa opisuje jedn� z kraw�dzi wierzcho�ka prowadz�c� do kolejnego wierzcho�ka wraz z kosztem przej�cia.
 */
class Edge
{
public:
	/**
	 * Konstruktor klasy Edge.
	 * 
	 * @param TargetVertex Wierzcho�ek, do kt�rego prowadzi kraw�d�.
	 * @param Weight Koszt przej�cia przez kraw�d�.
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
 * Klasa reprezentuj�ca algorytmu Dijkstry.
 * 
 * Klasa szukaj�ca najkr�tszej �cie�ki do ka�dego wierzcho�ka w grafie przy pomocy algorytmu Dijkstry.
 */
class Dijkstra
{
public:
	/** 
	 * Konstruktor klasy Dijkstra.
	 * 
	 * Reprezentacja grafu w postaci macierzy s�siedzwta.
	 * 
	 * @param Graph Graf w postaci macierzy s�siedztwa.
	 * @param StartingVertex Wierzcho�ek, dla kt�rego wyznaczane s� najkr�tsze �cie�ki do wszystkich pozosta�ych wierzcho�k�w.
	 */
	Dijkstra(const vector<vector<uint32_t>>& Graph, const uint32_t StartingVertex);

	/**
	 * Konstruktor klasy Dijkstra.
	 *
	 * Reprezentacja grafu w postaci listy s�siedztwa.
	 *
	 * @param Graph Graf w postaci listy s�siedztwa.
	 * @param StartingVertex Wierzcho�ek, dla kt�rego wyznaczane s� najkr�tsze �cie�ki do wszystkich pozosta�ych wierzcho�k�w.
	 */
	Dijkstra(const vector<vector<Edge>>& Graph, const uint32_t StartingVertex);

private:
	uint32_t Vertices;
};

