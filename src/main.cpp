#include "ui.h"
#include "HangmanLogic.h"
#include <print>

int main(void) {
    // Create GUI of App
    auto App ( AppWindow::create() );

    // Create logic
    HangmanLogic& hLogic ( HangmanLogic::getInstance() );
    std::string secretWord ( hLogic.GetSecretWord(8) );  

    App->on_quit_clicked([&] () {
        slint::quit_event_loop();
    });
    
    
   
    App->run();
    return 0;
}

