#pragma once

#include "GameSettings.h"

namespace RaySIX {


class GameController {
public:
    GameController(const GameSettings& settings);
    ~GameController();

    //! Starts a new game (resets game and starts it with initial settings)
    void StartGame();
    bool GuessLetter(const std::string& letter);
    bool IsGameOver() const;
    bool IsGameWon() const;

    //! Updates the Game UI with current game state
    void UpdateGameUI();

private:
    const GameSettings& m_GameSettings; //!< Reference to the Game Settings

};


} // RaySIX