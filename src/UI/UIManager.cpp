/*
 * src/UI/UIManager.cpp
 * Last Update: 6/7/25
 *
 * UI Manager implementation
 */

#include "UIManager.hpp"

UIManager::UIManager(sf::Font& font)
    : score(font), gameStateText(font) {}

void UIManager::increaseScore(int amount) {
    score.addScore(amount);
}

void UIManager::resetScore() {
    score.reset();
}

void UIManager::draw(sf::RenderWindow& window) {
    score.draw(window);
}

void UIManager::drawStateText(sf::RenderWindow& window) {
    gameStateText.draw(window);
}

void UIManager::setGameState(GameStatus status) {
    gameStateText.setStatus(status);
}

GameStatus UIManager::getGameState() const {
    return gameStateText.getStatus();
}

