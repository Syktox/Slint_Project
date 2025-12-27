#include "ui.h"
#include "HangmanLogic.h"
#include <print>

int main(void) {
    // Create GUI of App
    auto App ( AppWindow::create() );

    // Create logic
    HangmanLogic& hLogic ( HangmanLogic::getInstance() );
    std::string secretWord ( hLogic.GetSecretWord(8) );  

    App->on_reset_clicked([&] () {
        hLogic.resetHangman();
        std::print("Secret Word: {}\n", secretWord);
    });

    App->on_start_clicked([&] () {
        hLogic.resetHangman();
    });
    
    App->run();
    return 0;
}

