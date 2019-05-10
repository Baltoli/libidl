#pragma once

#include <value_ptr/value_ptr.h>

#include <fmt/format.h>

#include <memory>

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

template <typename T>
struct up_to_string_fmt {
  template <typename ParseContext>
  constexpr auto parse(ParseContext& ctx)
  {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(bsc::value_ptr<T> const& t, FormatContext& ctx)
  {
    return format_to(ctx.out(), "{}", t->to_string());
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

#define USE_VP_TO_STRING_FORMAT(cls) \
namespace fmt { \
template <> \
struct formatter<bsc::value_ptr<cls>> : up_to_string_fmt<cls> { \
}; \
}

// clang-format on
