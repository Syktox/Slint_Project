#pragma once

class HangmanLogic
{
public:
    HangmanLogic();
    ~HangmanLogic() = default;

    HangmanLogic(const HangmanLogic&) = delete;
    HangmanLogic& operator=(const HangmanLogic&) = delete;

    HangmanLogic(HangmanLogic&&) = delete;
    HangmanLogic& operator=(HangmanLogic&&) = delete;

    //! Increases the errors the user made
    void IncreaseErrors() { m_errors += 1; }
    //! Returns the errors the user made
    int GetErrors() { return m_errors; }


private:
    int m_errors;   //!< Erros of the User

};