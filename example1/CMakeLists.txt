cmake_minimum_required(VERSION 3.16.3)

project(ctests)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_COMPILER gcc)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

include(GNUInstallDirs)

include_directories(
    ../ 
    )

#add_subdirectory(arrays)


add_executable(args  
    ../arg_parse.c
    arg_config_ex1.c
    main.c
    )
    
#target_include_directories(ctests 
#    $(CMAKE_CURRENT_LIST_DIR))

target_link_libraries(args -Wall -Wextra)
 

