#include "NavigationController.h"
#include "GameController.h"
#include "ui.h"

#include "HangmanLogic.h"

#include <print>
#include <fstream>

int main(void) {
    // Create GUI of App
    auto App ( AppWindow::create() );

    // Create Controller
    NavigationController& navController ( NavigationController::getInstance() );    

    App->on_start_clicked([] () {
        GameController gameController;
    });
    
    App->on_settings_clicked([&] () {
        navController.GotoSettings();
    });
    
    App->on_quit_clicked([] () {
        slint::quit_event_loop();
    });

    

    App->run();
    return 0;
}

