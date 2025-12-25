#include "ui.h"
#include "HangmanLogic.h"

int main(void) {
    // Create GUI of App
    auto App ( AppWindow::create() );
    HangmanLogic hLogic;


    
    
    App->run();
    return 0;
}

