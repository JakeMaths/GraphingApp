#include "gui.h"

Gui::Gui() {
    ibwMin = 0;
    ibwMax = GUI_PANE_WIDTH;
    ibhMin = 0;
    ibhMax = WINDOW_HEIGHT;

    inputBackground.setSize(sf::Vector2f(ibwMax-ibwMin, ibhMax-ibhMin));
    inputBackground.setPosition(sf::Vector2f(ibwMin, ibhMin));
    inputBackground.setFillColor(sf::Color::White);

    toggleButton.setSize(sf::Vector2f(GUI_TOP_OFFSET, GUI_TOP_OFFSET));
    toggleButton.setPosition(sf::Vector2f(ibwMax, ibhMin));
    toggleButton.setFillColor(sf::Color(100, 100, 100, 255));
    tbwMin = ibwMax;
    tbwMax = ibwMax + toggleButton.getSize().x;
    tbhMin = ibhMin;
    tbhMax = ibhMin + toggleButton.getSize().y;
    
    enabled = true;

    font.loadFromFile("res/arial.ttf");
    toggleText.setFont(font);
    toggleText.setString("-");
    toggleText.setCharacterSize(48);
    toggleText.setFillColor(sf::Color::Black);
    toggleText.setPosition(sf::Vector2f(ibwMax+15, ibhMin-10));

    inputText.setFont(font);
    inputText.setCharacterSize(24);
    inputText.setFillColor(sf::Color::Black);
    inputText.setPosition(sf::Vector2f(100, 100));

    inputText2.setFont(font);
    inputText2.setCharacterSize(24);
    inputText2.setFillColor(sf::Color::Black);
    inputText2.setPosition(sf::Vector2f(100, 200));

    inputText3.setFont(font);
    inputText3.setCharacterSize(24);
    inputText3.setFillColor(sf::Color::Black);
    inputText3.setPosition(sf::Vector2f(100, 300));

    inputText4.setFont(font);
    inputText4.setCharacterSize(24);
    inputText4.setFillColor(sf::Color::Black);
    inputText4.setPosition(sf::Vector2f(100, 400));

    inputText5.setFont(font);
    inputText5.setCharacterSize(24);
    inputText5.setFillColor(sf::Color::Black);
    inputText5.setPosition(sf::Vector2f(100, 500));

    border.setSize(sf::Vector2f(ibwMax-ibwMin, 1));
    border.setFillColor(sf::Color::Black);
}

void Gui::updateGui(const KeyStates &keyStates, int &inputMode) {
    if (keyStates.mouse1press && enabled) {
        if (keyStates.clickposx >= ibwMin
        &&  keyStates.clickposx <= ibwMax
        &&  keyStates.clickposy >= GUI_TOP_OFFSET
        &&  keyStates.clickposy <= GUI_TOP_OFFSET + GUI_INPUT_HEIGHT * NUM_INPUT_BOXES) {
            for (int i=0; i<NUM_INPUT_BOXES; i++) {
                if (keyStates.clickposy >= GUI_TOP_OFFSET + GUI_INPUT_HEIGHT * i
                &&  keyStates.clickposy <= GUI_TOP_OFFSET + GUI_INPUT_HEIGHT * (i+1)) {
                    inputMode = i+1;
                }
            }
        } else {
            inputMode = 0;
        }
    }

    if (keyStates.mouse1press
    &&  keyStates.clickposx >= tbwMin
    &&  keyStates.clickposx <= tbwMax
    &&  keyStates.clickposy >= tbhMin
    &&  keyStates.clickposy <= tbhMax) {
        if (enabled) {
            toggleButton.setPosition(sf::Vector2f(0, 0));
            toggleText.setPosition(sf::Vector2f(10, -5));
            toggleText.setString("+");
            tbwMin = 0;
            tbwMax = toggleButton.getSize().x;
            tbhMin = 0;
            tbhMax = toggleButton.getSize().y;
            enabled = false;
        } else {
            toggleButton.setPosition(sf::Vector2f(ibwMax, ibhMin));
            toggleText.setPosition(sf::Vector2f(ibwMax+15, ibhMin-10));
            toggleText.setString("-");
            tbwMin = ibwMax;
            tbwMax = ibwMax + toggleButton.getSize().x;
            tbhMin = ibhMin;
            tbhMax = ibhMin + toggleButton.getSize().y;
            enabled = true;
        }
    }

    if (inputMode == 1) {
        addKeyToText(keyStates, inputText);
    }
    if (inputMode == 2) {
        addKeyToText(keyStates, inputText2);
    }
    if (inputMode == 3) {
        addKeyToText(keyStates, inputText3);
    }
    if (inputMode == 4) {
        addKeyToText(keyStates, inputText4);
    }
    if (inputMode == 5) {
        addKeyToText(keyStates, inputText5);
    }

    return;
}

void Gui::drawToWindow(sf::RenderWindow* window) {
    window->draw(toggleButton);
    window->draw(toggleText);

    if (enabled) {
        window->draw(inputBackground);

        window->draw(inputText);
        window->draw(inputText2);
        window->draw(inputText3);
        window->draw(inputText4);
        window->draw(inputText5);

        border.setPosition(sf::Vector2f(ibwMin, ibhMin + GUI_TOP_OFFSET));
        window->draw(border);
        border.setPosition(sf::Vector2f(ibwMin, ibhMin + GUI_TOP_OFFSET + GUI_INPUT_HEIGHT));
        window->draw(border);
        border.setPosition(sf::Vector2f(ibwMin, ibhMin + GUI_TOP_OFFSET + GUI_INPUT_HEIGHT * 2));
        window->draw(border);
        border.setPosition(sf::Vector2f(ibwMin, ibhMin + GUI_TOP_OFFSET + GUI_INPUT_HEIGHT * 3));
        window->draw(border);
        border.setPosition(sf::Vector2f(ibwMin, ibhMin + GUI_TOP_OFFSET + GUI_INPUT_HEIGHT * 4));
        window->draw(border);
        border.setPosition(sf::Vector2f(ibwMin, ibhMin + GUI_TOP_OFFSET + GUI_INPUT_HEIGHT * 5));
        window->draw(border);

    }
    return;
}

std::string Gui::getFunctionString(int i) const {
    std::string out;
    switch (i) {
        case 1:
            out = inputText.getString();
            break;
        case 2:
            out = inputText2.getString();
            break;
        case 3:
            out = inputText3.getString();
            break;
        case 4:
            out = inputText4.getString();
            break;
        case 5:
            out = inputText5.getString();
            break;
    }
    return out;
}