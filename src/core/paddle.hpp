/*
 * src/paddle.hpp
 * Update: 6/15/25
 *
 * Paddle settings
 */

#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

class Paddle {
public:
    // === Constructor ===
    Paddle();

    // === Getters & Setters ===
    sf::Vector2f getPosition() const;
    void setPosition(float, float);

    sf::Vector2f getSize() const;
    void setSize(float, float);

    float getSpeed() const;
    void setSpeed(float);

    sf::FloatRect getBounds() const;

    // Functions
    void moveLeft();
    void moveRight();
    void draw(sf::RenderWindow&) const;
    void reset();


private:
    sf::RectangleShape shape;
    sf::Color color;
    float speed;

    //slightly to right, perfect should be 565 on 1280 size
    const float init_posX = 545, init_posY = 1000;
};

#endif
