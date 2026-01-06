#pragma once

#include <string>

namespace RaySIX {

class GameSettings
{
public:
    GameSettings();
    virtual ~GameSettings();

    //! Increases the errors the user made
    void IncreaseErrors() { m_errors += 1; }
    //! Returns the errors the user made
    int GetErrors() { return m_errors; }

    //! Returns a randomly secret word of given length; If no length is given, any length is possible
    std::string GetSecretWord(int length = 0);

    //! Resets the game
    void resetHangman();

private:
    int m_errors;   //!< Erros of the User
};

} // RaySIX