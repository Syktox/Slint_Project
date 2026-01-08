#include "GameController.h" 

#include <print>

namespace RaySIX {

GameController::GameController(const GameSettings& settings)
: m_GameSettings ( settings )
{

}

GameController::~GameController()
{

}


void GameController::StartGame()
{
    std::printf("Game Started %d - %d attempts\n", m_GameSettings.GetMinimumWordLength(), m_GameSettings.GetMaxAttempts());
}

} // RaySIX