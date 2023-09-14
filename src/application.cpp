#include "application.h"

void Application::initializeVariables() {
    this->window = nullptr; 
    sf::Vector2f xRange(DEFAULT_X_MIN, DEFAULT_X_MAX);
    sf::Vector2f yRange(DEFAULT_Y_MIN, DEFAULT_Y_MAX);
    sf::Vector2f wRange(DEFAULT_W_MIN, DEFAULT_W_MAX);
    sf::Vector2f hRange(DEFAULT_H_MIN, DEFAULT_H_MAX);
    this->graph = new Graph(xRange, yRange, wRange, hRange);
}

void Application::initializeWindow() {
    this->videoMode.width = WINDOW_WIDTH;
    this->videoMode.height = WINDOW_HEIGHT;
    this->window = new sf::RenderWindow(this->videoMode, "Application", sf::Style::None);
                                      //  sf::Style::Titlebar | sf::Style::Close);
    this->window->setPosition(sf::Vector2i(0, 0));
    this->window->setFramerateLimit(60);
}

Application::Application() {
    this->initializeVariables();
    this->initializeWindow();
}

Application::~Application() {
    delete this->window;
    delete this->graph;
}

const bool Application::windowIsOpen() const {
    return this->window->isOpen();
}

void Application::pollEvents() {
    while (this->window->pollEvent(this->event)) {
        switch (this->event.type) {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            switch (this->event.key.code) {
                case sf::Keyboard::Escape:
                    this->window->close();
                    break;
                case sf::Keyboard::A:
                    graph->setGraphMode(1);
                    break;
                case sf::Keyboard::B:
                    graph->setGraphMode(2);
                    break;
                case sf::Keyboard::C:
                    graph->setGraphMode(3);
                    break;
                case sf::Keyboard::D:
                    graph->setGraphMode(4);
                    break;
                case sf::Keyboard::E:
                    graph->setGraphMode(5);
                    break;
                case sf::Keyboard::F:
                    graph->setGraphMode(6);
                    break;
                case sf::Keyboard::G:
                    graph->setGraphMode(7);
                    break;
                case sf::Keyboard::Right:
                    graph->incXRange(0.1);
                    break;
                case sf::Keyboard::Left:
                    graph->decXRange(0.1);
                    break;
                case sf::Keyboard::Up:
                    graph->incYRange(0.1);
                    break;
                case sf::Keyboard::Down:
                    graph->decYRange(0.1);
                    break;
            }
            break;
        }
    }
}

void Application::update() {
    pollEvents();
    graph->updateGraph();
}

void Application::render()
{
    window->clear();
    graph->drawToWindow(window);
    window->display();
}


