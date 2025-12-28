#include "NavigationController.h"
#include "GameController.h"
#include "ui.h"
#include "HangmanLogic.h"
#include <print>

int main(void) {
    // Create GUI of App
    auto App ( AppWindow::create() );

    // Create Controller
    NavigationController& navController ( NavigationController::getInstance() );    

    App->on_start_clicked([&] () {
        navController.GotoGame();
        GameController gameController;
    });
    
    App->on_settings_clicked([&] () {
        navController.GotoSettings();
    });
    
    App->on_quit_clicked([] () {
        slint::quit_event_loop();
        return 0;
    });

    

    App->run();
    return 0;
}

