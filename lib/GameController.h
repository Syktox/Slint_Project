#pragma once

#include "GameSettings.h"

namespace RaySIX {


class GameController {
public:
    GameController(const GameSettings& settings);
    ~GameController();

    //! Starts a new game (resets game and starts it with initial settings)
    void StartGame();

private:
    const GameSettings& m_GameSettings; //!< Reference to the Game Settings

};


} // RaySIX