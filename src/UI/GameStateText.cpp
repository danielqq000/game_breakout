/*
 * src/UI/GameStateText.cpp
 * Last Update:6/15/25
 *
 * game state text and UI
 */

#include "GameStateText.hpp"

GameStateText::GameStateText(const sf::Font& font) : currentStatus(GameStatus::None) {
    text.setFont(font);
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    text.setPosition(540, 530);
}

void GameStateText::setStatus(GameStatus status) {
    currentStatus = status;

    switch (status) {
        case GameStatus::Paused:
            text.setString("PAUSED");
            break;
        case GameStatus::GameOver:
            text.setString("GAME OVER");
            break;
        case GameStatus::None:
        default:
            text.setString("");
            break;
    }
}

const GameStatus GameStateText::getStatus() const { return currentStatus; }

void GameStateText::draw(sf::RenderWindow& window) const {
    if (currentStatus != GameStatus::None)
        window.draw(text);
}
