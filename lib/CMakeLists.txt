set (LibrarySources 
     HangmanLogic.cpp HangmanLogic.h
     GameController.cpp GameController.h
     NavigationController.cpp NavigationController.h)

#add Librarys
add_library(${MY_LIB_NAME} STATIC ${LibrarySources})
            
target_include_directories(${MY_LIB_NAME} PUBLIC .)