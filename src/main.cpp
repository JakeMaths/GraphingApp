#include "application.h"

/// Program entry point.
///
/// Seed random. 
/// Create an instance of Application. 
/// Update app and render to the screen while the window is open.

int main()
{
    std::srand(std::time(nullptr));
    Application app;
    while (app.windowIsOpen()) {
        app.update();
        app.render();
    }    
    return 0;
}
