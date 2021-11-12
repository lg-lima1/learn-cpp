add_executable(functions main.cpp)
target_link_libraries(
  functions
  PRIVATE project_options
          project_warnings
          CONAN_PKG::docopt.cpp
          CONAN_PKG::fmt
          CONAN_PKG::spdlog
          )
