#include "Application.h"
#include "NavigationController.h"

void Application::run() {
    // Create GUI of App
    auto App ( AppWindow::create() );
    NavigationController nav;

    nav.set_on_navigate([&](View p) {
        App->set_current_view(static_cast<int>(p));
    });

    App->on_start_clicked([&] () {
        nav.go_to(View::Game);
    });
    
    App->on_settings_clicked([&] () {
        nav.go_to(View::Settings);
    });
    
    App->on_quit_clicked([] () {
        slint::quit_event_loop();
        return 0;
    });

    App->run();
}