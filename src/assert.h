#include <iostream>
inline void report_assertion_failure(const char *expr, const char *file,
                                     int line) {
  std::cerr << "Assertion failed: " << expr << ", " << file << ":" << line
            << std::endl;
}

#define ASSERT(expr)                                                           \
  if (!expr) {                                                                 \
    report_assertion_failure(#expr, __FILE__, __LINE__);                       \
    __builtin_trap();                                                          \
  }