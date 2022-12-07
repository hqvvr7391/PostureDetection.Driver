cmake_minimum_required(VERSION 3.8)
project(Posture.Driver VERSION 0.1.0)

include(CTest)
enable_testing()


add_executable(${PROJECT_NAME} test/main.cpp)


set(OpenCV_DIR "P:/Frameworks/Library/Graphics/opencv/build/gcc")
message("Buld")
find_package(OpenCV REQUIRED)
set(BUILD_SHARED_LIBS OFF)

if( OpenCV_STATIC )
    message(${OpenCV_INCLUDE_DIRS})
    foreach( flag_var
            CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
            CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO
            CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO )
    if( ${flag_var} MATCHES "/MD" )
        string( REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}" )
    endif()
    endforeach()
endif()

if(OpenCV_FOUND)

    include_directories( ${OpenCV_INCLUDE_DIRS} )

    # Additional Library Directories
    link_directories( ${OpenCV_LIB_DIR} )
    target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )
endif()



#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
