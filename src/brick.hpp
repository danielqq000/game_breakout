/*
 * src/brick.hpp
 * Last Update: 4/25/25
 *
 * Brick settings
 */

#ifndef BRICK_HPP
#define BRICK_HPP

#include <SFML/Graphics.hpp>

class Brick {
public:
    Brick(float x, float y, float width = 100, float height = 30);

    void draw(sf::RenderWindow&) const;
    bool checkCollision(const sf::FloatRect);
    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape shape;
};

#endif
