cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.12/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(CONANFILE "../conanfile.txt"
                BASIC_SETUP CMAKE_TARGETS
                BUILD missing)

include(GNUInstallDirs)
enable_testing()

add_subdirectory(libidl)
