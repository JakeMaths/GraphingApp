#include "gui.h"

Gui::Gui() {
    ibwMin = 100;
    ibwMax = 500;
    ibhMin = 100;
    ibhMax = 980;
    inputBackground.setSize(sf::Vector2f(ibwMax-ibwMin, ibhMax-ibhMin));
    inputBackground.setPosition(sf::Vector2f(ibwMin, ibhMin));
    inputBackground.setFillColor(sf::Color::White);
}

void Gui::updateGui() {
    return;
}

void Gui::drawToWindow(sf::RenderWindow* window) {
    window->draw(inputBackground);
    return;
}