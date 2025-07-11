/*
 * src/Ball.cpp
 * Last Update: 6/15/25
 *
 * Ball implementation
 */

#include "ball.hpp"

Ball::Ball(float radius)
    : shape(radius), color(sf::Color::Red) {
    shape.setFillColor(color);
    shape.setOrigin(radius, radius);
    reset();
}

sf::Vector2f Ball::getPosition() const { return shape.getPosition(); }
void Ball::setPosition(float x, float y) { shape.setPosition(x, y); }

float Ball::getSpeedX() const { return speedX; }
void Ball::setSpeedX(float sx) { speedX = sx; }

float Ball::getSpeedY() const { return speedY; }
void Ball::setSpeedY(float sy) { speedY = sy; }

float Ball::getRadius() const { return shape.getRadius(); }
void Ball::setRadius(float r) { shape.setRadius(r); }

sf::FloatRect Ball::getBounds() const { return shape.getGlobalBounds(); }

void Ball::move() {
    checkSpeed();
    shape.move(speedX, speedY);
}

void Ball::draw(sf::RenderWindow& window) const { window.draw(shape); }

// Ball collision with the wall
void Ball::checkCollision(const sf::RenderWindow& window) {
    float left = shape.getPosition().x - shape.getRadius();
    float right = shape.getPosition().x + shape.getRadius();
    float top = shape.getPosition().y - shape.getRadius();

    if (left <= 0 || right >= window.getSize().x)
        speedX *= -1;

    if (top <= 0)
        speedY *= -1;
}

void Ball::checkSpeed() {
    if (std::abs(speedX) < minSpeedX) {
        speedX = (speedX > 0) ? minSpeedX : -minSpeedX;
    }
    if (std::abs(speedY) < minSpeedY) {
        speedY = (speedY > 0) ? minSpeedY : -minSpeedY;
    }
}

void Ball::reset() {
    shape.setPosition(init_posX, init_posY);
    speedX = init_speedX;
    speedY = init_speedY;
}
