#pragma once

#include <string>

/*! Note on init you should search for a json file and load the settings if the file is there
if there is no file, we create a file and init the standard settings
We save the new settings when the save button was clicked
*/

namespace RaySIX {

class GameSettings
{
public:
    GameSettings();
    virtual ~GameSettings();

    //! Returns a randomly secret word of given length; If no length is given, any length is possible
    std::string GetSecretWord(int length = 0);

    //! Get music volume (0-100)
    unsigned int GetMusicVolume() const { return m_uiMusicVolume; }
    //! Set music volume (0-100)
    void SetMusicVolume(unsigned int volume) { m_uiMusicVolume = volume; }

    //! Get minimum word length
    unsigned int GetMinimumWordLength() const { return m_uiMinimumWordLength; }
    //! Set minimum word length
    void SetMinimumWordLength(unsigned int length) { m_uiMinimumWordLength = length; }

    //! Get maximum word length
    unsigned int GetMaximumWordLength() const  { return m_uiMaximumWordLength; }
    //! Set maximum word length
    void SetMaximumWordLength(unsigned int length)  { m_uiMaximumWordLength = length; }

    //! Get maximum attempts
    unsigned int GetMaxAttempts() const { return m_uiMaxAttempts; }
    //! Set maximum attempts
    void SetMaxAttempts(unsigned int attempts) { m_uiMaxAttempts = attempts; }

    //! Check if sound effects are enabled
    bool AreSoundEffectsEnabled() const { return m_bEnableSoundEffects; }
    //! Set sound effects enabled/disabled
    void SetSoundEffectsEnabled(bool enabled)  { m_bEnableSoundEffects = enabled; }
    

private:
    int m_uiMusicVolume; //!< Music volume (0-100)
    int m_uiMinimumWordLength; //!< Minimum word length for secret words
    int m_uiMaximumWordLength; //!< Maximum word length for secret words
    int m_uiMaxAttempts; //!< Maximum number of wrong attempts in Hangman
    bool m_bEnableSoundEffects; //!< Enable or disable sound effects
};

} // RaySIX