/*
 * main.cpp
 * Made by : danielqq000
 * Last Update: 5/4/25
 *
 * Main entrance of this application.
 */

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "src/brick.hpp"
#include "src/ball.hpp"
#include "src/paddle.hpp"
#include "src/collision.hpp"

int main() {
    // build a 800x600 window
    sf::RenderWindow window(sf::VideoMode(1280,1060), "Breakout!");

    Paddle paddle;
    Ball ball(10);

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

    // UI
    int score = 0;
    sf::Font font;
    if(!font.loadFromFile("../assets/Jersey25-Regular.ttf")) {
        std::cerr << "Failed to load\n";
    }

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10.f, 10.f);

    // Game Main Loop
    while(window.isOpen()) {

        // Event Control
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
                paddle.moveLeft();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if(paddle.getPosition().x + paddle.getSize().x < window.getSize().x)
                paddle.moveRight();
        }

        // Ball Movement
        ball.move();
        ball.checkCollision(window);

        // Handle Collisions
        CollisionManager::handleBallPaddle(ball, paddle);
        if(CollisionManager::handleBallBricks(ball, bricks))
            score += 100;

        // ball fall below the screen, for now reset the whole game
        if (ball.getPosition().y > window.getSize().y) {
            sf::sleep(sf::seconds(0.5f));
            ball.reset();
            paddle.setPosition(575, 1000); // see paddle def for more
            paddle.draw(window);
            ball.draw(window);
            sf::sleep(sf::seconds(1.5f));
        }

        // Window Rendering
        window.clear(sf::Color::Black);
        paddle.draw(window);
        ball.draw(window);
        for (auto& brick : bricks)
            brick.draw(window);
        scoreText.setString("Score: " + std::to_string(score));
        window.draw(scoreText);

        window.display();
    }

    return 0;
}
