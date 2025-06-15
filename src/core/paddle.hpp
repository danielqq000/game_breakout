/*
 * src/paddle.hpp
 * Update: 5/4/25
 *
 * Paddle settings
 */

#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

class Paddle {
public:
    // Constructor
    Paddle();

    // set Functions
    void setPosition(const float&, const float&);
    void setSpeed(const float&);

    // get Functions
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    float getSpeed() const;
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
    const float init_posX = 545, init_posY = 1000; //slightly to right, perfect should be 565 on 1280 size
};

#endif
