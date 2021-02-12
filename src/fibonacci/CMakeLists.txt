add_executable(fibonacci main.cpp)
target_link_libraries(
  fibonacci
  PRIVATE project_options
          project_warnings
          CONAN_PKG::fmt
          CONAN_PKG::spdlog
          )
