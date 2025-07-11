/*
 * src/collision.cpp
 * Created: 6/15/25
 *
 * Collision logic implementation
 */

#include "collision.hpp"
#include <cmath>

namespace CollisionManager {

    // Ball and Paddle Collision
    void handleBallPaddle(Ball& ball, const Paddle& paddle) {
        const sf::FloatRect& ballBounds = ball.getBounds();
        const sf::FloatRect& paddleBounds = paddle.getBounds();

        if (ballBounds.intersects(paddleBounds)) {
            const float paddleCenterX = paddle.getPosition().x + paddle.getSize().x / 2;
            const float ballX = ball.getPosition().x;

            // Speed offset based on position of collision
            const float offset = ballX - paddleCenterX;
            const float normalizedOffset = offset / (paddle.getSize().x / 2.0f);
            const float baseSpeed = std::sqrt(ball.getSpeedX() * ball.getSpeedX() + ball.getSpeedY() * ball.getSpeedY());

            // Add paddle movement influence
            const float paddleInfluence = 0.2f;
            const float combinedSpeedX = normalizedOffset * baseSpeed + paddle.getSpeed() * paddleInfluence;

            ball.setSpeedX(combinedSpeedX);
            ball.setSpeedY(-std::abs(ball.getSpeedY()));

            // Clamp min speed
            if (std::abs(ball.getSpeedX()) < 1.5f)
                ball.setSpeedX((ball.getSpeedX() > 0 ? 1 : -1) * 1.5f);
        }
    }

    // Ball and Bricks Collision
    bool handleBallBricks(Ball& ball, std::vector<Brick>& bricks) {
        const sf::FloatRect ballBounds = ball.getBounds();
        auto it = bricks.begin();
        while (it != bricks.end()) {
            if (it->checkCollision(ballBounds)) {
                // check direction of collision
                const float ballX = ballBounds.left + ballBounds.width / 2;
                const float ballY = ballBounds.top + ballBounds.height / 2;
                const sf::FloatRect brickBounds = it->getBounds();

                if(ballX <= brickBounds.left || ballX >= brickBounds.left + brickBounds.width)
                    ball.setSpeedX(-ball.getSpeedX());
                if(ballY <= brickBounds.top || ballY >= brickBounds.top + brickBounds.height)
                    ball.setSpeedY(-ball.getSpeedY());

                it = bricks.erase(it);
                return true;
            } else {
                ++it;
            }
        }

        return false;
    }
}

