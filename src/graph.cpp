#include "graph.h"

sf::Vector2f Graph::gridToScreen(sf::Vector2u grid_pos)
{
    sf::Vector2f screen_pos;
    screen_pos.x = wMin + grid_pos.x * (wMax-wMin) / gridCols;
    screen_pos.y = hMin + grid_pos.y * (hMax-hMin) / gridRows;
    return screen_pos;
}

sf::Vector2f Graph::screenToGraph(sf::Vector2f screen_pos)
{
    sf::Vector2f graph_pos;
    graph_pos.x = xMin + (screen_pos.x-wMin) * (xMax-xMin) / (wMax-wMin);
    graph_pos.y = yMax - (screen_pos.y-hMin) * (yMax-yMin) / (hMax-hMin);
    return graph_pos;
}

sf::Vector2f Graph::graphToScreen(sf::Vector2f graph_pos)
{
    sf::Vector2f screen_pos;
    screen_pos.x = wMin + (graph_pos.x-xMin) * (wMax-wMin) / (xMax-xMin);
    screen_pos.y = hMin + (yMax-graph_pos.y) * (hMax-hMin) / (yMax-yMin);
    return screen_pos;
}

Graph::Graph(sf::Vector2f xRange, sf::Vector2f yRange, sf::Vector2f wRange, sf::Vector2f hRange)
{
    xMin = xRange.x;
    xMax = xRange.y;
    yMin = yRange.x;
    yMax = yRange.y;
    wMin = wRange.x;
    wMax = wRange.y;
    hMin = hRange.x;
    hMax = hRange.y;
    gridRows = 1000;
    gridCols = 1000;
    graphMode = 1;
    gridTile.setSize(sf::Vector2f((wMax-wMin)/gridCols, (hMax-hMin)/gridRows));
    background.setSize(sf::Vector2f(wMax-wMin, hMax-hMin));
    background.setPosition(sf::Vector2f(wMin, hMin));
    background.setFillColor(sf::Color::White);
}

void Graph::setGraphMode(int i)
{
    graphMode = i;
    return;
}

void Graph::updateGraph()
{
    gridVector.clear();
    for (int i=0; i<gridRows; i++)
    {
        for (int j=0; j<gridCols; j++)
        {
            sf::Vector2f screenC = gridToScreen(sf::Vector2u(i, j));
            sf::Vector2f graphC = screenToGraph(screenC);
            float x = graphC.x;
            float y = graphC.y;
            float fx = 0;
            switch (graphMode)
            {
                case 1:
                    fx = funcA(x);
                    break;
                case 2:
                    fx = funcB(x);
                    break;
                case 3:
                    fx = funcC(x);
                    break;
                case 4:
                    fx = funcD(x);
                    break;
                case 5:
                    fx = funcE(x);
                    break;
                case 6:
                    fx = funcF(x);
                    break;
                case 7:
                    fx = funcG(x);
                    break;
            }
            if (std::abs(y-fx) < 0.01)
            {
                gridTile.setPosition(screenC);
                gridTile.setFillColor(sf::Color::Red);
                gridVector.push_back(gridTile);
            }
            else if (std::abs(y) < 0.01)
            {
                gridTile.setPosition(screenC);
                gridTile.setFillColor(sf::Color::Black);
                gridVector.push_back(gridTile);
            }
            else if (std::abs(x) < 0.01)
            {
                gridTile.setPosition(screenC);
                gridTile.setFillColor(sf::Color::Black);
                gridVector.push_back(gridTile);
            }
        }
    }
}

void Graph::drawToWindow(sf::RenderWindow* window)
{
    window->draw(background);
    for (auto r : gridVector)
    {
        window->draw(r);
    }
    return;
}

void Graph::decXRange(float xDec)
{
    xMin -= xDec;
    xMax -= xDec;
    return;
}

void Graph::decYRange(float yDec)
{
    yMin -= yDec;
    yMax -= yDec;
    return;
}

void Graph::incXRange(float xInc)
{
    xMin += xInc;
    xMax += xInc;
    return;
}

void Graph::incYRange(float yInc)
{
    yMin += yInc;
    yMax += yInc;
    return;
}
