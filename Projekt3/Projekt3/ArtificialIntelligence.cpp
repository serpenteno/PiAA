#include "ArtificialIntelligence.h"
#include "Board.h"

UArtificialIntelligence::UArtificialIntelligence(uint32_t Depth)
{
	this->Depth = Depth;
	this->BestRow = -1;
	this->BestColumn = -1;
}

void UArtificialIntelligence::AIMove(UBoard* Board)
{
	int32_t CurrentOutcome = INT32_MAX;
	int32_t BestOutcome = INT32_MAX;

	for (uint32_t Row = 0; Row < Board->GetSize(); Row++)
	{
		for (uint32_t Column = 0; Column < Board->GetSize(); Column++)
		{
			if (!Board->IsBoxOccupied(Row, Column))
			{
				Board->PlaceSymbol(Row, Column, Board->GetAISymbol());
				CurrentOutcome = MiniMax(Board, Depth, true, INT32_MIN, INT32_MAX);
				Board->EraseSymbol(Row, Column);
				if (CurrentOutcome < BestOutcome)
				{
					BestRow = Row;
					BestColumn = Column;
					BestOutcome = CurrentOutcome;
				}
			}
		}
	}
}

int32_t UArtificialIntelligence::MiniMax(UBoard* Board, uint32_t Depth, bool bIsMaximizingOutcome, int32_t Alpha, int32_t Beta)
{
	EGameState CurrentGameState = Board->CheckGameState();
	if (CurrentGameState == EGameState::PlayerWins || CurrentGameState == EGameState::AIWins || Board->IsBoardFull() || Depth == 0)
	{
		switch (CurrentGameState)
		{
		case EGameState::PlayerWins:
			return 1;

		case EGameState::AIWins:
			return -1;

		case EGameState::Ongoing:
			return 0;

		case EGameState::Draw:
			return 0;
		}
	}

	if (bIsMaximizingOutcome)
	{
		int32_t Max = INT32_MIN;

		for (uint32_t Row = 0; Row < Board->GetSize(); Row++)
		{
			for (uint32_t Column = 0; Column < Board->GetSize(); Column++)
			{
				if (!Board->IsBoxOccupied(Row, Column))
				{
					Board->PlaceSymbol(Row, Column, Board->GetPlayerSymbol());
					Max = std::max(Max, MiniMax(Board, Depth - 1, false, Alpha, Beta));
					Board->EraseSymbol(Row, Column);
					Alpha = std::max(Alpha, Max);
					
					if (Alpha >= Beta)
					{
						return Alpha;
					}
				}
			}
		}
		return Max;
	}
	else
	{
		int32_t Min = INT32_MAX;

		for (uint32_t Row = 0; Row < Board->GetSize(); Row++)
		{
			for (uint32_t Column = 0; Column < Board->GetSize(); Column++)
			{
				if (!Board->IsBoxOccupied(Row, Column))
				{
					Board->PlaceSymbol(Row, Column, Board->GetAISymbol());
					Min = std::min(Min, MiniMax(Board, Depth - 1, true, Alpha, Beta));
					Board->EraseSymbol(Row, Column);
					Beta = std::min(Beta, Min);

					if (Beta <= Alpha)
					{
						return Beta;
					}
				}
			}
		}
		return Min;
	}
}
