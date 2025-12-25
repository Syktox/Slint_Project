#include "ui.h"
#include "HangmanLogic.h"

int main(void) {
    // Create GUI of App
    auto App ( AppWindow::create() );
    HangmanLogic hLogic;

    std::string ziel_wort = "PROGRAMMIEREN";

    App->on_buchstabe_getippt([&](slint::SharedString buchstabe) {
        std::string taste = std::string(buchstabe);
        // Hier prüfen: Ist 'taste' im 'ziel_wort'?
        
        // Beispiel: Fehler erhöhen
        hLogic.IncreaseErrors();
        App->set_fehler(hLogic.GetErrors());
        
        if (hLogic.GetErrors() >= 6) {
            // Spiel verloren Logik
        }
    });
    
    App->run();
    return 0;
}

