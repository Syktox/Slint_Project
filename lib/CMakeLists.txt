set (LibrarySources 
     GameSettings.cpp GameSettings.h
     GameController.cpp GameController.h
     NavigationController.h
     Views.h)

#add Librarys
add_library(${MY_LIB_NAME} STATIC ${LibrarySources})
            
target_include_directories(${MY_LIB_NAME} PUBLIC .)