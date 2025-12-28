#pragma once

enum Views {
    Home = 0,
    Game,
    Settings    
};

class NavigationController
{
public:
    ~NavigationController() = default;

    NavigationController(const NavigationController&) = delete;
    NavigationController operator=(const NavigationController&) = delete;

    static NavigationController& getInstance()
    {
        static NavigationController instance;
        return instance;
    }

    void GotoSettings();

private:
    NavigationController();

    //! Current Page
    Views current_view;
};