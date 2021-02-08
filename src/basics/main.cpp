#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include <iostream>

int main()
{
  fmt::print("Insert a number: ");

  int x{ };
  std::cin >> x;

  fmt::print("You inserted number {}\n", x);

  return 0;  
}
