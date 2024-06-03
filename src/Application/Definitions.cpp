#include <Application/Definitions.h>
#include <Application/Utils.h>

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

namespace Application::Definitions {
    bool AssumeSwapSupport = false;
    bool PreserveSwap = true;
    bool UseExternalStorage = true;

    long SwapSize = 1024l * 1024l * 1024l * 16l;
    long DefaultSwapSize = 1024l * 1024l * 1024l * 8l; // 8 GB

    long SpecificSwapSize(char *value) {
        std::string val_str(value);
        std::istringstream iss(val_str);
        std::string number, unit;
        long result;

        iss >> number >> unit;
        unit.erase(std::remove_if(unit.begin(), unit.end(), isspace), unit.end());

        try {
            result = std::stol(number);
        } catch (const std::invalid_argument &e) {
            std::cerr << "Invalid number format; fallback to 8 GB" << std::endl;
            return DefaultSwapSize;
        }

        if (unit == "G" || unit == "GB")
            result *= 1024l * 1024l * 1024l;
        else if (unit == "M" || unit == "MB")
            result *= 1024l * 1024l;
        else if (unit == "T" || unit == "TB")
            result *= 1024l * 1024l * 1024l * 1024l;
        else {
            std::cerr << "Unknown unit; received " << val_str << "; fallback to 8 GB" << std::endl;
            return DefaultSwapSize;
        }

        return result;
    }
}

namespace Application::Variables {
    bool AOSP_WORK_DIR_InPWD = false;
    std::string AOSP_WORK_DIR = "{pwd}/aosp-{branch_name}";
    std::string AOSP_OUTPUT_DIR = "{pwd}/aosp-{branch_name}/out";
    std::string AOSP_REMOTE_URL = "https://android.googlesource.com/platform/manifest";
    std::string AOSP_REMOTE_BRANCH = BRANCH_REMOTE_DEFAULT;
    std::string DRIVE_PATH = DEFAULTS_VALUE_SELECT;

    int GIT_DEPTH = 0;
}