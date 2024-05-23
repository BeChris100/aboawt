#include <Application/Definitions.h>
#include <Application/Utils.h>

namespace Application::Definitions {
    bool AssumeSwapSupport = false;
    bool PreserveSwap = true;
    bool UseExternalStorage = true;

    long SwapSize = 1024l * 1024l * 1024l * 16l;

    long SpecificSwapSize(char *value) {
        // TODO: convert "value" to a specific long value
        // e.g.
        // "16G" | "16 G" --> 16 GB
        // "1024M*16" --> calculate "1024M" to 1024 MB, multiply by 16
        // values in K/KB are not supported
        // values in M/MB, G/GB and T/TB are supported
        return 1024l * 1024l * 1024l * 16l;
    }
}

namespace Application::Variables {
    std::string AOSP_WORK_DIR = "{pwd}/aosp-{branch_name}";
    std::string AOSP_OUTPUT_DIR = "{pwd}/aosp-{branch_name}/out";
    std::string AOSP_REMOTE_URL = "https://android.googlesource.com/platform/manifest";
    std::string AOSP_REMOTE_BRANCH = BRANCH_REMOTE_DEFAULT;
    std::string DRIVE_PATH = DEFAULTS_VALUE_SELECT;

    int GIT_DEPTH = 0;
}