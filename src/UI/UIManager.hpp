/*
 * src/UI/UIManager.hpp
 * Last Update: 6/7/25
 *
 * UI Manager Settings
 */

#ifndef UI_MANAGER_HPP
#define UI_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include "score.hpp"
#include "GameStateText.hpp"

class UIManager {
public:
    UIManager(sf::Font& font);

    void increaseScore(int amount);
    void resetScore();
    void draw(sf::RenderWindow& window);
    void drawStateText(sf::RenderWindow& window);

    void setGameState(GameStatus status);
    GameStatus getGameState() const;

private:
    Score score;
    GameStateText gameStateText;
};

#endif
