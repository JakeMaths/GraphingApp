#pragma once

#include "header.h"
#include "keystates.h"
#include "test_funcs.h"
#include "parser.h"

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

    ////! Vector: each element is a vector of lines to be drawn
    //std::vector<std::vector<sf::VertexArray>> graphsToDraw;

    //! Vector: each element is vertex to be drawn
    std::vector<sf::VertexArray> graphsToDraw;

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
    //! Vector of String representations of functions to be graphed
    std::vector<std::string> functionStrings;
    //! String representation of basis vector 1
    std::string vectorString1;
    //! String representation of basis vector 2
    std::string vectorString2;

    // Private Member Functions

    // Conversions
    //! Convert grid (i,j) coordinates to screen (w,h) coordinates
    sf::Vector2f gridToScreen(sf::Vector2u grid_pos);
    //! Convert screen (w,h) coordinates to graph (x,y) coordinates
    sf::Vector2f screenToGraph(sf::Vector2f screen_pos);
    //! Convert graph (x,y) coordinates to screen (w,h) coordinates
    sf::Vector2f graphToScreen(sf::Vector2f graph_pos);

    // Graphics Generation
    //! Create points for a function
    sf::VertexArray functionPoints(std::string funcString, int color);
    //! Create lines for a function
    std::vector<sf::VertexArray> functionLines(std::string funcString, int color);

    // Transformations
    //! Transform xMax, xMin, yMax, yMin to zoom in
    void zoomIn();
    //! Transform xMax, xMin, yMax, yMin to zoom out
    void zoomOut();
    //! Transform xMax, xMin to move along x axis
    void moveX(float x);
    //! Transform yMax, yMin to move along y axis
    void moveY(float y);
    //! Reset position to default
    void resetGraph();
public:
    //! Default Constructor
    Graph(sf::Vector2f xRange, sf::Vector2f yRange, sf::Vector2f wRange, sf::Vector2f hRange);
    //! Update gridVector based on graphMode
    void updateGraph(KeyStates &keyStates, int &inputMode);
    //! Draw gridVector to a window
    void drawToWindow(sf::RenderWindow* window);
    //! Set function string
    void setFunctionStrings(std::vector<std::string> funcStrings);
    //! Updates graphsToDraw
    void generateGraphs();
    //! Set vector strings
    void setVectorString(int i, std::string vectorString);
};
