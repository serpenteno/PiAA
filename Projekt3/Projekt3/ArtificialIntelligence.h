#pragma once
#include <cstdint>

class UBoard;

class UArtificialIntelligence
{
public:
	UArtificialIntelligence(uint32_t Depth);

	void AIMove(UBoard* Board);

	int32_t MiniMax(UBoard* Board, uint32_t Depth, bool bIsMaximizingOutcome, int32_t Alpha, int32_t Beta);

	uint32_t GetBestRow() const { return BestRow; }

	uint32_t GetBestColumn() const { return BestColumn; }

private:
	uint32_t BestRow;

	uint32_t BestColumn;

	uint32_t Depth;
};
