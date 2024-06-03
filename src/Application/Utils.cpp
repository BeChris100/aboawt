#include <Application/Utils.h>

#include <cstdlib>
#include <ctime>
#include <limits>
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <sstream>

namespace Application::Utils {

    int RandomInteger(int min, int max) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        return std::rand() % (max - min + 1) + min;
    }

    long RandomLong(long min, long max) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        return std::rand() % (max - min + 1) + min;
    }

    std::string Lowercase(const std::string &str) {
        std::string v = str;
        std::transform(v.begin(), v.end(), v.begin(), [](unsigned char c){ return std::tolower(c); });
        return v;
    }

    std::string Uppercase(const std::string &str) {
        std::string v = str;
        std::transform(v.begin(), v.end(), v.begin(), [](unsigned char c){ return std::toupper(c); });
        return v;
    }

    bool SafeIntConversion(const std::string& str) {
        try {
            long value = std::stol(str);

            if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
                return false;

            return true;
        } catch (const std::invalid_argument& e) {
            return false;
        } catch (const std::out_of_range& e) {
            return false;
        }
    }

    bool StrToBool(const std::string& str, bool defBool) {
        std::string v = Lowercase(str);

        if (v == "true" || v == "t")
            return true;

        if (v == "false" || v == "f")
            return false;

        if (v == "yes" || v == "y")
            return true;

        if (v == "no" || v == "n")
            return false;

        if (v == "enabled" || v == "e")
            return true;

        if (v == "disabled" || v == "d")
            return false;

        if (v == "allowed")
            return true;

        if (v == "disallowed")
            return false;

        return defBool;
    }

    std::vector<std::string> PathEnv() {
        std::vector<std::string> items;

        const char* pathEnv = std::getenv("PATH");
        if (pathEnv == nullptr || std::string(pathEnv).empty())
            return items;

        std::string pathString(pathEnv);
        if (pathString.find(':') == std::string::npos) {
            items.push_back(pathString);
            return items;
        }

        std::stringstream ss(pathString);
        std::string _path;

        while (std::getline(ss, _path, ':'))
            items.push_back(_path);

        return items;
    }

}