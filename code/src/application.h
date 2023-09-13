#pragma once

/*
    Manages the application window
*/

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

const float WINDOW_WIDTH = 1920;
const float WINDOW_HEIGHT = 1080;

const float X_MIN = -5;
const float X_MAX = 5;
const float Y_MIN = -1;
const float Y_MAX = 9;

const float W_MIN = 560;
const float W_MAX = 1360;
const float H_MIN = 140;
const float H_MAX = 940;

const float TILE_WIDTH = 1;
const float TILE_HEIGHT = 1;

class Application {
private:
    // Variables
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    sf::RectangleShape gridTile;
    std::vector<sf::RectangleShape> gridVector;
    int gridRows;
    int gridCols;

    // Private functions
    void initializeVariables();
    void initializeWindow();

    sf::Vector2f gridToScreen(sf::Vector2u pos);
    sf::Vector2f screenToEuclidean(sf::Vector2f pos);
    sf::Vector2f euclideanToScreen(sf::Vector2f pos);
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
