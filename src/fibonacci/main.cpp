#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include <array>
#include <utility>
#include <sstream>

template<uint64_t I>
struct Fib 
{
  static const uint64_t val = Fib<I-1>::val + Fib<I-2>::val;
};

template<>
struct Fib<0>
{
  static const uint64_t val = 0;
};

template<>
struct Fib<1>
{
  static const uint64_t val = 1;
};

template<size_t ... I>
uint64_t fib_impl(std::index_sequence<I...>, const int i)
{
  constexpr std::array<uint64_t, sizeof...(I)> a = { Fib<I>::val... };

  return a[unsigned(i)];
}

uint64_t fib(const int i)
{
  return fib_impl(std::make_index_sequence<95>(), i);
}

int main(int, const char** argv)
{
  spdlog::info("Hello World!");

  std::istringstream iss{ argv[1] };
  int val{};

  if (iss >> val)
  {
    if (val > 94) 
    {
      spdlog::error("Maximum number for calculating the Fibonacci is 94.");
      val = 94;
    }

    for(int i = 0; i < val; i++)
      fmt::print("fib({}) = {}\n", i, fib(i));
  }

  return 0;  
}
