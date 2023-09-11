#include "application.h"


// Private functions

void Application::initializeVariables() {
    this->window = nullptr; 
    this->sortArrayLength = 1000;
    for (int i=0; i<this->sortArrayLength; i++) {
        this->sortArray.push_back(sortArrayLength - i);
        this->sortBarColors.push_back(1);
    }
    this->timeDelta = 0.00001;
    this->shuffleSortArray();
}

void Application::initializeWindow() {
    this->videoMode.width = 1920;
    this->videoMode.height = 1080;
    this->window = new sf::RenderWindow(this->videoMode, "Application", sf::Style::None);
                                      //  sf::Style::Titlebar | sf::Style::Close);
    this->window->setPosition(sf::Vector2i(0, 0));
}

void Application::initializeSortBars() {
    this->sortBars.clear();
    this->sortBarWidth = this->videoMode.width / static_cast<float>(this->sortArrayLength); 
    int maxValue = this->sortArray[0];
    for (int i=0; i<this->sortArrayLength; i++) {
        if (this->sortArray[i] > maxValue) {
            maxValue = sortArray[i];
        }
    }
    for (int i=0; i<this->sortArrayLength; i++) {
        this->sortBar.setPosition(
            this->sortBarWidth * i,
            this->videoMode.height * (1 - this->sortArray[i] / static_cast<float>(maxValue))
        );
        this->sortBar.setSize(sf::Vector2f(
            this->sortBarWidth,
            this->videoMode.height * this->sortArray[i] / static_cast<float>(maxValue)
        ));
        switch (this->sortBarColors[i]) {
            case 1:
                this->sortBar.setFillColor(sf::Color::White);
                break;
            case 2:
                this->sortBar.setFillColor(sf::Color::Red);
                break;
            default:
                this->sortBar.setFillColor(sf::Color::Black);
                break;
        }
        this->sortBars.push_back(this->sortBar);
    }
}

void Application::shuffleSortArray() {
    for (int i=0; i<this->sortArrayLength; i++) {
        int randIndex1 = std::rand() % this->sortArrayLength;
        int randIndex2 = std::rand() % this->sortArrayLength;
        int temp = this->sortArray[randIndex1];
        this->sortArray[randIndex1] = this->sortArray[randIndex2];
        this->sortArray[randIndex2] = temp; 
    }
}

void Application::clearSortBarColors() {
    this->sortBarColors.clear();
    for (int i=0; i<this->sortArrayLength; i++) {
        this->sortBarColors.push_back(1);
    }
}

void Application::bubbleSortStep() {
    static int i = 0;
    static int j = 0;
    if (i < this->sortArrayLength - 1) {
        this->clearSortBarColors();
        if (j < this->sortArrayLength - 1 - i) {
            if (this->sortArray[j] > this->sortArray[j+1]) {
                int temp = this->sortArray[j];
                this->sortArray[j] = this->sortArray[j+1];
                this->sortArray[j+1] = temp;

                this->sortBarColors[j] = 2;
                this->sortBarColors[j+1] = 2;                

                sf::Clock clock;
                while (clock.getElapsedTime().asSeconds() < this->timeDelta);
            }
            j++;
        } else {
            j = 0;
            i++;
        }
    }
}

void Application::insertionSortStep() {
    static int i = 1;
    static int j = 0;
    static int key = this->sortArray[i];
    if (i < this->sortArrayLength) {
        this->clearSortBarColors();
        if (j >= 0 && this->sortArray[j] > key) {
            this->sortArray[j+1] = this->sortArray[j];

            this->sortBarColors[j] = 2;
            this->sortBarColors[j+1] = 2;

            j--;

            sf::Clock clock;
            while (clock.getElapsedTime().asSeconds() < this->timeDelta);
        } else {
            this->sortArray[j+1] = key;
            i++;
            j = i - 1;
            key = this->sortArray[i];
        }
        
    }
}

// Constructors / Destructors

Application::Application() {
    this->initializeVariables();
    this->initializeWindow();
    this->initializeSortBars();
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

    this->bubbleSortStep();
//    this->insertionSortStep();

    this->initializeSortBars();    
}

void Application::render() {
    this->window->clear();

    for (int i=0; i<this->sortArrayLength; i++) {
        this->window->draw(this->sortBars[i]);
    }

    this->window->display();
}


