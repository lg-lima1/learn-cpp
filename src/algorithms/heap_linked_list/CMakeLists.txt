add_executable(heap_linked_list main.cpp)
target_link_libraries(
  heap_linked_list
  PRIVATE project_options
          project_warnings
          CONAN_PKG::fmt
          )
