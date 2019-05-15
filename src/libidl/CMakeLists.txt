project(libidl VERSION 0.1 LANGUAGES CXX)

set(CODE_GEN_PY "${CMAKE_CURRENT_SOURCE_DIR}/resources/code_gen.py")
set(CODE_GEN_SRC_OUT "code_gen_src.cpp")

add_custom_command(
  OUTPUT ${CODE_GEN_SRC_OUT}
  COMMAND echo "#include <string>"                                >  ${CODE_GEN_SRC_OUT}
  COMMAND echo "using namespace std::literals::string_literals;"  >> ${CODE_GEN_SRC_OUT}
  COMMAND echo "namespace idl {"                                  >> ${CODE_GEN_SRC_OUT}
  COMMAND echo "auto code_gen_src = R\"***("                         >> ${CODE_GEN_SRC_OUT}
  COMMAND cat ${CODE_GEN_PY}                                      >> ${CODE_GEN_SRC_OUT}
  COMMAND echo ")***\"s;"                                            >> ${CODE_GEN_SRC_OUT}
  COMMAND echo "}"                                                >> ${CODE_GEN_SRC_OUT}
  VERBATIM
  MAIN_DEPENDENCY ${CODE_GEN_PY})

add_custom_target(code-gen-src
  ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${CODE_GEN_SRC_OUT})

add_library(idl
  src/atom.cpp
  src/atom_type.cpp
  src/code_generator.cpp
  src/constraint.cpp
  src/opcode_type.cpp
  src/python_utils.cpp
  src/slot.cpp
  src/specification.cpp

  ${CODE_GEN_SRC_OUT}
)

add_dependencies(idl code-gen-src)

target_include_directories(idl
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(idl
  CONAN_PKG::fmt
  CONAN_PKG::value-ptr
  CONAN_PKG::python_dev_config
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

add_executable(idl-app
  test/app.cpp)

target_link_libraries(idl-app
  idl
  CONAN_PKG::fmt)

add_executable(idl-unit
  test/main.cpp)

target_link_libraries(idl-unit
  idl
  CONAN_PKG::Catch2)

add_test(
  NAME idl-unit
  COMMAND $<TARGET_FILE:idl-unit>)
