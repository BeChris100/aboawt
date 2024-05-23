#ifndef ABOAWT_UTILS_H
#define ABOAWT_UTILS_H

#define DEFAULTS_VALUE_SELECT "{select}"

#include <string>

namespace Application::Utils {

    int RandomInteger(int min, int max);

    long RandomLong(long min, long max);

    bool SafeIntConversion(const std::string& str);

}

#endif //ABOAWT_UTILS_H
