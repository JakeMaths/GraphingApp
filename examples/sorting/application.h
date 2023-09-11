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

class Application {
private:
    // Variables
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    int sortArrayLength;
    std::vector<int> sortArray;
    std::vector<int> sortBarColors;
    float timeDelta;

    float sortBarWidth;

    // Objects
    sf::RectangleShape sortBar;
    std::vector<sf::RectangleShape> sortBars;

    // Private functions
    void initializeVariables();
    void initializeWindow();
    void initializeSortBars();

    void shuffleSortArray();
    void clearSortBarColors();
    void bubbleSortStep();
    void insertionSortStep();
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
