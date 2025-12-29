#pragma once

// NOTE: If you add some View here, you also have to add it to 
// the ui.slint file and change it correctly. (in property<int> current_view)

typedef enum Views {
    Home = 0,
    Game,
    Settings    
} View;