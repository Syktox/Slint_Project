#pragma once

#include "ui.h"
#include "NavigationController.h"
#include "GameSettings.h"

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

    AppView m_AppView;  //!< on unique_ptr needed; ComponentHandle manages itself
    std::unique_ptr<NavigationController<AppView>> m_Nav;   //!< Navigation Controller to handle View Navigation
    
};

} // RaySIX