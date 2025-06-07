/*
 * src/UI/score.cpp
 * Last Update: 6/7/25
 *
 * score and UI implementation
 */

#include "score.hpp"
#include <string>

Score::Score(sf::Font& font) {
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);
    updateText();
}

const int Score::getScore() const {
    return score;
}

void Score::addScore(const int amount) {
    score += amount;
    updateText();
}

void Score::draw(sf::RenderWindow& window) const {
    window.draw(scoreText);
}

void Score::reset() {
    score = 0;
    updateText();
}

void Score::updateText() {
    scoreText.setString("Score: " + std::to_string(score));
}
