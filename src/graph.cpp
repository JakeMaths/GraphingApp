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

sf::VertexArray Graph::functionVertices()
{
    sf::VertexArray vertices;
    for (int i=0; i<gridRows; i++)
    {
        for (int j=0; j<gridCols; j++)
        {
            sf::Vector2f screenC = gridToScreen(sf::Vector2u(i, j));
            sf::Vector2f graphC = screenToGraph(screenC);
            float x = graphC.x;
            float y = graphC.y;
            float fx = 0;
            // determine the function 
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
            // graph vertices 
            if (std::abs(y-fx) < DEFAULT_ZERO_THRESH)
            {
                sf::Vertex vertex;
                vertex.position = screenC;
                vertex.color = sf::Color::Red;
                vertices.append(vertex);
            }
        }
    }
    return vertices;
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
    gridRows = hMax-hMin;
    gridCols = wMax-wMin;
    axisTickLength = DEFAULT_AXIS_TICK_LENGTH;
    graphMode = 1;

    background.setSize(sf::Vector2f(wMax-wMin, hMax-hMin));
    background.setPosition(sf::Vector2f(wMin, hMin));
    background.setFillColor(sf::Color::White);

    font.loadFromFile("res/arial.ttf");
    text.setFont(font);
    // pixels, not points
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
}

void Graph::setGraphMode(int i)
{
    graphMode = i;
    return;
}

void Graph::updateGraph(const KeyStates &keyStates)
{
    if (keyStates.keyUp || keyStates.keyW)
        incYRange(0.1);
    if (keyStates.keyDown || keyStates.keyS)
        decYRange(0.1);
    if (keyStates.keyRight || keyStates.keyD)
        incXRange(0.1);
    if (keyStates.keyLeft || keyStates.keyA)
        decXRange(0.1);
    if (keyStates.key1)
        setGraphMode(1);
    if (keyStates.key2)
        setGraphMode(2);
    if (keyStates.key3)
        setGraphMode(3);
    if (keyStates.key4)
        setGraphMode(4);
    if (keyStates.key5)
        setGraphMode(5);
    if (keyStates.key6)
        setGraphMode(6);
    if (keyStates.key7)
        setGraphMode(7);
    if (keyStates.keyEqual)
    {
        xMax /= 2;
        xMin /= 2;
        yMax /= 2;
        yMin /= 2;
    }
    if (keyStates.keyHyphen)
    {
        xMax *= 2;
        xMin *= 2;
        yMax *= 2;
        yMin *= 2;
    }

    gridVector.clear();
    textVector.clear();
    
    sf::VertexArray graphVertices = functionVertices();
    for (int i=0; i<graphVertices.getVertexCount(); i++)
    {
        gridVector.append(graphVertices[i]);
    }    

    // draw x axis
    if (yMax > 0 && yMin < 0)
    {
        float screenY = graphToScreen(sf::Vector2f(xMin, 0)).y;
        for (int i=0; i<gridCols; i++)
        {
            sf::Vertex vertex;
            float screenX = gridToScreen(sf::Vector2u(i, 0)).x;
            vertex.position = sf::Vector2f(screenX, screenY);
            vertex.color = sf::Color::Black;
            gridVector.append(vertex);
        }
    }

    // draw x axis tick marks and numbers numbers
    for (int i=static_cast<int>(ceil(xMin)); i<static_cast<int>(ceil(xMax)); i++)
    {
        sf::Vector2f tick_position = graphToScreen(sf::Vector2f(i,0));
        sf::Vertex vertex;
        for (int j=-axisTickLength; j<=axisTickLength; j++)
        {
            vertex.position = sf::Vector2f(tick_position.x, tick_position.y + j);
            vertex.color = sf::Color::Black;
            gridVector.append(vertex);

        }
        text.setString(std::to_string(i));
        text.setPosition(tick_position);
        textVector.push_back(text);
    } 

    // draw y axis
    if (xMax > 0 && xMin < 0)
    {
        float screenX = graphToScreen(sf::Vector2f(0, yMin)).x;
        for (int i=0; i<gridRows; i++)
        {
            sf::Vertex vertex;
            float screenY = gridToScreen(sf::Vector2u(0, i)).y;
            vertex.position = sf::Vector2f(screenX, screenY);
            vertex.color = sf::Color::Black;
            gridVector.append(vertex);
        }
    }

    // draw y axis tick numbers
    for (int i=static_cast<int>(ceil(yMin)); i<static_cast<int>(ceil(yMax)); i++)
    {
        sf::Vector2f tick_position = graphToScreen(sf::Vector2f(0,i));
        sf::Vertex vertex;
        for (int j=-axisTickLength; j<=axisTickLength; j++)
        {
            vertex.position = sf::Vector2f(tick_position.x + j, tick_position.y);
            vertex.color = sf::Color::Black;
            gridVector.append(vertex);

        }
        text.setString(std::to_string(i));
        text.setPosition(tick_position);
        textVector.push_back(text);
    } 

    return;
}

void Graph::drawToWindow(sf::RenderWindow* window)
{
    window->draw(background);

    /*
    for (auto r : gridVector)
    {
        window->draw(r);
    }
    */
   window->draw(gridVector);

    for (auto t: textVector)
    {
        window->draw(t);
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
