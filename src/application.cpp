#include "application.h"

void Application::initializeVariables() {
    this->window = nullptr; 
    sf::Vector2f xRange(DEFAULT_X_MIN, DEFAULT_X_MAX);
    sf::Vector2f yRange(DEFAULT_Y_MIN, DEFAULT_Y_MAX);
    sf::Vector2f wRange(DEFAULT_W_MIN, DEFAULT_W_MAX);
    sf::Vector2f hRange(DEFAULT_H_MIN, DEFAULT_H_MAX);
    this->graph = new Graph(xRange, yRange, wRange, hRange);
    this->gui = new Gui();
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
    delete this->gui;
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
                    keyStates.keyA = true;
                    break;
                case sf::Keyboard::B:
                    keyStates.keyB = true;
                    break;
                case sf::Keyboard::C:
                    keyStates.keyC = true;
                    break;
                case sf::Keyboard::D:
                    keyStates.keyD = true;
                    break;
                case sf::Keyboard::E:
                    keyStates.keyE = true;
                    break;
                case sf::Keyboard::F:
                    keyStates.keyF = true;
                    break;
                case sf::Keyboard::G:
                    keyStates.keyG = true;
                    break;
                case sf::Keyboard::H:
                    keyStates.keyH = true;
                    break;
                case sf::Keyboard::I:
                    keyStates.keyI = true;
                    break;
                case sf::Keyboard::J:
                    keyStates.keyJ = true;
                    break;
                case sf::Keyboard::K:
                    keyStates.keyK = true;
                    break;
                case sf::Keyboard::L:
                    keyStates.keyL = true;
                    break;
                case sf::Keyboard::M:
                    keyStates.keyM = true;
                    break;
                case sf::Keyboard::N:
                    keyStates.keyN = true;
                    break;
                case sf::Keyboard::O:
                    keyStates.keyO = true;
                    break;
                case sf::Keyboard::P:
                    keyStates.keyP = true;
                    break;
                case sf::Keyboard::Q:
                    keyStates.keyQ = true;
                    break;
                case sf::Keyboard::R:
                    keyStates.keyR = true;
                    break;
                case sf::Keyboard::S:
                    keyStates.keyS = true;
                    break;
                case sf::Keyboard::T:
                    keyStates.keyT = true;
                    break;
                case sf::Keyboard::U:
                    keyStates.keyU = true;
                    break;
                case sf::Keyboard::V:
                    keyStates.keyV = true;
                    break;
                case sf::Keyboard::W:
                    keyStates.keyW = true;
                    break;
                case sf::Keyboard::X:
                    keyStates.keyX = true;
                    break;
                case sf::Keyboard::Y:
                    keyStates.keyY = true;
                    break;
                case sf::Keyboard::Z:
                    keyStates.keyZ = true;
                    break;
                case sf::Keyboard::Num1:
                    keyStates.key1 = true;
                    break;
                case sf::Keyboard::Num2:
                    keyStates.key2 = true;
                    break;
                case sf::Keyboard::Num3:
                    keyStates.key3 = true;
                    break;
                case sf::Keyboard::Num4:
                    keyStates.key4 = true;
                    break;
                case sf::Keyboard::Num5:
                    keyStates.key5 = true;
                    break;
                case sf::Keyboard::Num6:
                    keyStates.key6 = true;
                    break;
                case sf::Keyboard::Num7:
                    keyStates.key7 = true;
                    break;
                case sf::Keyboard::Num8:
                    keyStates.key8 = true;
                    break;
                case sf::Keyboard::Num9:
                    keyStates.key9 = true;
                    break;
                case sf::Keyboard::Num0:
                    keyStates.key0 = true;
                    break;
                case sf::Keyboard::Up:
                    keyStates.keyUp = true;
                    break;
                case sf::Keyboard::Down:
                    keyStates.keyDown = true;
                    break;
                case sf::Keyboard::Right:
                    keyStates.keyRight = true;
                    break;
                case sf::Keyboard::Left:
                    keyStates.keyLeft = true;
                    break;
                case sf::Keyboard::Equal:
                    keyStates.keyEqual = true;
                    break;
                case sf::Keyboard::Hyphen:
                    keyStates.keyHyphen = true;
                    break;
            }
            break;
        case sf::Event::KeyReleased:
            switch(this->event.key.code) {
                case sf::Keyboard::A:
                    keyStates.keyA = false;
                    break;
                case sf::Keyboard::B:
                    keyStates.keyB = false;
                    break;
                case sf::Keyboard::C:
                    keyStates.keyC = false;
                    break;
                case sf::Keyboard::D:
                    keyStates.keyD = false;
                    break;
                case sf::Keyboard::E:
                    keyStates.keyE = false;
                    break;
                case sf::Keyboard::F:
                    keyStates.keyF = false;
                    break;
                case sf::Keyboard::G:
                    keyStates.keyG = false;
                    break;
                case sf::Keyboard::H:
                    keyStates.keyH = false;
                    break;
                case sf::Keyboard::I:
                    keyStates.keyI = false;
                    break;
                case sf::Keyboard::J:
                    keyStates.keyJ = false;
                    break;
                case sf::Keyboard::K:
                    keyStates.keyK = false;
                    break;
                case sf::Keyboard::L:
                    keyStates.keyL = false;
                    break;
                case sf::Keyboard::M:
                    keyStates.keyM = false;
                    break;
                case sf::Keyboard::N:
                    keyStates.keyN = false;
                    break;
                case sf::Keyboard::O:
                    keyStates.keyO = false;
                    break;
                case sf::Keyboard::P:
                    keyStates.keyP = false;
                    break;
                case sf::Keyboard::Q:
                    keyStates.keyQ = false;
                    break;
                case sf::Keyboard::R:
                    keyStates.keyR = false;
                    break;
                case sf::Keyboard::S:
                    keyStates.keyS = false;
                    break;
                case sf::Keyboard::T:
                    keyStates.keyT = false;
                    break;
                case sf::Keyboard::U:
                    keyStates.keyU = false;
                    break;
                case sf::Keyboard::V:
                    keyStates.keyV = false;
                    break;
                case sf::Keyboard::W:
                    keyStates.keyW = false;
                    break;
                case sf::Keyboard::X:
                    keyStates.keyX = false;
                    break;
                case sf::Keyboard::Y:
                    keyStates.keyY = false;
                    break;
                case sf::Keyboard::Z:
                    keyStates.keyZ = false;
                    break;
                case sf::Keyboard::Num1:
                    keyStates.key1 = false;
                    break;
                case sf::Keyboard::Num2:
                    keyStates.key2 = false;
                    break;
                case sf::Keyboard::Num3:
                    keyStates.key3 = false;
                    break;
                case sf::Keyboard::Num4:
                    keyStates.key4 = false;
                    break;
                case sf::Keyboard::Num5:
                    keyStates.key5 = false;
                    break;
                case sf::Keyboard::Num6:
                    keyStates.key6 = false;
                    break;
                case sf::Keyboard::Num7:
                    keyStates.key7 = false;
                    break;
                case sf::Keyboard::Num8:
                    keyStates.key8 = false;
                    break;
                case sf::Keyboard::Num9:
                    keyStates.key9 = false;
                    break;
                case sf::Keyboard::Num0:
                    keyStates.key0 = false;
                    break;
                case sf::Keyboard::Up:
                    keyStates.keyUp = false;
                    break;
                case sf::Keyboard::Down:
                    keyStates.keyDown = false;
                    break;
                case sf::Keyboard::Right:
                    keyStates.keyRight = false;
                    break;
                case sf::Keyboard::Left:
                    keyStates.keyLeft = false;
                    break;
                case sf::Keyboard::Equal:
                    keyStates.keyEqual = false;
                    break;
                case sf::Keyboard::Hyphen:
                    keyStates.keyHyphen = false;
                    break;
            }
            break;
        }
    }
}

void Application::update() {
    pollEvents();
    graph->updateGraph(keyStates);
    gui->updateGui();
}

void Application::render()
{
    window->clear();
    graph->drawToWindow(window);
    gui->drawToWindow(window);
    window->display();
}


