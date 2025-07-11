/*
 * src/brick.cpp
 * Last Update: 6/15/25
 *
 * Brick implementation
 */

#include "brick.hpp"

Brick::Brick(float x, float y, float width, float height) {
    shape.setSize({width, height});
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(x, y);
}

void Brick::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

bool Brick::checkCollision(const sf::FloatRect& ballBounds) const {
    if (ballBounds.intersects(shape.getGlobalBounds())) {
        return true;
    }

    return false;
}

sf::FloatRect Brick::getBounds() const {
    return shape.getGlobalBounds();
}
