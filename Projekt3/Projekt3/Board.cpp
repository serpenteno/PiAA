#include "Board.h"

UBoard::UBoard(uint32_t Size, uint32_t WinCondition, char PlayerSymbol)
{
	this->Size = Size;
	this->WinCondition = WinCondition;
	switch (PlayerSymbol)
	{
	case 'x':
		this->PlayerSymbol = ESymbol::Cross;
		this->AISymbol = ESymbol::Circle;
		this->Turn = ETurn::Player;
		break;

	case 'o':
		this->PlayerSymbol = ESymbol::Circle;
		this->AISymbol = ESymbol::Cross;
		this->Turn = ETurn::AI;
		break;

	default:
		break;
	}
	this->GameState = EGameState::Ongoing;
	this->Boxes = std::vector<std::vector<ESymbol>>(Size, std::vector<ESymbol>(Size, ESymbol::None));
}

void UBoard::PlaceSymbol(uint32_t Row, uint32_t Column, ESymbol Symbol)
{
	Boxes[Row][Column] = Symbol;
}

void UBoard::EraseSymbol(uint32_t Row, uint32_t Column)
{
	Boxes[Row][Column] = ESymbol::None;
}

void UBoard::ResetBoard()
{
	for (uint32_t Row = 0; Row < Size; Row++)
	{
		for (uint32_t Column = 0; Column < Size; Column++)
		{
			Boxes[Row][Column] = ESymbol::None;
		}
	}
}

ESymbol UBoard::CheckSymbol(uint32_t Row, uint32_t Column) const
{
	return Boxes[Row][Column];
}

bool UBoard::IsBoxOccupied(uint32_t Row, uint32_t Column) const
{
	return (CheckSymbol(Row, Column) == ESymbol::None) ? false : true;
}

bool UBoard::IsBoardFull() const
{
	for (uint32_t Row = 0; Row < Size; Row++)
	{
		for (uint32_t Column = 0; Column < Size; Column++)
		{
			if (!IsBoxOccupied(Row, Column))
			{
				return false;
			}
		}
	}
	return true;
}

void UBoard::SwitchTurn()
{
	switch (Turn)
	{
	case ETurn::Player:
		Turn = ETurn::AI;
		break;

	case ETurn::AI:
		Turn = ETurn::Player;
		break;
	}
}

EGameState UBoard::CheckGameState()
{
	uint32_t PlayerSymbolsChain = 0;
	uint32_t AISymbolsChain = 0;

	// Sprawdzenie rzêdów
	for (uint32_t Row = 0; Row < Size; Row++)
	{
		PlayerSymbolsChain = 0;
		AISymbolsChain = 0;

		for (uint32_t Column = 0; Column < Size; Column++)
		{
			if (CheckSymbol(Row, Column) == PlayerSymbol)
			{
				PlayerSymbolsChain++;
				AISymbolsChain = 0;
			}

			if (CheckSymbol(Row, Column) == AISymbol)
			{
				AISymbolsChain++;
				PlayerSymbolsChain = 0;
			}

			if (CheckSymbol(Row, Column) == ESymbol::None)
			{
				PlayerSymbolsChain = 0;
				AISymbolsChain = 0;
			}

			if (PlayerSymbolsChain >= WinCondition)
			{
				return EGameState::PlayerWins;
			}

			if (AISymbolsChain >= WinCondition)
			{
				return EGameState::AIWins;
			}
		}
	}

	// Sprawdzenie kolumn
	for (uint32_t Column = 0; Column < Size; Column++)
	{
		PlayerSymbolsChain = 0;
		AISymbolsChain = 0;

		for (uint32_t Row = 0; Row < Size; Row++)
		{
			if (CheckSymbol(Row, Column) == PlayerSymbol)
			{
				PlayerSymbolsChain++;
				AISymbolsChain = 0;
			}

			if (CheckSymbol(Row, Column) == AISymbol)
			{
				AISymbolsChain++;
				PlayerSymbolsChain = 0;
			}

			if (CheckSymbol(Row, Column) == ESymbol::None)
			{
				PlayerSymbolsChain = 0;
				AISymbolsChain = 0;
			}

			if (PlayerSymbolsChain >= WinCondition)
			{
				return EGameState::PlayerWins;
			}

			if (AISymbolsChain >= WinCondition)
			{
				return EGameState::AIWins;
			}
		}
	}

	// Sprawdzenie przek¹tnych
	for (uint32_t Row = 0; Row <= Size - WinCondition; Row++)
	{
		for (uint32_t Column = 0; Column <= Size - WinCondition; Column++)	
		{
			PlayerSymbolsChain = 0;
			AISymbolsChain = 0;

			for (uint32_t Chain = 0; Chain < WinCondition; Chain++)
			{
				if (CheckSymbol(Row + Chain, Column + Chain) == PlayerSymbol)
				{
					PlayerSymbolsChain++;
					AISymbolsChain = 0;
				}

				if (CheckSymbol(Row + Chain, Column + Chain) == AISymbol)
				{
					AISymbolsChain++;
					PlayerSymbolsChain = 0;
				}

				if (CheckSymbol(Row + Chain, Column + Chain) == ESymbol::None)
				{
					PlayerSymbolsChain = 0;
					AISymbolsChain = 0;
				}

				if (PlayerSymbolsChain == WinCondition)
				{
					return EGameState::PlayerWins;
				}

				if (PlayerSymbolsChain == WinCondition)
				{
					return EGameState::AIWins;
				}
			}
		}
	}

	for (uint32_t Row = Size - 1; Row >= WinCondition; Row--)
	{
		for (uint32_t Column = 0; Column <= Size - WinCondition; Column++)
		{
			PlayerSymbolsChain = 0;
			AISymbolsChain = 0;

			for (uint32_t Chain = 0; Chain < WinCondition; Chain++)
			{
				if (CheckSymbol(Row - Chain, Column + Chain) == PlayerSymbol)
				{
					PlayerSymbolsChain++;
					AISymbolsChain = 0;
				}

				if (CheckSymbol(Row - Chain, Column + Chain) == AISymbol)
				{
					AISymbolsChain++;
					PlayerSymbolsChain = 0;
				}

				if (CheckSymbol(Row - Chain, Column + Chain) == ESymbol::None)
				{
					PlayerSymbolsChain = 0;
					AISymbolsChain = 0;
				}

				if (PlayerSymbolsChain >= WinCondition)
				{
					return EGameState::PlayerWins;
				}

				if (PlayerSymbolsChain >= WinCondition)
				{
					return EGameState::AIWins;
				}
			}
		}
	}

	if (IsBoardFull())
	{
		return EGameState::Draw;
	}

	return EGameState::Ongoing;
}
