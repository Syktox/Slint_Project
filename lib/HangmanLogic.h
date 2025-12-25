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

    void IncreaseError() { m_errors += 1; }


private:
    int m_errors;

};