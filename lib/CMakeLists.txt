set (LibrarySources 
     HangmanLogic.cpp HangmanLogic.h
     Controller.cpp Controller.h)

#add Librarys
add_library(${MY_LIB_NAME} STATIC ${LibrarySources})
            
target_include_directories(${MY_LIB_NAME} PUBLIC .)