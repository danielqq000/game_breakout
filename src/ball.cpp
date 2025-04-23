#include "ball.hpp"

// Constructor
Ball::Ball(float radius)
    : shape(radius), speed(2.0f), velocity(1.0f, -1.5f) {
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(radius, radius);
    initialPostion = {640, 500};
    shape.setPosition(initialPostion);
}

void Ball::update() {
    shape.move(velocity);

    // wall collision
    
}
