#pragma once

#include "header.h"
#include "keystates.h"
#include "test_funcs.h"

/// Manages the graph area on screen.
///
/// .
class Graph
{
private:
    // Variables
    //! Minimum x value (graph)
    float xMin;
    //! Maximum x value (graph)
    float xMax;
    //! Minimum y value (graph)
    float yMin;
    //! Maximum y value (graph)
    float yMax;
    //! Minimum x value (screen)
    float wMin;
    //! Maximum x value (screen)
    float wMax;
    //! Minimum y value (screen)
    float hMin;
    //! Maximum y value (screen)
    float hMax;
    //! Rows in rectangle grid
    int gridRows;
    //! Columns in rectangle grid
    int gridCols;
    //! Axis tick marker length in pixels
    int axisTickLength;
    //! Collection of points to be drawn (axes, tick marks)
    sf::VertexArray gridVector;
    //! Vector: each element is a vector of lines to be drawn
    std::vector<std::vector<sf::VertexArray>> graphsToDraw;
    //! Background rectangle
    sf::RectangleShape background;
    //! Text for drawing on graph
    sf::Text text;
    //! Collect of texts to be drawn
    std::vector<sf::Text> textVector;
    //! Font for drawing text
    sf::Font font;
    //! Display debug information
    bool showDebug;

    //! Temp variable for declaring graph type
    int graphMode;

    // Private Member Functions

    // Conversions
    //! Convert grid (i,j) coordinates to screen (w,h) coordinates
    sf::Vector2f gridToScreen(sf::Vector2u grid_pos);
    //! Convert screen (w,h) coordinates to graph (x,y) coordinates
    sf::Vector2f screenToGraph(sf::Vector2f screen_pos);
    //! Convert graph (x,y) coordinates to screen (w,h) coordinates
    sf::Vector2f graphToScreen(sf::Vector2f graph_pos);

    // Graphics Generation
    //! Create lines for a function
    std::vector<sf::VertexArray> functionLines();

    // Transformations
    //! Transform xMax, xMin, yMax, yMin to zoom in
    void zoomIn();
    //! Transform xMax, xMin, yMax, yMin to zoom out
    void zoomOut();
    //! Transform xMax, xMin to move along x axis
    void moveX(float x);
    //! Transform yMax, yMin to move along y axis
    void moveY(float y);
public:
    //! Default Constructor
    Graph(sf::Vector2f xRange, sf::Vector2f yRange, sf::Vector2f wRange, sf::Vector2f hRange);
    //! Set graphMode
    void setGraphMode(int i);
    //! Update gridVector based on graphMode
    void updateGraph(const KeyStates &keyStates);
    //! Draw gridVector to a window
    void drawToWindow(sf::RenderWindow* window);
};
