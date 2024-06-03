#ifndef ABOAWT_DEFINITIONS_H
#define ABOAWT_DEFINITIONS_H

#define ACTION_PREPARE      "prepare"
#define ACTION_INITIALIZE   "init"
#define ACTION_FETCH        "fetch"
#define ACTION_BUILD        "build"
#define ACTION_NONE         "none"

#define BRANCH_REMOTE_DEFAULT "{remote_default}"

#include <string>

namespace Application {

    enum ActionType {
        NONE = 0,
        PREPARE = 1,
        INITIALIZE = 2,
        FETCH = 3,
        BUILD = 4
    };

    namespace Definitions {
        extern bool AssumeSwapSupport;
        extern bool PreserveSwap;
        extern bool UseExternalStorage;

        extern long SwapSize;
        extern long DefaultSwapSize;

        long SpecificSwapSize(char *value);
    }

    namespace Variables {
        extern bool AOSP_WORK_DIR_InPWD;
        extern std::string AOSP_WORK_DIR;
        extern std::string AOSP_OUTPUT_DIR;
        extern std::string AOSP_REMOTE_URL;
        extern std::string AOSP_REMOTE_BRANCH;
        extern std::string DRIVE_PATH;

        extern int GIT_DEPTH;
    }

}

#endif //ABOAWT_DEFINITIONS_H
