/*
 * UI/FPSCounter.cpp
 * Last Update: 6/15/25
 *
 * FPS Counter Implementation
 */

#include "FPSCounter.hpp"
#include <sstream>

FPSCounter::FPSCounter(const sf::Font& font) {
    fpsText.setFont(font);
    fpsText.setCharacterSize(20);
    fpsText.setFillColor(sf::Color::White);
    fpsText.setPosition(10.f, 10.f);
}

void FPSCounter::update(float deltaTime, const sf::RenderWindow& window) {
    timeAccumulator += deltaTime;
    frameCount++;

    if (timeAccumulator >= 1.0f) {
        fps = frameCount;
        frameCount = 0;
        timeAccumulator -= 1.0f;

        std::ostringstream ss;
        ss << "FPS: " << fps;
        fpsText.setString(ss.str());

        float xPos = window.getSize().x - fpsText.getLocalBounds().width - 10.f;
        float yPos = 10.f;
        fpsText.setPosition(xPos, yPos);
    }
}

void FPSCounter::draw(sf::RenderWindow& window) {
    window.draw(fpsText);
}
