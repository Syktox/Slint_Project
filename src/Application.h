#pragma once

#include "ui.h"
#include "NavigationController.h"
#include "GameSettings.h"
#include "GameController.h"

namespace RaySIX {

typedef slint::ComponentHandle<AppWindow> AppView;

class Application {
public:
    Application();
    virtual ~Application();

    void run();

private:
    //! Handles all Callbacks for the HomeView
    void HandleCallbacksHomeView();

    //! Handles all Callbacks for the SettingsView
    void HandleCallbacksSettingsView();

    //! Handles all Callbacks for the GameView
    void HandleCallbacksGameView();

    //! Initialize Game Settings in the UI from m_GameSettings
    void InitGameSettings();

    AppView m_AppView;  //!< on unique_ptr needed; ComponentHandle manages itself
    std::unique_ptr<NavigationController<AppView>> m_Nav;   //!< Navigation Controller to handle View Navigation
    std::unique_ptr<GameSettings> m_GameSettings;  //!< Game Settings Manager
    std::unique_ptr<GameController> m_GameController;  //!< Game Controller
};

} // RaySIX