#include <iostream>

#include "Game.h"
#include "Board.h"
#include "ArtificialIntelligence.h"

UGame::UGame(UBoard* Board, UArtificialIntelligence* AI)
{
	this->Window = new sf::RenderWindow(sf::VideoMode(WindowResolution, WindowResolution), "Tic Tac Toe");
	this->GameBoard = Board;
	this->GameAI = AI;
}

void UGame::Run()
{
	while (this->Window->isOpen())
	{
		Render();
		HandleEvents();
	}
}

void UGame::Render()
{
    Window->clear(sf::Color::White);

    const float CellWidth = Window->getSize().x / static_cast<float>(GameBoard->GetSize());
    const float CellHeight = Window->getSize().y / static_cast<float>(GameBoard->GetSize());

    for (uint32_t Row = 0; Row < GameBoard->GetSize(); Row++)
    {
        for (uint32_t Column = 0; Column < GameBoard->GetSize(); Column++)
        {
            sf::RectangleShape Cell(sf::Vector2f(CellWidth, CellHeight));
            Cell.setPosition(Column * CellWidth, Row * CellHeight);
            Cell.setOutlineThickness(1.0f);
            Cell.setOutlineColor(sf::Color::Black);
            Cell.setFillColor(sf::Color::White);
            Window->draw(Cell);

            sf::Shape* CellSymbol;

            if (GameBoard->CheckSymbol(Row, Column) == ESymbol::Cross)
            {
                CellSymbol = new sf::RectangleShape(sf::Vector2f(CellWidth / 2.0f, CellHeight / 20.0f));
                CellSymbol->setPosition(Column * CellWidth + CellWidth / 3.0f, Row * CellHeight + CellHeight / 3.0f);
                CellSymbol->setFillColor(sf::Color::Black);
                CellSymbol->rotate(45.0f);
                Window->draw(*CellSymbol);
                CellSymbol->setPosition(CellSymbol->getPosition().x - 10.0f, CellSymbol->getPosition().y + CellHeight / 2.825f);
                CellSymbol->rotate(-90.0f);
                Window->draw(*CellSymbol);
            }

            if (GameBoard->CheckSymbol(Row, Column) == ESymbol::Circle)
            {
                CellSymbol = new sf::CircleShape(CellHeight / 3.0f);
                CellSymbol->setPosition(Column * CellWidth - CellWidth / 3.0f, Row * CellHeight - CellHeight / 3.0f);
                CellSymbol->setFillColor(sf::Color::Black);
                CellSymbol->move(sf::Vector2f(CellWidth / 2.0f, CellHeight / 2.0f));
                Window->draw(*CellSymbol);
            }
        }
    }

    Window->display();
}

void UGame::HandleEvents()
{
    sf::Event Event;

    while (Window->pollEvent(Event))
    {
        if (Event.type == sf::Event::Closed || GameBoard->CheckGameState() != EGameState::Ongoing)
        {
            Window->close();
        }

        switch (GameBoard->GetTurn())
        {
        case ETurn::Player:
            if (Event.type == sf::Event::MouseButtonPressed)
            {
                if (Event.mouseButton.button == sf::Mouse::Left)
                {
                    const uint32_t ClickPositionX = Event.mouseButton.x;
                    const uint32_t ClickPositionY = Event.mouseButton.y;

                    const uint32_t ClickedRow = static_cast<uint32_t>(ClickPositionY / (Window->getSize().y / GameBoard->GetSize()));
                    const uint32_t ClickedColumn = static_cast<uint32_t>(ClickPositionX / (Window->getSize().x / GameBoard->GetSize()));

                    if (!GameBoard->IsBoxOccupied(ClickedRow, ClickedColumn))
                    {
                        GameBoard->PlaceSymbol(ClickedRow, ClickedColumn, GameBoard->GetPlayerSymbol());

                        switch (GameBoard->CheckGameState())
                        {
                        case EGameState::PlayerWins:
                            std::cout << "Player won!\n";
                            Window->close();
                            break;

                        case EGameState::Draw:
                            std::cout << "Draw\n";
                            Window->close();
                            break;
                        }
                        GameBoard->SwitchTurn();
                        break;
                    }
                }
            }
            break;

        case ETurn::AI:
            GameAI->AIMove(GameBoard);
            GameBoard->PlaceSymbol(GameAI->GetBestRow(), GameAI->GetBestColumn(), GameBoard->GetAISymbol());
            switch (GameBoard->CheckGameState())
            {
            case EGameState::AIWins:
                std::cout << "AI won!\n";
                Window->close();
                break;

            case EGameState::Draw:
                std::cout << "Draw\n";
                Window->close();
                break;
            }
            GameBoard->SwitchTurn();
            break;
        }

    }
}
