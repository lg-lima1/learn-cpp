#include <fmt/format.h>
#include <spdlog/spdlog.h>

void print_out()
{
  fmt::print("\tStarting print_out()\n");
  static int count = 0;
  fmt::print("\t\tprint_out() - count: {}\n", ++count);
  fmt::print("\tEnding print_out()\n");
}

void func_b()
{
  fmt::print("\t\tStarting func_b()\n");
  fmt::print("\t\tEnding func_b()\n");  
}

void func_a()
{
  fmt::print("\tStarting func_a()\n");
  func_b();
  fmt::print("\tEnding func_a()\n");  
}

int main()
{
  // Calling functions more than once
  fmt::print("Starting main()\n");
  print_out();
  print_out();

  // Function calling function
  func_a();

  fmt::print("Ending main()\n");
  return 0;  
}
