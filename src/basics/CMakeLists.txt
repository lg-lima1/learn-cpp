add_executable(basics main.cpp)
target_link_libraries(
  basics
  PRIVATE project_options
          project_warnings
          CONAN_PKG::docopt.cpp
          CONAN_PKG::fmt
          CONAN_PKG::spdlog
          )
