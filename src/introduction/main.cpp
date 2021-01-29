#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include <array>
#include <string_view>
#include <tuple>
#include <type_traits>

namespace a::b::c
{
  inline constexpr std::string_view str{ "hello" }; // C++17: String view
}

template <class... T>
std::tuple<std::size_t, std::common_type_t<T...>> sum(T... args)
{
  return { sizeof...(T), (args + ...) };
}

int main()
{
  // Check if compilation goes like butter
  spdlog::info("Hello World!");

  // Test C++17 features
  auto [size, result]{ sum(1, 2, 3, 4, 5, 6, 7, 8, 9) }; // C++17: Template meta-programming
  fmt::print("a::b::c::str: {}\n", a::b::c::str);
  fmt::print("size: {}, result: {}\n", size, result);

  std::array arr{ 1, 2, 3 }; // C++17: Array initialization
  fmt::print("std::size(arr): {}\n", std::size(arr));

  return 0;  
}
