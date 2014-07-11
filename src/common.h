#ifndef COMMON_H
#define COMMON_H

#include "util/ilogger.h"

#include <memory>
#include <cxxabi.h>

inline const char* demangle(const char *s) {
    return abi::__cxa_demangle(s, 0, 0, NULL);
}

template<typename T>
inline const char* type_name() {
    return demangle(typeid(T).name());
}

#endif // COMMON_H
