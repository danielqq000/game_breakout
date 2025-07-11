/*
 * UI/FPSCounter.hpp
 * Last Update: 6/15/25
 *
 * FPS Counter settings
 */

#ifndef FPSCOUNTER_HPP
#define FPSCOUNTER_HPP

#include <SFML/Graphics.hpp>
#include <string>

class FPSCounter {
public:
    FPSCounter(const sf::Font&);

    void update(float, const sf::RenderWindow&);
    void draw(sf::RenderWindow&);

private:
    sf::Text fpsText;
    float timeAccumulator = 0.0f;
    int frameCount = 0;
    int fps = 0;
};

#endif
