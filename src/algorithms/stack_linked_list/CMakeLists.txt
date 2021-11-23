add_executable(stack_linked_list main.cpp)
target_link_libraries(
  stack_linked_list
  PRIVATE project_options
          project_warnings
          CONAN_PKG::fmt
          )
