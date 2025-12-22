#include "MainWindow.h"
#include <memory>

int main(int argc, char **argv) {
    // Instanz der UI erstellen
    auto ui = MainWindow::create();

    // Initialen Wert für eine Property setzen
    ui->set_user_name("Syktox");

    // Den Callback (Button-Klick) mit C++ Logik verbinden
    ui->on_button_clicked([&] {
        // Aktuellen Wert aus der UI lesen
        int current_count = ui->get_counter();
        
        // Wert erhöhen und zurück an die UI senden
        ui->set_counter(current_count + 1);
    });

    // Fenster anzeigen und Event-Loop starten
    ui->run();

    return 0;
}