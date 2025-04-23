/*
 * src/brick.cpp
 * Last Update: 4/14/25
 *
 * Brick settings
 */

#include "brick.hpp"

Brick::Brick(float x, float y, float width, float height) {
    shape.setSize({width, height});
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(x, y);
}

void Brick::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

bool Brick::checkCollision(sf::CircleShape& ball, float& ballSpeedY) {
    if (ball.getGlobalBounds().intersects(shape.getGlobalBounds())) {
        ballSpeedY = -ballSpeedY;
        return true;
    }

    return false;
}

sf::FloatRect Brick::getBounds() const {
    return shape.getGlobalBounds();
}
