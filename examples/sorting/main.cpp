#include "application.h"

int main()
{
    std::srand(static_cast<unsigned>(time(NULL)));

    Application app;

    while (app.windowIsOpen()) {
        app.update();
        app.render();
    }    
    return 0;
}
