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

std::vector<sf::VertexArray> Graph::functionLines()
{
    std::vector<sf::VertexArray> lines;
    for (int i=0; i<gridCols-1; i++)
    {
        sf::VertexArray buffer;
        buffer.setPrimitiveType(sf::Lines);

        sf::Vector2f screenC = gridToScreen(sf::Vector2u(i, 0));
        sf::Vector2f screenC2 = gridToScreen(sf::Vector2u(i+1, 0));
        sf::Vector2f graphC = screenToGraph(screenC);
        sf::Vector2f graphC2 = screenToGraph(screenC2);
        float x = graphC.x;
        float x2 = graphC2.x;
        float fx = 0;
        float fx2 = 0;
        // determine the function 

        try {
            Parser p1(functionString, x);
            Parser p2(functionString, x2);
            fx = p1.parse();
            fx2 = p2.parse();
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
            return lines;
        }
                
        if (std::abs(fx-fx2) < yMax - yMin)
        {
            if (fx <= yMax && fx >= yMin && fx2 <= yMax && fx2 >= yMin)
            {
                screenC = graphToScreen(sf::Vector2f(x, fx));
                screenC2 = graphToScreen(sf::Vector2f(x2, fx2));
                sf::Vertex vertex;
                vertex.color = sf::Color::Red;
                vertex.position = screenC;
                buffer.append(vertex);
                vertex.position = screenC2;
                buffer.append(vertex);
                lines.push_back(buffer);
            }
        }
    }
    return lines;
}

void Graph::zoomIn()
{
    if (std::min(xMax-xMin, yMax-yMin) > std::pow(10, -3)) 
    {
        float dx = (xMax-xMin)/10;
        float dy = (yMax-yMin)/10;
        xMax -= dx;
        xMin += dx;
        yMax -= dy;
        yMin += dy;
    }
    return;
}

void Graph::zoomOut()
{
    if (std::max(xMax-xMin, yMax-yMin) < std::pow(10, 8)) 
    {
        float dx = (xMax-xMin)/10;
        float dy = (yMax-yMin)/10;
        xMax += dx;
        xMin -= dx;
        yMax += dy;
        yMin -= dy;
    }
    return;
}

void Graph::moveX(float x)
{
    float dx = (xMax-xMin)/100;
    xMax += x*dx;
    xMin += x*dx;
    return;
}

void Graph::moveY(float y)
{
    float dy = (yMax-yMin)/100;
    yMax += y*dy;
    yMin += y*dy;
}

void Graph::resetGraph()
{
    xMin = DEFAULT_X_MIN;
    xMax = DEFAULT_X_MAX;
    yMin = DEFAULT_Y_MIN;
    yMax = DEFAULT_Y_MAX;
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

    gridVector.setPrimitiveType(sf::Points);

    background.setSize(sf::Vector2f(wMax-wMin, hMax-hMin));
    background.setPosition(sf::Vector2f(wMin, hMin));
    background.setFillColor(sf::Color(193, 154, 107, 255));

    font.loadFromFile("res/arial.ttf");
    text.setFont(font);
    // pixels, not points
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);

    showDebug = true;
}

