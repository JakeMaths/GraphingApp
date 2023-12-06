#pragma once

#include "header.h"
#include "keystates.h"
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
    KeyStates keyStates;
    Graph* graph;
    Gui* gui;

    //! Boolean to stop mouse scroll if not scrolled
    bool mouseScrollThisFrame;
    //! Mode for text input (graph (0) or gui (1))
    int inputMode;
    //! Time since last graph draw
    sf::Time lastDraw;
    //! Clock for keeping time
    sf::Clock clock;

    // Private Member Functions
    //! Initialzie member variables
    void initializeVariables();
    //! Initialize window member variable
    void initializeWindow();
    //! Reset keystates to default (off)
    void resetKeyStates();
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
