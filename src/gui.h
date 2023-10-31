#pragma once

#include "header.h"
#include "keystates.h"

/// Manages the gui for the application.
///
/// .
class Gui
{
private:
    // Variables
    //! Input Region Background Min Width
    float ibwMin;
    //! Input Region Background Max Width
    float ibwMax;
    //! Input Region Background Min Height
    float ibhMin;
    //! Input Region Background Max Height
    float ibhMax;

    //! Input Region Background
    sf::RectangleShape inputBackground;

    //! Toggle (enable/disable) GUI Button
    sf::RectangleShape toggleButton;
    //! Toggle button min width
    float tbwMin;
    //! Toggle button max width
    float tbwMax;
    //! Toggle button min height
    float tbhMin;
    //! Toggle button max height
    float tbhMax;
    //! GUI enabled
    bool enabled;
    //! Toggle Button Text
    sf::Text toggleText;

    //! Input Text for GUI
    sf::Text inputText;
    //! Font for drawing text
    sf::Font font;

    //! Input Region Border Top
    sf::RectangleShape borderTop;
    //! Input Region Border Bottom
    sf::RectangleShape borderBottom;
public:
    //! Default Constructor
    Gui();
    //! Update Gui
    void updateGui(const KeyStates &keyStates, int &inputMode);
    //! Draw Gui to a window
    void drawToWindow(sf::RenderWindow* window);
    //! Get function string from gui
    std::string getFunctionString() const;
};