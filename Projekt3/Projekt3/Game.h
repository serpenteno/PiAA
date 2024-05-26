#pragma once
#include <SFML/Graphics.hpp>

const uint32_t WindowResolution = 1024;

class UBoard;
class UArtificialIntelligence;

class Game
{
public:
	Game(UBoard* Board, UArtificialIntelligence* AI);

	void Run();

private:
	void Render();

	void HandleEvents();

	UBoard* GameBoard;
	UArtificialIntelligence* GameAI;

	sf::RenderWindow* Window;
};

