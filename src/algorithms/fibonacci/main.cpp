#include <fmt/format.h>
#include <array>
#include <utility>
#include <string>

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
uint64_t fib_impl(std::index_sequence<I...>, const uint32_t i)
{
  constexpr std::array<uint64_t, sizeof...(I)> a = { Fib<I>::val... };

  return a[i];
}

uint64_t fib(const uint32_t i)
{
  return fib_impl(std::make_index_sequence<94>(), i);
}

int main(int, char *argv[])
{
  auto val = unsigned(std::stoi(argv[1]));

  if (val < 94) 
  {
    fmt::print("fib({}) = {}\n", val, fib(val));
  }

  return 0;  
}
