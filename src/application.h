#pragma once

#include "header.h"
#include "graph.h"

const float WINDOW_WIDTH = 1920;
const float WINDOW_HEIGHT = 1080;

const float DEFAULT_X_MIN = -2;
const float DEFAULT_X_MAX = 2;
const float DEFAULT_Y_MIN = -2;
const float DEFAULT_Y_MAX = 2;

const float DEFAULT_W_MIN = 560;
const float DEFAULT_W_MAX = 1360;
const float DEFAULT_H_MIN = 140;
const float DEFAULT_H_MAX = 940;

/// Manages the application window.
///
/// .
class Application {
private:
    // Variables
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;
    Graph* graph;

    // Private Member Functions
    //! Initialzie member variables
    void initializeVariables();
    //! Initialize window member variable
    void initializeWindow();
public:
    // Constructors / Destructors
    //! Default Constructor
    Application();
    //! Destructor
    virtual ~Application();
    // Accessors
    //! Get whether window is open
    const bool windowIsOpen() const;
    // Functions
    //! Poll for events
    void pollEvents();
    //! Update application objects
    void update();
    //! Draw renderable objects to the window and display
    void render();
};
