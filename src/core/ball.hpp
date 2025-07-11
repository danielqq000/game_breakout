/*
 * src/ball.hpp
 * Last Update: 6/15/25
 *
 * Ball settings
 */

#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball {
public:
    // === Constructor ===
    Ball(float radius = 10.0f);

    // === Getters & Setters ===
    sf::Vector2f getPosition() const;
    void setPosition(float, float);

    float getSpeedX() const;
    void setSpeedX(float);

    float getSpeedY() const;
    void setSpeedY(float);

    float getRadius() const;
    void setRadius(float);

    sf::FloatRect getBounds() const;

    // Functions
    void move();
    void draw(sf::RenderWindow&) const;
    void checkCollision(const sf::RenderWindow&);
    void checkSpeed();
    void reset();

private:
    sf::CircleShape shape;
    sf::Color color;
    float speedX, speedY;
    const float minSpeedX = 0, minSpeedY = 1.5f;
    const float init_speedX = 0, init_speedY = 2.0f;
    const float init_posX = 640, init_posY = 500;
};

#endif
