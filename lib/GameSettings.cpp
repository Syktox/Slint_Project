#include "GameSettings.h"

#include <fstream>
#include <cassert>
#include <sstream>


namespace RaySIX {

GameSettings::GameSettings()
: m_uiMusicVolume(50)
, m_uiMinimumWordLength(3)
, m_uiMaximumWordLength(10)
, m_uiMaxAttempts(6)
, m_bEnableSoundEffects(true)
{

}

GameSettings::~GameSettings() 
{

};


std::string GameSettings::GetSecretWord(int length /*= 0*/)
{
    // Open the word list file
    std::ifstream wordFile("assets/wordlist.txt");

    if ( !wordFile.is_open() ) 
    {
        assert(false && "Could not open wordlist.txt");
        return "";
    }

    std::string secretWord;
    while (std::getline(wordFile, secretWord)) {
        if (length == secretWord.length() || length == 0) 
        {
            break; // Found a word of the desired length
        }
    }
    
    wordFile.close();

    return secretWord;
}


} // RaySIX