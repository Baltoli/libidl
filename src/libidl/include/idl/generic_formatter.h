#pragma once

#include <fmt/format.h>

namespace fmt {

template <typename T>
struct to_string_fmt {
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx)
  {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(T const& t, FormatContext& ctx)
  {
    return format_to(ctx.out(), "{}", t.to_string());
  }
};

} // namespace fmt

// clang-format off

#define USE_TO_STRING_FORMAT(cls) \
namespace fmt { \
template <> \
struct formatter<cls> : to_string_fmt<cls> { \
}; \
}

// clang-format on
