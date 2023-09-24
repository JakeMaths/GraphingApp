#pragma once

#include "header.h"

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
public:
    //! Default Constructor
    Gui();
    //! Update Gui
    void updateGui();
    //! Draw Gui to a window
    void drawToWindow(sf::RenderWindow* window);

};