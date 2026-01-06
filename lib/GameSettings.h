#pragma once

#include <string>

namespace RaySIX {

class HangmanLogic
{
public:
    ~HangmanLogic() = default;

    //! Removed copying functionality
    HangmanLogic(const HangmanLogic&) = delete;
    HangmanLogic& operator=(const HangmanLogic&) = delete;

    //! Increases the errors the user made
    void IncreaseErrors() { m_errors += 1; }
    //! Returns the errors the user made
    int GetErrors() { return m_errors; }

    static HangmanLogic& getInstance() 
    {
        static HangmanLogic instance;
        return instance;
    }

    //! Returns a randomly secret word of given length; If no length is given, any length is possible
    std::string GetSecretWord(int length = 0);

    //! Resets the game
    void resetHangman();

private:
    //! private Constructor for Singleton
    HangmanLogic();

    int m_errors;   //!< Erros of the User
};

} // RaySIX