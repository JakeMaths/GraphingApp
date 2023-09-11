#include "application.h"

int main()
{
    Application app;
    while (app.windowIsOpen()) {
        app.update();
        app.render();
    }    
    return 0;
}
