/*
 * src/ball.hpp
 * Last Update: 5/4/25
 *
 * Ball settings
 */

#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball {
public:
    // Constructor
    Ball(float radius = 10.0f);

    // set Functions
    void setPosition(const float&, const float&);
    void setSpeedX(const float&);
    void setSpeedY(const float&);

    // get Functions
    sf::Vector2f getPosition() const;
    float getSpeedX() const;
    float getSpeedY() const;
    float getRadius() const;
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
    const float minSpeedX = 1.5f, minSpeedY = 1.5f;
    const float init_speedX = 0, init_speedY = 2.0f;
    const float init_posX = 640, init_posY = 500;
};

#endif
