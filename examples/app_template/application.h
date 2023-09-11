#pragma once

/*
    Manages the application window
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Application {
private:
    // Variables
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    // Private functions
    void initializeVariables();
    void initializeWindow();
public:
    // Constructors / Destructors
    Application();
    virtual ~Application();

    // Accessors
    const bool windowIsOpen() const;

    // Functions
    void pollEvents();
    void update();
    void render();
};
