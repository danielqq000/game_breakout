/*
 * src/UI/score.hpp
 * Last Update: 6/15/25
 *
 * score settings
 */

#ifndef SCORE_HPP
#define SCORE_HPP

#include <SFML/Graphics.hpp>

class Score {
public:
    // Constructor
    Score(const sf::Font& font);

    // Get functions
    const int getScore() const;

    // functions
    void addScore(const int amount);
    void draw(sf::RenderWindow& window) const;
    void reset();

private:
    int score = 0;
    sf::Text scoreText;
    void updateText();
};

#endif
