#pragma once
#include <cstdint>
#include <vector>

enum ETurn
{
	Player,
	AI
};

enum ESymbol
{
	None,
	Cross,
	Circle
};

enum EGameState
{
	Ongoing,
	PlayerWins,
	AIWins,
	Draw
};

class UBoard
{
public:
	UBoard() {};

	UBoard(uint32_t Size, uint32_t WinCondition, char PlayerSymbol);

	void PlaceSymbol(uint32_t Row, uint32_t Column, ESymbol Symbol);

	void EraseSymbol(uint32_t Row, uint32_t Column);

	void ResetBoard();

	ESymbol CheckSymbol(uint32_t Row, uint32_t Column) const;

	bool IsBoxOccupied(uint32_t Row, uint32_t Column) const;

	bool IsBoardFull() const;

	void SwitchTurn();

	EGameState CheckGameState();

	size_t GetSize() const { return Size; }

	uint32_t GetWinCondition() const { return WinCondition; }

	ETurn GetTurn() const { return Turn; }

	ESymbol GetPlayerSymbol() const { return PlayerSymbol; }

	ESymbol GetAISymbol() const{ return AISymbol; }

private:
	uint32_t Size;

	uint32_t WinCondition;

	ETurn Turn;

	ESymbol PlayerSymbol;

	ESymbol AISymbol;

	EGameState GameState;

	std::vector<std::vector<ESymbol>> Boxes;
};

