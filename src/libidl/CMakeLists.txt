project(libidl VERSION 0.1 LANGUAGES CXX)

add_library(idl
  src/atom.cpp
  src/atom_type.cpp
  src/constraint.cpp
  src/slot.cpp
  src/specification.cpp
)

target_link_libraries(idl
  CONAN_PKG::fmt
)

target_include_directories(idl PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  PRIVATE src)

install(TARGETS idl EXPORT IDLConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT IDLConfig DESTINATION share/IDL/cmake)

add_executable(idl-unit
  test/main.cpp)

target_link_libraries(idl-unit
  idl
  CONAN_PKG::Catch2)

add_test(
  NAME idl-unit
  COMMAND $<TARGET_FILE:idl-unit>)
