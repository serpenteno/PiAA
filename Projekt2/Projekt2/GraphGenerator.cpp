#include "GraphGenerator.h"
#include "Dijkstra.h"

#include <random>

static uint32_t GenerateRandomNumber()
{
    random_device RandomDevice;
    mt19937 Generator(RandomDevice());
    uniform_int_distribution<uint32_t> Distribution(MinGeneratedNumber, MaxGeneratedNumber);

    return Distribution(Generator);
}

vector<vector<uint32_t>> GenerateRandomGraph_AdjacencyMatrix(uint32_t Vertices, double Density)
{
    vector<vector<uint32_t>> Graph(Vertices, vector<uint32_t>(Vertices, 0));
    for (uint32_t i = 0; i < Vertices; i++)
    {
        for (uint32_t j = i + 1; j < Vertices; j++)
        {
            if (GenerateRandomNumber() <= Density * MaxGeneratedNumber)
            {
                Graph[i][j] = GenerateRandomNumber();
                Graph[j][i] = Graph[i][j];
            }
        }
    }

    return Graph;
}

vector<vector<Edge>> GenerateRandomGraph_AdjacencyList(uint32_t Vertices, double Density)
{
    vector<vector<Edge>> Graph(Vertices);

    for (uint32_t i = 0; i < Vertices; i++)
    {
        for (uint32_t j = i + 1; j < Vertices; j++)
        {
            if (GenerateRandomNumber() < Density * MaxGeneratedNumber) 
            {
                uint32_t Weight = GenerateRandomNumber(); // Losowa waga krawêdzi (od 1 do 10)
                Graph[i].push_back(Edge(j, Weight));
                Graph[j].push_back(Edge(i, Weight)); // Graf nieskierowany
            }
        }
    }

    return Graph;
}
