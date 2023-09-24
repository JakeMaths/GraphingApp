#pragma once

#include "header.h"
#include "graph.h"
#include "gui.h"

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
    Gui* gui;

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
