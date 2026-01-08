#include "Application.h"

#include <print>

namespace RaySIX {

Application::Application() 
: m_AppView( AppWindow::create() )
, m_Nav ( std::make_unique<NavigationController<AppView>>(m_AppView) )
, m_GameSettings ( std::make_unique<GameSettings>() )
, m_GameController ( std::make_unique<GameController> ( *m_GameSettings ) )
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
        m_GameController->StartGame();
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
        // Get Settings and save it.
        slint_GameSettings settings = m_AppView->get_settings();
        m_GameSettings->SetMusicVolume( static_cast<int>( settings.music_volume ) );
        m_GameSettings->SetMinimumWordLength( static_cast<int>( settings.min_word_length ) );
        m_GameSettings->SetMaximumWordLength( static_cast<int>( settings.max_word_length ) );
        m_GameSettings->SetMaxAttempts( static_cast<int>( settings.max_attempts ) );
        m_GameSettings->SetSoundEffectsEnabled( settings.sound_effects_enabled );
                
        // Here you would typically save the settings to a file or apply them
        m_Nav->navigate(ViewState::Home);
    });
    
    m_AppView->on_cancel_clicked([&] () {
        // Create settings from current GameSettings and set it in the UI
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

        // Discard changes and go back
        m_Nav->navigate(ViewState::Home);
    });

}


void Application::HandleCallbacksGameView()
{
    m_AppView->on_letter_pressed([&] (slint::SharedString letter) {
        m_GameController->GuessLetter(std::string_view ( letter ) );
        auto gameState = m_GameController->GetState(); 

        // Update the UI with the new game state
        m_AppView->set_display_word( slint::SharedString( gameState.displayWord ) );
        // m_AppView->set_mistakes( static_cast<float>( gameState.mistakes) );
    });

    m_AppView->on_reset_game([&] () {
        m_GameController->StartGame();
    });

    m_AppView->on_home_clicked([&] () {
        m_Nav->navigate(ViewState::Home);
    });
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