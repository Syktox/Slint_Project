#pragma once

#include "GameSettings.h"

namespace RaySIX {


class GameController {
public:
    GameController(const GameSettings& settings);
    ~GameController();

    //! Starts a new game (resets game and starts it with initial settings)
    void StartGame();
    bool GuessLetter(std::string_view letter);
    bool IsGameOver() const;
    bool IsGameWon() const;

    //! Updates the Game UI with current game state
    void UpdateGameUI();

private:
    GameSettings m_GameSettings; //!< Reference to the Game Settings
    std::string m_SecretWord;      //!< The secret word to guess
    std::string m_DisplayWord;     //!< The current display version of the word (with guessed letters)
    int m_Mistakes;                //!< Number of incorrect guesses
};


} // RaySIX