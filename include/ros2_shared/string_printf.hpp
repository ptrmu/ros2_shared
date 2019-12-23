
#ifndef _STRING_PRINTF_HPP
#define _STRING_PRINTF_HPP

#include <cstdarg> // for va_list, va_start
#include <string>

namespace ros2_shared
{
  std::string string_printf(std::string fmt_str, ...)
  {
    constexpr size_t string_reserve = 32;
    size_t str_len = std::max(fmt_str.size(), string_reserve);
    std::string str;

    do {
      va_list ap;
      va_start(ap, fmt_str); // NOTE: vsnprintf modifies ap so it has to be initialized in the loop

      str.resize(str_len);

      auto final_n = vsnprintf(const_cast<char *>(str.data()), str_len, fmt_str.c_str(), ap);

      // For an encoding error just return what is in the buffer.
      if (final_n < 0) {
        break;
      }

      auto final_n_ = static_cast<size_t>(final_n);
      // If the buffer sufficient, resize it and finish.
      if (final_n_ < str_len) {
        str.resize(final_n_ + 1); // don't truncate the trailing null!
        break;
      }

      // The buffer was not large enough. So resize it.
      str_len = final_n_ + 1;

      va_end(ap);
    } while (true);

    return str;
  }
}
#endif //_STRING_PRINTF_HPP
