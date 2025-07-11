/*
 * src/paddle.cpp
 * Update: 6/15/25
 *
 * Paddle implementation
 */

#include "paddle.hpp"

Paddle::Paddle()
    : shape(sf::Vector2f(150, 25)), speed(2.5f), color(sf::Color::White) {
        shape.setFillColor(color);
        reset();
}

sf::Vector2f Paddle::getPosition() const { return shape.getPosition(); }
void Paddle::setPosition(float x, float y) { shape.setPosition(x,y); }

sf::Vector2f Paddle::getSize() const { return shape.getSize(); }
void Paddle::setSize(float l, float w) { shape.setSize(sf::Vector2f(l,w)); }

float Paddle::getSpeed() const { return speed; }
void Paddle::setSpeed(float v) { speed = v; }

sf::FloatRect Paddle::getBounds() const { return shape.getGlobalBounds(); }

void Paddle::moveLeft() { shape.move(-speed, 0); }

void Paddle::moveRight() { shape.move(speed, 0); }

void Paddle::draw(sf::RenderWindow& window) const { window.draw(shape); }

void Paddle::reset() { shape.setPosition(init_posX, init_posY); }
