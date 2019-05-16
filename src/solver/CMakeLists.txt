project(solver VERSION 0.1 LANGUAGES CXX)

add_library(solver
  src/Solver.cpp
  src/Solution.cpp
  src/FunctionWrap.cpp

  src/BackendEdge.cpp
  src/BackendSingle.cpp
  src/BackendCollect.cpp
  src/BackendDominate.cpp
  src/BackendOrdering.cpp
  src/BackendSameSets.cpp
  src/BackendIncomingValue.cpp
  src/BackendSpecializations.cpp
)

target_link_libraries(solver
  ${llvm_libs})

target_include_directories(solver PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  PRIVATE src)

install(TARGETS solver EXPORT SolverConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT SolverConfig DESTINATION share/Solver/cmake)
