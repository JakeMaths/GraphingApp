#include "application.h"

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
