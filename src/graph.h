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
    //! Lines used to draw graph of a function
    std::vector<sf::VertexArray> graphLines;
    //! Background rectangle
    sf::RectangleShape background;
    //! Text for drawing on graph
    sf::Text text;
    //! Collect of texts to be drawn
    std::vector<sf::Text> textVector;
    //! Font for drawing text
    sf::Font font;

    //! Temp variable for declaring graph type
    int graphMode;

    // Private Member Functions
    //! Convert grid (i,j) coordinates to screen (w,h) coordinates
    sf::Vector2f gridToScreen(sf::Vector2u grid_pos);
    //! Convert screen (w,h) coordinates to graph (x,y) coordinates
    sf::Vector2f screenToGraph(sf::Vector2f screen_pos);
    //! Convert graph (x,y) coordinates to screen (w,h) coordinates
    sf::Vector2f graphToScreen(sf::Vector2f graph_pos);
    //! Create lines for a function
    std::vector<sf::VertexArray> functionLines();
    //! Create verticies for a function
    sf::VertexArray functionVertices();
public:
    //! Default Constructor
    Graph(sf::Vector2f xRange, sf::Vector2f yRange, sf::Vector2f wRange, sf::Vector2f hRange);
    //! Set graphMode
    void setGraphMode(int i);
    //! Update gridVector based on graphMode
    void updateGraph(const KeyStates &keyStates);
    //! Draw gridVector to a window
    void drawToWindow(sf::RenderWindow* window);
    //! Decrement xMin and xMax by xDec
    void decXRange(float xDec);
    //! Decrement yMin and yMax by yDec
    void decYRange(float yDec);
    //! Increment xMin and xMax by xInc
    void incXRange(float xInc);
    //! Increment yMin and yMax by yInc
    void incYRange(float yInc);
};