void Graph::updateGraph(KeyStates &keyStates, int &inputMode)
{
    if (inputMode == 0) {
        if (keyStates.keyUp || keyStates.keyW)
            moveY(1);
        if (keyStates.keyDown || keyStates.keyS)
            moveY(-1);
        if (keyStates.keyRight || keyStates.keyD)
            moveX(1);
        if (keyStates.keyLeft || keyStates.keyA)
            moveX(-1);
        if (keyStates.keyG) {
            keyStates.keyG = 0;
            showDebug ^= 1;
        }
        if (keyStates.keyEqual)
            zoomIn();
        if (keyStates.keyHyphen)
            zoomOut();
        if (keyStates.mousescrolldelta > 0) {
            zoomIn();
        }
        if (keyStates.mousescrolldelta < 0) {
            zoomOut();
        }
        if (keyStates.keyR) {
            resetGraph();
        }
    }
    
    gridVector.clear();
    textVector.clear();
    graphsToDraw.clear();

    // add graphs to graphsToDraw
    graphsToDraw.push_back(functionLines());

    text.setFillColor(sf::Color::Black);

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

    // draw x axis tick marks and numbers
    {
        int precision = -1 * static_cast<int>(std::floor(std::log10(xMax-xMin)));
        float start = std::floor(std::pow(10,precision) * xMin) / std::pow(10,precision);
        float stop = std::ceil(std::pow(10,precision) * xMax) / std::pow(10,precision);
        float current = start;
        while (current <= stop)
        {
            sf::Vector2f tick_position = graphToScreen(sf::Vector2f(current,0));
            if (tick_position.x >= wMin && tick_position.x <= wMax
             && tick_position.y >= hMin && tick_position.y <= hMax)
            {
                sf::Vertex vertex;
                for (int j=-axisTickLength; j<=axisTickLength; j++)
                {
                    vertex.position = sf::Vector2f(tick_position.x, tick_position.y + j);
                    vertex.color = sf::Color::Black;
                    gridVector.append(vertex);

                }
                std::ostringstream oss;
                oss << std::setprecision(std::abs(precision)+3) << std::noshowpoint << current;
                text.setString(oss.str());
                text.setPosition(tick_position);
                textVector.push_back(text);
            }
            current += std::pow(10, -1 * precision) / 2;
        }
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

    // draw y axis tick marks and numbers
    {
        int precision = -1 * static_cast<int>(std::floor(std::log10(yMax-yMin)));
        float start = std::floor(std::pow(10,precision) * yMin) / std::pow(10,precision);
        float stop = std::ceil(std::pow(10,precision) * yMax) / std::pow(10,precision);
        float current = start;
        while (current <= stop)
        {
            sf::Vector2f tick_position = graphToScreen(sf::Vector2f(0,current));
            if (tick_position.x >= wMin && tick_position.x <= wMax
             && tick_position.y >= hMin && tick_position.y <= hMax)
            {
                sf::Vertex vertex;
                for (int j=-axisTickLength; j<=axisTickLength; j++)
                {
                    vertex.position = sf::Vector2f(tick_position.x + j, tick_position.y);
                    vertex.color = sf::Color::Black;
                    gridVector.append(vertex);

                }
                std::ostringstream oss;
                oss << std::noshowpoint << current;
                text.setString(oss.str());
                text.setPosition(tick_position);
                textVector.push_back(text);
            }
            current += std::pow(10, -1 * precision) / 2;
        }
    }

    // show debugging information
    if (showDebug)
    {
        text.setFillColor(sf::Color::Blue);
        text.setString("Debug Info");
        text.setPosition(sf::Vector2f(1600, 75));
        textVector.push_back(text);
        text.setFillColor(sf::Color::Green);
        text.setString("xMin: " + std::to_string(xMin));
        text.setPosition(sf::Vector2f(1600, 100));
        textVector.push_back(text);
        text.setString("xMax: " + std::to_string(xMax));
        text.setPosition(sf::Vector2f(1600, 125));
        textVector.push_back(text);
        text.setString("yMin: " + std::to_string(yMin));
        text.setPosition(sf::Vector2f(1600, 150));
        textVector.push_back(text);
        text.setString("yMax: " + std::to_string(yMax));
        text.setPosition(sf::Vector2f(1600, 175));
        textVector.push_back(text);  
        text.setString("xDelta: " + std::to_string(xMax-xMin));
        text.setPosition(sf::Vector2f(1600, 200));
        textVector.push_back(text); 
        text.setString("yDelta: " + std::to_string(yMax-yMin));
        text.setPosition(sf::Vector2f(1600, 225));
        textVector.push_back(text);          
    }
    return;
}

void Graph::drawToWindow(sf::RenderWindow* window)
{
    window->draw(background);

    window->draw(gridVector);

    for (auto graph: graphsToDraw)
    {
        for (auto line: graph)
        {
            window->draw(line);
        }
    }

    for (auto t: textVector)
    {
        window->draw(t);
    }
    return;
}

void Graph::setFunctionString(std::string funcStr) {
    functionString = funcStr;
    return;
}
