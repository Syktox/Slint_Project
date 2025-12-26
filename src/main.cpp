#include "ui.h"
#include "HangmanLogic.h"


int main(void) {
    // Create GUI of App
    auto App ( AppWindow::create() );

    // Create logic
    HangmanLogic& hLogic = HangmanLogic::getInstance();
    std::string secretWord = hLogic.GetSecretWord(8);

    App->on_buchstabe_getippt([&](slint::SharedString buchstabe) {
        std::string taste = std::string(buchstabe);
     
        if (secretWord.find(taste) != std::string::npos) 
        {
            
        }
        else 
        {
            hLogic.IncreaseErrors();
            App->set_fehler(hLogic.GetErrors());
        }
        
        if (hLogic.GetErrors() >= 6) {
            // Spiel verloren Logik
        }
    });
    
    App->run();
    return 0;
}

