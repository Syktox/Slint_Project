#include "Application.h"

namespace RaySIX {

Application::Application() 
: m_AppView( AppWindow::create() )
, m_Nav ( std::make_unique<NavigationController<AppView>>(m_AppView) )
{

};

Application::~Application() = default;

void Application::run() {
    HandleCallbacksHomeView();
    HandleCallbacksSettingsView();
    HandleCallbacksGameView();

    m_AppView->run();
}


void Application::HandleCallbacksHomeView()
{
    m_AppView->on_start_clicked([&] () {
        m_Nav->navigate(View::Game);
    });
    
    m_AppView->on_settings_clicked([&] () {
        m_Nav->navigate(View::Settings);
    });
    
    m_AppView->on_quit_clicked([] () {
        slint::quit_event_loop();
        return 0;
    });
}


void Application::HandleCallbacksSettingsView()
{
    m_AppView->on_save_clicked([&] () {
        // Here you would typically save the settings to a file or apply them
        m_Nav->navigate(View::Home);
    });
    
    m_AppView->on_cancel_clicked([&] () {
        // Discard changes and go back
        m_Nav->navigate(View::Home);
    });

}


void Application::HandleCallbacksGameView()
{

}

}   // RaySIX