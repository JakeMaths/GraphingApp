#include "application.h"
#include "test_funcs.h"

// Private functions

void Application::initializeVariables() {
    this->window = nullptr; 
    this->gridTile.setPosition(sf::Vector2f(W_MIN,H_MIN));
    this->gridTile.setSize(sf::Vector2f(TILE_WIDTH, TILE_HEIGHT));
    gridRows = (H_MAX - H_MIN) / TILE_HEIGHT;
    gridCols = (W_MAX - W_MIN) / TILE_WIDTH;
    for (int i=0; i<this->gridRows; i++) {
        for (int j=0; j<this->gridCols; j++) {
            this->gridTile.setPosition(sf::Vector2f(
                W_MIN + TILE_WIDTH * j,
                H_MIN + TILE_HEIGHT * i
            ));
            this->gridVector.push_back(this->gridTile);
        }
    }
}

void Application::initializeWindow() {
    this->videoMode.width = WINDOW_WIDTH;
    this->videoMode.height = WINDOW_HEIGHT;
    this->window = new sf::RenderWindow(this->videoMode, "Application", sf::Style::None);
                                      //  sf::Style::Titlebar | sf::Style::Close);
    this->window->setPosition(sf::Vector2i(0, 0));
    this->window->setFramerateLimit(60);
}

sf::Vector2f Application::gridToScreen(sf::Vector2u gpos) {
    sf::Vector2f spos;
    spos.x = W_MIN + (gpos.x) * (W_MAX - W_MIN) / (this->gridCols);
    spos.y = H_MIN + (gpos.y) * (H_MAX - H_MIN) / (this->gridRows);
    return spos;
}

sf::Vector2f Application::screenToEuclidean(sf::Vector2f spos) {
    sf::Vector2f epos;
    epos.x = X_MIN + (spos.x - W_MIN) * (X_MAX - X_MIN) / (W_MAX - W_MIN);
    epos.y = Y_MAX - (spos.y - H_MIN) * (Y_MAX - Y_MIN) / (H_MAX - H_MIN);
    return epos;
}

sf::Vector2f Application::euclideanToScreen(sf::Vector2f epos) {
    sf::Vector2f spos;
    spos.x = W_MIN + (epos.x - X_MIN) * (W_MAX - W_MIN) / (X_MAX - X_MIN);
    spos.y = H_MIN + (Y_MAX - epos.y) * (H_MAX - H_MIN) / (Y_MAX - Y_MIN);
    return spos;
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
//    int k = std::rand() % (this->gridRows * this->gridCols);
//    this->gridVector[k].setFillColor(sf::Color::Red);
    for (int i=0; i<this->gridRows; i++) {
        for (int j=0; j<this->gridCols; j++) {
            sf::Vector2f euclidean = this->screenToEuclidean(
                this->gridToScreen( sf::Vector2u(j,i) )
            ); 
            if (std::abs( euclidean.y - funcB(euclidean.x) ) < 0.01) {
                this->gridVector[i*gridRows + j].setFillColor(sf::Color::Red);
            }
        }
    }
}

void Application::render() {
    this->window->clear();

    for (int i=0; i<this->gridRows; i++) {
        for (int j=0; j<this->gridCols; j++ ) {
            this->window->draw(this->gridVector[i*gridRows + j]);
        }
    }
//    for (int i=0; i<this->gridRows*this->gridCols; i++) {
//        this->window->draw(this->gridVector[i]);
//    }
//    for (auto v : this->gridVector) {
//        this->window->draw(v);
//    } 

    this->window->display();
}


