/*
 * src/paddle.cpp
 * Update: 5/4/25
 *
 * Paddle implementation
 */

#include "paddle.hpp"

Paddle::Paddle()
    : shape(sf::Vector2f(150, 25)), speed(2.5f), color(sf::Color::White) {
        shape.setFillColor(color);
        reset();
}

void Paddle::setPosition(const float& x, const float& y) {
    shape.setPosition(x,y);
}

void Paddle::setSpeed(const float& v) {
    speed = v;
}

sf::Vector2f Paddle::getPosition() const {
    return shape.getPosition();
}

sf::Vector2f Paddle::getSize() const {
    return shape.getSize();
}

float Paddle::getSpeed() const {
    return speed;
}

sf::FloatRect Paddle::getBounds() const {
    return shape.getGlobalBounds();
}

void Paddle::moveLeft() {
    shape.move(-speed, 0);
}

void Paddle::moveRight() {
    shape.move(speed, 0);
}

void Paddle::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

void Paddle::reset() {
    shape.setPosition(init_posX, init_posY);
}
