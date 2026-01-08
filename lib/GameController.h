#pragma once

#include "GameSettings.h"

namespace RaySIX {

struct GameState {
    std::string displayWord;
    int mistakes;
    bool gameOver;
    bool gameWon;
};

class GameController {
public:
    GameController(const GameSettings& settings);
    ~GameController();

    //! Starts a new game (resets game and starts it with initial settings)
    void StartGame();
    bool GuessLetter(std::string_view letter);
    bool IsGameOver() const;
    bool IsGameWon() const;

    //! Returns the Game State to update the UI
    GameState GetState() const;

private:
    GameSettings m_GameSettings; //!< Reference to the Game Settings
    std::string m_SecretWord;      //!< The secret word to guess
    std::string m_DisplayWord;     //!< The current display version of the word (with guessed letters)
    int m_Mistakes;                //!< Number of incorrect guesses
};


} // RaySIX