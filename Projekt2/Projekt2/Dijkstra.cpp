#include "Dijkstra.h"

#include <limits>
#include <queue>
#include <iostream>

#define INF numeric_limits<uint32_t>::max()

Edge::Edge(const uint32_t TargetVertex, const uint32_t Weight)
{
	this->TargetVertex = TargetVertex;
	this->Weight = Weight;
}

Dijkstra::Dijkstra(const vector<vector<uint32_t>>& Graph, const uint32_t StartingVertex)
{
	Vertices = static_cast<uint32_t>(Graph.size());

    vector<uint32_t> DistanceToTheVertex(Vertices, INF);
    vector<bool> bHasTheVertexBeenVisited(Vertices, false);

    priority_queue<pair<uint32_t, uint32_t>, vector<pair<uint32_t, uint32_t>>, greater<pair<uint32_t, uint32_t>>> VertexQueue;

    DistanceToTheVertex[StartingVertex] = 0;
    VertexQueue.push({ 0, StartingVertex });

    while (!VertexQueue.empty()) 
    {
        uint32_t CurrentVertex = VertexQueue.top().second;
        VertexQueue.pop();

        if (bHasTheVertexBeenVisited[CurrentVertex]) 
        {
            continue;
        }

        bHasTheVertexBeenVisited[CurrentVertex] = true;

        for (uint32_t NextVertex = 0; NextVertex < Vertices; NextVertex++)
        {
            if (Graph[CurrentVertex][NextVertex] != 0 && !bHasTheVertexBeenVisited[NextVertex])
            {
                uint32_t DistanceToNextVertex = DistanceToTheVertex[CurrentVertex] + Graph[CurrentVertex][NextVertex];
                if (DistanceToNextVertex < DistanceToTheVertex[NextVertex])
                {
                    DistanceToTheVertex[NextVertex] = DistanceToNextVertex;
                    VertexQueue.push({ DistanceToTheVertex[NextVertex], NextVertex });
                }
            }
        }
    }

    /*cout << "Najkr�tsze odleg�o�ci od wierzcho�ka " << StartingVertex << ":" << endl;
    for (int i = 0; i < Vertices; ++i) {
        cout << "Wierzcho�ek " << i << ": ";
        if (DistanceToTheVertex[i] == INF)
            cout << "Brak po��czenia" << endl;
        else
            cout << DistanceToTheVertex[i] << endl;
    }*/
}

Dijkstra::Dijkstra(const vector<vector<Edge>>& Graph, const uint32_t StartingVertex)
{
    Vertices = static_cast<uint32_t>(Graph.size());

    vector<uint32_t> DistanceToTheVertex(Vertices, INF);
    vector<bool> bHasTheVertexBeenVisited(Vertices, false);

    priority_queue<pair<uint32_t, uint32_t>, vector<pair<uint32_t, uint32_t>>, greater<pair<uint32_t, uint32_t>>> VertexQueue;

    DistanceToTheVertex[StartingVertex] = 0;
    VertexQueue.push({ 0, StartingVertex });

    while (!VertexQueue.empty())
    {
        uint32_t CurrentVertex = VertexQueue.top().second;
        VertexQueue.pop();

        if (bHasTheVertexBeenVisited[CurrentVertex])
        {
            continue;
        }

        bHasTheVertexBeenVisited[CurrentVertex] = true;

        for (const Edge& Edge : Graph[CurrentVertex])
        {
            uint32_t NextVertex = Edge.GetTargetVertex();
            uint32_t Weight = Edge.GetWeight();

            if (!bHasTheVertexBeenVisited[NextVertex])
            {
                uint32_t DistanceToNextVertex = DistanceToTheVertex[CurrentVertex] + Weight;
                if (DistanceToNextVertex < DistanceToTheVertex[NextVertex])
                {
                    DistanceToTheVertex[NextVertex] = DistanceToNextVertex;
                    VertexQueue.push({ DistanceToTheVertex[NextVertex], NextVertex });
                }
            }
        }
    }

    /*cout << "Odleg�o�ci od wierzcho�ka " << StartingVertex << " do pozosta�ych wierzcho�k�w:" << endl;
    for (uint32_t i = 0; i < Vertices; i++) 
    {
        cout << "Wierzcho�ek " << i << ": ";
        if (DistanceToTheVertex[i] != INF)
        {
            cout << DistanceToTheVertex[i] << endl;
        }
        else
        {
            cout << "Brak po��czenia" << endl;
        }
    }*/
}