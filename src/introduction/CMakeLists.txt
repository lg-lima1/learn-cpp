add_executable(introduction main.cpp)
target_link_libraries(
  introduction
  PRIVATE project_options
          project_warnings
          CONAN_PKG::docopt.cpp
          CONAN_PKG::fmt
          CONAN_PKG::spdlog
          )
