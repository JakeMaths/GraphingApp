#include "application.h"


// Private functions

void Application::initializeVariables() {
    this->window = nullptr; 
}

void Application::initializeWindow() {
    this->videoMode.width = 1920;
    this->videoMode.height = 1080;
    this->window = new sf::RenderWindow(this->videoMode, "Application", sf::Style::None);
                                      //  sf::Style::Titlebar | sf::Style::Close);
    this->window->setPosition(sf::Vector2i(0, 0));
}

// Constructors / Destructors

Application::Application() {
    this->initializeVariables();
    this->initializeWindow();
}

Application::~Application() {
    delete this->window;
}

// Accessors

const bool Application::windowIsOpen() const {
    return this->window->isOpen();
}

// Functions

void Application::pollEvents() {
    while (this->window->pollEvent(this->event)) {
        switch (this->event.type) {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->event.key.code == sf::Keyboard::Escape) {
                this->window->close();
            }
            break;
        }
    }
}

void Application::update() {
    this->pollEvents();
}

void Application::render() {
    this->window->clear();

    sf::RectangleShape rect(sf::Vector2f(80.f, 80.f));
    rect.setPosition(100.f, 100.f);
    this->window->draw(rect);

    this->window->display();
}


