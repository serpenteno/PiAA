#include <iostream>

#include "Board.h"
#include "ArtificialIntelligence.h"
#include "Game.h"

int main()
{
    setlocale(LC_ALL, "pl_PL");

    uint32_t Size, WinCondition, Depth;
    char PlayerSymbol;

    do
    {
        std::cout << "Podaj rozmiar planszy\n";
        std::cin >> Size;
    } while (Size < 0 || Size > UINT32_MAX);

    do
    {
        std::cout << "Podaj liczbê symboli potrzebnych do wygrania\n";
        std::cin >> WinCondition;
    } while (WinCondition < 0 || WinCondition > Size);

    do
    {
        std::cout << "Podaj g³êbokoœæ liczenia wariantów/rekurencji\n";
        std::cin >> Depth;
    } while (WinCondition < 0 || WinCondition > Size);

    do
    {
        std::cout << "Wybierz symbol (x/o) (x - zaczyna)\n";
        std::cin >> PlayerSymbol;
    } while (PlayerSymbol != 'x' && PlayerSymbol != 'o');

    UBoard Board(Size, WinCondition, PlayerSymbol);
    UArtificialIntelligence AI(Depth);

    UGame* NewGame = new UGame(&Board, &AI);
    NewGame->Run();

    return 0;
}