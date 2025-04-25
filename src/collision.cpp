/*
 * src/collision.cpp
 * Created: 4/25/25
 *
 * Collision logic implementation
 */

#include "collision.hpp"
#include <cmath>

namespace CollisionManager {
    void handleBallPaddle(Ball& ball, Paddle& paddle) {
        sf::FloatRect ballBounds = ball.getBallBounds();
        sf::FloatRect paddleBounds(paddle.getPosition(), paddle.getSize());

        if (ballBounds.intersects(paddleBounds)) {
            float paddleCenterX = paddle.getPosition().x + paddle.getSize().x / 2;
            float ballX = ball.getPosition().x;

            float offset = ballX - paddleCenterX;
            float normalizedOffset = offset / (paddle.getSize().x / 2.0f);

            float baseSpeed = std::sqrt(ball.getSpeedX() * ball.getSpeedX() + ball.getSpeedY() * ball.getSpeedY());

            ball.setSpeedX(normalizedOffset * baseSpeed);
            ball.setSpeedY(-std::abs(ball.getSpeedY()));
        }
    }

    void handleBallBricks(Ball& ball, std::vector<Brick>& bricks) {
        auto it = bricks.begin();
        while (it != bricks.end()) {
            if (it->checkCollision(ball.getBallBounds())) {
                ball.setSpeedY(-ball.getSpeedY());
                it = bricks.erase(it);
            } else {
                ++it;
            }
        }
    }
}

