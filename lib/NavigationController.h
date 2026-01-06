#pragma once
#include "Views.h"

namespace RaySIX {

template <typename App>
class NavigationController {
public: 
    explicit NavigationController(App& app)
    : m_App(app)
    {
    };

    virtual ~NavigationController() = default;

    void navigate (ViewState page) {
        current = page;
        m_App->set_current_view ( page );
    }

    View current_page() const {
        return current;
    }

private:
    App& m_App; //!< Slint API used for the View; Zugriff immer als Pointer
    ViewState current;
};

}   // RaySIX