#include <Application/Utils.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <stdexcept>

namespace Application::Utils {

    int RandomInteger(int min, int max) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        return std::rand() % (max - min + 1) + min;
    }

    long RandomLong(long min, long max) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        return std::rand() % (max - min + 1) + min;
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
}