/*
 * main.cpp
 * Made by : danielqq000
 * Last Update: 6/7/25
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
#include "src/UI/UIManager.hpp"

enum class GameState {
    Playing,
    Paused
};


int main() {
    // build a 800x600 window
    sf::RenderWindow window(sf::VideoMode(1280,1060), "Breakout!");

    Paddle paddle;
    Ball ball(10);


    // UI
    sf::Font font;
    if(!font.loadFromFile("../assets/Jersey25-Regular.ttf")) {
        std::cerr << "Failed to load\n";
    }
    
    UIManager uiManager(font);


    // Brick setup
    std::vector<Brick> bricks;
    const int brickRows = 4;
    const int brickCols = 10;
    const float brickWidth = 100;
    const float brickHeight = 30;
    const float brickSpacing = 5;

    for (int row = 0; row < brickRows; ++row) {
        for (int col = 0; col < brickCols; ++col) {
            bricks.emplace_back(
                col * (brickWidth + brickSpacing) + 60,
                row * (brickHeight + brickSpacing) + 60
            );
        }
    }

    GameState gameState = GameState::Playing;
    // Game Main Loop
    while(window.isOpen()) {

        // Event Control
        sf::Event event;
        while(window.pollEvent(event)) {
            // Press Esc to terminate
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
            
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
                if(gameState == GameState::Playing) {
                    gameState = GameState::Paused;
                    uiManager.setGameState(GameStatus::Paused);
                }
                else {
                    gameState = GameState::Playing;
                    uiManager.setGameState(GameStatus::None);
                }
            }

        }

        // game pasued
        if(gameState == GameState::Paused)
            goto display;

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
            uiManager.increaseScore(100);

        // ball fall below the screen, for now reset the whole game
        if (ball.getPosition().y > window.getSize().y) {
            sf::sleep(sf::seconds(0.5f));
            ball.reset();
            uiManager.resetScore();
            paddle.setPosition(575, 1000); // see paddle def for more
            paddle.draw(window);
            ball.draw(window);
            sf::sleep(sf::seconds(1.5f));
        }

        // Window Rendering
display:
        window.clear(sf::Color::Black);
        paddle.draw(window);
        ball.draw(window);
        for (auto& brick : bricks)
            brick.draw(window);

        uiManager.draw(window);
        if(gameState == GameState::Paused) {
            uiManager.drawStateText(window);
        }

        window.display();
    }

    return 0;
}
