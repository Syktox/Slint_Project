#include "NavigationController.h"

NavigationController::NavigationController() 
: current (View::Home)
, onNavigate ( nullptr )
{
    
}