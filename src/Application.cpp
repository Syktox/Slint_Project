#include "Application.h"

namespace RaySIX {

Application::Application() 
: m_AppView( AppWindow::create() )
, m_Nav ( std::make_unique<NavigationController<AppView>>(m_AppView) )
, m_GameSettings ( std::make_unique<GameSettings>() )
{
    InitGameSettings();
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
        m_Nav->navigate(ViewState::Game);
    });
    
    m_AppView->on_settings_clicked([&] () {
        m_Nav->navigate(ViewState::Settings);
    });
    
    m_AppView->on_quit_clicked([] () {
        slint::quit_event_loop();
        return 0;
    });
}


void Application::HandleCallbacksSettingsView()
{
    m_AppView->on_save_clicked([&] () {     
        // m_GameSettings->SetMusicVolume ( (int) m_AppView->get_music_volume() );
        // m_GameSettings->SetMinimumWordLength ( m_AppView->get_min_word_length() );
        // m_GameSettings->SetMaximumWordLength ( m_AppView->get_max_word_length() );
        // m_GameSettings->SetMaxAttempts ( m_AppView->get_max_attempts() );
        // m_GameSettings->SetSoundEffectsEnabled ( m_AppView->get_enable_sound_effects() );
                
        // Here you would typically save the settings to a file or apply them
        m_Nav->navigate(ViewState::Home);
    });
    
    m_AppView->on_cancel_clicked([&] () {
        // Discard changes and go back
        m_Nav->navigate(ViewState::Home);
    });

}


void Application::HandleCallbacksGameView()
{

}

void Application::InitGameSettings()
{
    slint_GameSettings settings
    {
        .music_volume = static_cast<float>( m_GameSettings->GetMusicVolume() ),
        .min_word_length = static_cast<float>( m_GameSettings->GetMinimumWordLength() ),
        .max_word_length = static_cast<float>( m_GameSettings->GetMaximumWordLength() ),
        .max_attempts = static_cast<float>( m_GameSettings->GetMaxAttempts() ),
        .sound_effects_enabled = m_GameSettings->AreSoundEffectsEnabled()
    };

    // Set the settings in the UI
    m_AppView->set_settings( settings );
}

}   // RaySIX