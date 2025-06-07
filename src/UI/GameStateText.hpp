/*
 * src/UI/GameStateText.hpp
 * Last Update: 6/7/25
 *
 * Game States and UI settings
 */

#ifndef GAME_STATE_TEXT_HPP
#define GAME_STATE_TEXT_HPP

#include <SFML/Graphics.hpp>

enum class GameStatus {
    None,
    Paused,
    GameOver,
};

class GameStateText {
public:
    GameStateText(sf::Font& font);

    void setStatus(GameStatus status);
    GameStatus getStatus() const;

    void draw(sf::RenderWindow& window) const;

private:
    sf::Text text;
    GameStatus currentStatus;
};

#endif
