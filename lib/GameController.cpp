#include "GameController.h" 

#include <print>

namespace RaySIX {

GameController::GameController(const GameSettings& settings)
: m_GameSettings ( settings )
, m_Mistakes ( 0 )
{

}

GameController::~GameController()
{

}


void GameController::StartGame()
{
    m_SecretWord = m_GameSettings.GetSecretWord( m_GameSettings.GetMaximumWordLength() );
    m_DisplayWord = std::string( m_SecretWord.length(), '_' );
    m_Mistakes = 0;

    std::printf("%s\t\t(Display Word: %s)\n", m_SecretWord.c_str(), m_DisplayWord.c_str());    
}

bool GameController::GuessLetter(std::string_view letter)
{
    if (letter.empty()) 
        return false;
    
    if (letter.find(m_SecretWord) != std::string::npos) 
    {
      return true;
    }
    else 
    {
        m_Mistakes++;
        std::printf("Incorrect guess. Total mistakes: %d\n", m_Mistakes);
        return false;
    }

    return false;
}

bool GameController::IsGameOver() const
{
    return false;
}

bool GameController::IsGameWon() const
{
    return false;
}

GameState GameController::GetState() const
{
    return { 
        m_DisplayWord, 
        m_Mistakes, 
        IsGameOver(), 
        IsGameWon() 
    };
}

} // RaySIX