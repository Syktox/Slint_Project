#pragma once
#include "Views.h"
#include <functional>

class NavigationController {
public:
    NavigationController();
    virtual ~NavigationController() = default;

    using Callback = std::function<void(View)>;

    void set_on_navigate(Callback cb) {
        onNavigate = cb;
    }

    void go_to(View page) {
        current = page;
        if (onNavigate) onNavigate(page);
    }

    View current_page() const {
        return current;
    }

private:
    View current;
    Callback onNavigate;
};