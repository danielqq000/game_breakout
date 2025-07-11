/*
 * src/collision.hpp
 * Created: 6/15/25
 *
 * Collision Manager — handles Ball collisions with Paddle and Bricks
 */

#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "ball.hpp"
#include "paddle.hpp"
#include "brick.hpp"
#include <vector>

namespace CollisionManager {
    void handleBallPaddle(Ball& ball, const Paddle& paddle);
    bool handleBallBricks(Ball& ball, std::vector<Brick>& bricks);
}

#endif
