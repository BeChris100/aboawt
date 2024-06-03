#ifndef ABOAWT_UTILS_H
#define ABOAWT_UTILS_H

#define DEFAULTS_VALUE_SELECT "{select}"

#include <string>
#include <vector>

namespace Application::Utils {

    int RandomInteger(int min, int max);

    long RandomLong(long min, long max);

    std::string Lowercase(const std::string &str);

    std::string Uppercase(const std::string &str);

    bool SafeIntConversion(const std::string& str);

    bool StrToBool(const std::string& str, bool defBool);

    std::vector<std::string> PathEnv();

}

#endif //ABOAWT_UTILS_H
