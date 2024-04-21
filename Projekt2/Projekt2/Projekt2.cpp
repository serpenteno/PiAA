#include <iostream>
#include <chrono>

#include "Dijkstra.h"
#include "GraphGenerator.h"

using namespace std;

int main() 
{
    setlocale(LC_ALL, "pl_PL");

    static char NumberOfVertices_Opt;
    static uint32_t NumberOfVertices;
    static uint16_t Repetition;
    static char GraphDencity_Opt;
    static double GraphDensity;
    static char RepresentationType_Opt;

    while (true)
    {
        do
        {
            system("cls");
            cout << "Podaj liczbê wierzcho³ków grafu:\n1. 10\n2. 50\n3. 100\n4. 500\n5. 1 000\n";
            cin >> NumberOfVertices_Opt;
        } while (NumberOfVertices_Opt != '1' && NumberOfVertices_Opt != '2' && NumberOfVertices_Opt != '3' && NumberOfVertices_Opt != '4' && NumberOfVertices_Opt != '5');

        switch (NumberOfVertices_Opt)
        {
        case '1':
            NumberOfVertices = 10;
            Repetition = 1000;
            break;

        case '2':
            NumberOfVertices = 50;
            Repetition = 1000;
            break;

        case '3':
            NumberOfVertices = 100;
            Repetition = 100;
            break;

        case '4':
            NumberOfVertices = 500;
            Repetition = 100;
            break;

        case '5':
            NumberOfVertices = 1000;
            Repetition = 100;
            break;

        default:
            return 1;
        }
        do
        {
            system("cls");
            cout << "Podaj gêstoœæ grafu:\n1. 25%\n2. 50%\n3. 75%\n4. 100%\n";
            cin >> GraphDencity_Opt;
        } while (GraphDencity_Opt != '1' && GraphDencity_Opt != '2' && GraphDencity_Opt != '3' && GraphDencity_Opt != '4');

        switch (GraphDencity_Opt)
        {
        case '1':
            GraphDensity = .25;
            break;

        case '2':
            GraphDensity = .5;
            break;

        case '3':
            GraphDensity = .75;
            break;

        case '4':
            GraphDensity = 1.0;
            break;

        default:
            return 1;
        }

        do
        {
            system("cls");
            cout << "Podaj typ reprezentcji grafu:\n1. Macierz s¹siedztwa\n2. Lista s¹siedztwa\n";
            cin >> RepresentationType_Opt;
        } while (RepresentationType_Opt != '1' && RepresentationType_Opt != '2');

        chrono::high_resolution_clock::time_point OperationStart;
        chrono::high_resolution_clock::time_point OperationEnd;
        chrono::microseconds TotalOperationTime;
        switch (RepresentationType_Opt)
        {
        case '1':
        {
            vector<vector<uint32_t>>Graph = GenerateRandomGraph_AdjacencyMatrix(NumberOfVertices, GraphDensity);
          
            OperationStart = chrono::high_resolution_clock::now();
            for (uint16_t i = 0; i < Repetition; i++)
            {
                Dijkstra(Graph, 0);
            }
            OperationEnd = chrono::high_resolution_clock::now();
            TotalOperationTime = chrono::duration_cast<chrono::microseconds>((OperationEnd - OperationStart));
            break;
        }

        case '2':
        {
            vector<vector<Edge>> Graph = GenerateRandomGraph_AdjacencyList(NumberOfVertices, GraphDensity);
            /*for (uint32_t i = 0; i < Graph.size(); i++)
            {
                cout << i << '\t';
                for (const Edge& Edge : Graph[i])
                {
                    cout << Edge.GetWeight() << " " << Edge.GetTargetVertex() << "\t";
                }
                cout << endl;
            }*/
            OperationStart = chrono::high_resolution_clock::now();
            for (uint16_t i = 0; i < Repetition; i++)
            {
                Dijkstra(Graph, 0);
            }
            OperationEnd = chrono::high_resolution_clock::now();
            TotalOperationTime = chrono::duration_cast<chrono::microseconds>((OperationEnd - OperationStart));
            break;
        }

        default:
            return 1;
        }

        cout << "Liczba wierzcho³ków: " << NumberOfVertices << endl;
        cout << "Gêstoœæ grafu: " << GraphDensity << endl;
        cout << "Typ reprezentacji grafu: " << RepresentationType_Opt << endl;
        cout << "Ca³kowity czas wykonywania operacji: " << TotalOperationTime.count() / Repetition << " us" << endl;
        system("pause");
    }

    return 0;
}
