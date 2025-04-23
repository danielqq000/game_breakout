/*
 * src/ball.hpp
 * Last Update: 4/20/25
 *
 * Ball settings
 */
#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(float radius = 10.0f);

    void update();
    void reset();
    void draw(sf::RenderWindow& window);
    void bounceX();
    void bounceY();
    void setInitialPostion(sf::Vector2f pos);
    sf::Vector2f getPostion() const;
    sf::FloatRect getBounds() const;
    sf::Vector2f getVelocity() const;
    void setVelocity(sf::Vector2f vel);

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    sf::Vector2f initialPosition;
    float speed;
};

#endif
