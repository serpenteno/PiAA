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

    chrono::high_resolution_clock::time_point OperationStart;
    chrono::high_resolution_clock::time_point OperationEnd;

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
            cout << "Podaj gêstoœæ grafu:\n1. 25%\n2. 50%\n3. 75%\n4. Graf pe³ny\n";
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
            cout << "Podaj typ reprezentcji grafu:\nM. Macierz s¹siedztwa\nL. Lista s¹siedztwa\n";
            cin >> RepresentationType_Opt;
        } while (RepresentationType_Opt != 'M' && RepresentationType_Opt != 'L');

        char Simulate;
        bool bSimulateDijkstra;
        do
        {
            cout << "Przeprowadziæ symulacjê? [y/n]: ";
            cin >> Simulate;
        } while (Simulate != 'y' && Simulate != 'n');

        switch (Simulate)
        {
        case 'y':
            bSimulateDijkstra = true;
            break;

        case 'n':
            bSimulateDijkstra = false;
            break;
        }

        double SummedTime = 0.0;
        switch (RepresentationType_Opt)
        {
            case 'M':
            {
                vector<vector<vector<uint32_t>>> Graphs(Repetition);
                cout << "Generowanie " << Repetition << " grafów...\n";
                for (uint32_t i = 0; i < Repetition; i++)
                {
                    Graphs[i] = GenerateRandomGraph_AdjacencyMatrix(NumberOfVertices, GraphDensity);
                    cout << "Liczba wygenerowanych grafów: " << i + 1 << "\r";
                }
                cout << "\nGenerowanie grafów zakoñczone!" << endl;
                system("pause");

                system("cls");
                cout << "Wyszukiwanie najkrótszej drogi...\n";
                for (uint16_t i = 0; i < Repetition; i++)
                {
                    OperationStart = chrono::high_resolution_clock::now();
                    Dijkstra(Graphs[i], 0, bSimulateDijkstra);
                    OperationEnd = chrono::high_resolution_clock::now();
                    if (bSimulateDijkstra)
                    {
                        break;
                    }
                    SummedTime += chrono::duration_cast<chrono::microseconds>(OperationEnd - OperationStart).count();
                }
                break;
            }

            case 'L':
            {
                vector<vector<vector<Edge>>> Graphs(Repetition);
                cout << "Generowanie " << Repetition << " grafów...\n";
                for (uint32_t i = 0; i < Repetition; i++)
                {
                    Graphs[i] = GenerateRandomGraph_AdjacencyList(NumberOfVertices, GraphDensity);
                    cout << "Liczba wygenerowanych grafów: " << i + 1 << "\r";
                }
                cout << "\nGenerowanie grafów zakoñczone!" << endl;
                system("pause");

                system("cls");
                cout << "Wyszukiwanie najkrótszej drogi...\n";
                for (uint16_t i = 0; i < Repetition; i++)
                {
                    OperationStart = chrono::high_resolution_clock::now();
                    Dijkstra(Graphs[i], 0, bSimulateDijkstra);
                    OperationEnd = chrono::high_resolution_clock::now();
                    if (bSimulateDijkstra)
                    {
                        break;
                    }
                    SummedTime += chrono::duration_cast<chrono::microseconds>(OperationEnd - OperationStart).count();
                }
                break;
            }

            default:
                return 1;
        }
        if (!bSimulateDijkstra)
        {
            cout << "Liczba wierzcho³ków: " << NumberOfVertices << endl;
            cout << "Gêstoœæ grafu: " << GraphDensity << endl;
            cout << "Typ reprezentacji grafu: " << RepresentationType_Opt << endl;
            cout << "Ca³kowity czas wykonywania operacji: " << SummedTime / Repetition << " us" << endl;
            system("pause");
        }
    }

    return 0;
}
