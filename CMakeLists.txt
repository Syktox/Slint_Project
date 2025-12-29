cmake_minimum_required(VERSION 3.31)

# ==========================================
# 1. PROJEKT-KONFIGURATION (Hier alles ändern)
# ==========================================
set(MY_PROJECT_NAME    "Hangman")
set(MY_PROJECT_VERSION "1.0.0")
set(MY_LIB_NAME        "HangmanLogic") # Name deiner Library aus dem lib-Ordner

# Liste aller Quelldateien im src-Ordner
set(MY_SOURCES
    "src/main.cpp"
    "src/Application.h"
    "src/Application.cpp"
    # "src/weitere_datei.cpp" <-- einfach hier erweitern
)

# Liste aller Slint-UI-Dateien
# Note: Man darf hier nur eine slint Datei haben. Slint Dateien sollte man in diese Datei importieren.
set(MY_UI_FILES
    "ui/ui.slint"
)

# C++ Standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==========================================
# 2. PROJEKT-SETUP
# ==========================================
project(${MY_PROJECT_NAME} VERSION ${MY_PROJECT_VERSION} LANGUAGES CXX)

# Hilfreich für macOS/Homebrew Pfade
if(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")
endif()

# ==========================================
# 3. SLINT (FIND-OR-FETCH LOGIK)
# ==========================================
# 1. Optionen setzen, um Ballast zu vermeiden
set(SLINT_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(SLINT_BUILD_TESTS OFF CACHE INTERNAL "")
set(SLINT_BUILD_DOCS OFF CACHE INTERNAL "")

include(FetchContent)

find_package(Slint QUIET)

if(NOT Slint_FOUND)
    message(STATUS "Slint nicht auf dem System gefunden.")
    FetchContent_Declare(
        Slint
        GIT_REPOSITORY https://github.com/slint-ui/slint.git
        GIT_TAG release/1.14
        GIT_SHALLOW TRUE
        SOURCE_SUBDIR api/cpp
    )
    FetchContent_MakeAvailable(Slint)
endif()

# ==========================================
# 4. TARGETS & LINKING
# ========================================== 

# Unterverzeichnis für deine Library einbinden
add_subdirectory(lib)

# Das Hauptprogramm erstellen (nutzt die Liste aus MY_SOURCES)
add_executable(${MY_PROJECT_NAME} ${MY_SOURCES})

# Slint-Dateien verarbeiten (nutzt die Liste aus MY_UI_FILES)
slint_target_sources(${MY_PROJECT_NAME} ${MY_UI_FILES})

# Verknüpfen aller Komponenten
target_link_libraries(${MY_PROJECT_NAME} 
    PRIVATE 
    Slint::Slint 
    ${MY_LIB_NAME}
)

# On Windows, copy the Slint DLL next to the application binary so that it's found.
if(WIN32)
    add_custom_command(TARGET ${MY_PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:${MY_PROJECT_NAME}>
        $<TARGET_FILE_DIR:${MY_PROJECT_NAME}>
        COMMAND_EXPAND_LISTS
    )
endif()

# Add assets to the exe
file(COPY ${CMAKE_SOURCE_DIR}/assets
     DESTINATION ${CMAKE_BINARY_DIR})