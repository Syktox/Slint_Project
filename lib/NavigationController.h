#pragma once

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


private:
    NavigationController();

};