cmake_minimum_required(VERSION 3.16)

# ==========================================
# 1. PROJEKT-KONFIGURATION (Hier alles ändern)
# ==========================================
set(MY_PROJECT_NAME    "RaySIX")
set(MY_PROJECT_VERSION "1.0.0")
set(MY_LIB_NAME        "RaySixCore") # Name deiner Library aus dem lib-Ordner

# Liste aller Quelldateien im src-Ordner
set(MY_SOURCES
    "src/main.cpp"
    # "src/weitere_datei.cpp" <-- einfach hier erweitern
)

# Liste aller Slint-UI-Dateien
set(MY_UI_FILES
    "ui/MainWindow.slint"
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
include(FetchContent)

find_package(Slint QUIET)

if(NOT Slint_FOUND)
    message(STATUS "Slint nicht auf dem System gefunden.")
    FetchContent_Declare(
        Slint
        GIT_REPOSITORY https://github.com/slint-ui/slint.git
        GIT_TAG release/1.14
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
add_executable(${PROJECT_NAME} ${MY_SOURCES})

# Slint-Dateien verarbeiten (nutzt die Liste aus MY_UI_FILES)
slint_target_sources(${PROJECT_NAME} ${MY_UI_FILES})

# Verknüpfen aller Komponenten
target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        Slint::Slint 
        ${MY_LIB_NAME}
)