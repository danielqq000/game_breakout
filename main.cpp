/*
 * main.cpp
 * Made by : danielqq000
 * Last Update: 4/14/25
 *
 * Main entrance of this application.
 */

#include <SFML/Graphics.hpp>
#include <vector>
#include "src/brick.hpp"

int main() {
    // build a 800x600 window
    sf::RenderWindow window(sf::VideoMode(1280,1060), "Breakout!");

    // Paddle Settings
    sf::RectangleShape paddle(sf::Vector2f(150, 25));
    paddle.setFillColor(sf::Color::White);
    paddle.setPosition(600, 1000); // starting position at bottom-middle
    float paddleSpeed = 2.0f; // initial moving speed

    // Ball Settings
    sf::CircleShape ball(10); // radius
    ball.setFillColor(sf::Color::Red);
    ball.setPosition(640,500); // starting postion
    float ballSpeedX = 1.0f, ballSpeedY = 1.5f; // initial speed
    
    // Brick Settings
    std::vector<Brick> bricks;
    const int brickRows = 4;
    const int brickCols = 10;
    const float brickWidth = 100;
    const float brickHeight = 30;
    const float brickSpacing = 5;

    for(int row = 0; row < brickRows; ++row) {
        for(int col = 0; col < brickCols; ++col) {
            bricks.emplace_back(
                    col * (brickWidth + brickSpacing) + 60,
                    row * (brickHeight + brickSpacing) + 60
                    );
        }
    }

    // Game Main Loop
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            // Press Esc to terminate
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

        // Paddle Control
        // controling paddle with left/right key.
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if(paddle.getPosition().x > 0)
                paddle.move(-paddleSpeed, 0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if(paddle.getPosition().x + paddle.getSize().x < window.getSize().x)
                paddle.move(paddleSpeed, 0);
        }

        // Ball Movement
        ball.move(ballSpeedX, ballSpeedY);
        
        // Ball collision
        if (ball.getPosition().x <= 0 || ball.getPosition().x + ball.getRadius() * 2 >= window.getSize().x)
            ballSpeedX = -ballSpeedX;
        if (ball.getPosition().y <= 0)
            ballSpeedY = -ballSpeedY;
        if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds())) {
            ballSpeedY += 0.05;
            ballSpeedY = -ballSpeedY;
        }

        // ball fall below the screen, for now reset the whole game
        if (ball.getPosition().y > window.getSize().y) {
            sf::sleep(sf::seconds(0.5f));
            ball.setPosition(640, 500);
            paddle.setPosition(600, 1000);
            sf::sleep(sf::seconds(1.5f));
        }

        // check ball collision with bricks
        for (auto it = bricks.begin(); it != bricks.end(); ) {
            if (it->checkCollision(ball, ballSpeedY)) {
                it = bricks.erase(it);
            } else {
                ++it;
            }
        }

        // Window Rendering
        window.clear(sf::Color::Black);
        window.draw(paddle);
        window.draw(ball);
        for (auto& brick : bricks)
            brick.draw(window);

        window.display();
    }

    return 0;
}
