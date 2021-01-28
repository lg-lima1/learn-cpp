add_executable(lesson_0 main.cpp)
target_link_libraries(
  lesson_0
  PRIVATE project_options
          project_warnings
          CONAN_PKG::docopt.cpp
          CONAN_PKG::fmt
          CONAN_PKG::spdlog)
