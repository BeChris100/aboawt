#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>

#include <Application/Definitions.h>
#include <Application/Utils.h>

std::string action = ACTION_NONE;

using namespace Application::Utils;

void help() {
    std::cout << "aboawt (AOSP building on Android with Termux) v1.0" << std::endl << std::endl;
    std::cout << "usage: ./aboawt [options] [action]" << std::endl << std::endl;
    std::cout << "options:" << std::endl;
    std::cout << "  --no-preserve-swap              Do not initialize a Swap file, if no swap file is in use" << std::endl;
    std::cout << "  --no-mass-storage-attachment    Do not use an external storage card (e.g. USB/SD card)" << std::endl;
    std::cout << "  --assume-swap-capable           Assumes that the kernel is swap capable (dangerous!)" << std::endl;
    std::cout << "  --swap-size=[size]              Sets a specific amount of Swap (\"[size]\": amount of swap file size; e.g. 16G)" << std::endl << std::endl;
    std::cout << "actions:" << std::endl;
    std::cout << "  prepare                         Prepares the device for building" << std::endl;
    std::cout << "  init                            Initializes the AOSP from remote URL" << std::endl;
    std::cout << "  fetch                           Fetches the files from the remote URL (similar to \"repo sync\" process)" << std::endl;
    std::cout << "  build                           Builds the AOSP" << std::endl << std::endl;
    std::cout << "Takes env variables:" << std::endl;
    std::cout << "  AOSP_WORK_DIR=[path]            Puts the AOSP codebase in a specific directory (defaults to the current directory, or relative path of \"DRIVE_PATH\")" << std::endl;
    std::cout << "  AOSP_OUTPUT_DIR=[path]          Puts the compiled AOSP code to its specific directory (defaults to the current directory's \"out\" folder)" << std::endl;
    std::cout << "  AOSP_REMOTE_URL=[url]           Takes in a remote manifest URL (default: \"https://android.googlesource.com/platform/manifest\")" << std::endl;
    std::cout << "  AOSP_REMOTE_BRANCH=[branch]     Takes in a remote Git Branch (defaults to the remote default branch)" << std::endl;
    std::cout << "  DRIVE_PATH=[drive|path]         Automates the selection of a specific USB Mass Storage Device/SD card to the specific device/path" << std::endl;
    std::cout << "  GIT_DEPTH=0                     If a non 0 value is given, it passes the `--depth=` parameter. Can be used to fetch sources faster" << std::endl;
}

bool args(int argc, char **argv) {
    std::vector<std::string> actionList;
    bool pushArg = false;

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (arg[0] == '-') {
            if (arg == "--no-preserve-swap")
                Application::Definitions::PreserveSwap = false;

            if (arg == "--no-mass-storage-attachment")
                Application::Definitions::UseExternalStorage = false;

            if (arg == "--assume-swap-capable") {
                if (RandomInteger(1, 500) != 210) {
                    std::cerr << "!! DANGEROUS !!" << std::endl;
                    std::cerr << "Using \"--assume-swap-capable\" might crash the application, or in worse cases, crash the device." << std::endl;
                    std::cerr << "If you know the kernel build configuration, you may continue." << std::endl;
                    std::cerr << "Proceed at your own risk." << std::endl << std::endl;
                } else {
                    std::cerr << "!! you going crazy !!" << std::endl;
                    std::cerr << "Blud, are you trying to nuke your device?" << std::endl;
                    std::cerr << "I hope you already know that your kernel has swap enabled." << std::endl;
                    std::cerr << "If not... well, not my problem, if the app crashes, or your device crashes." << std::endl;
                }

                Application::Definitions::AssumeSwapSupport = true;
            }
        } else {
            if (arg == "none") {
                std::cerr << "Can't take \"none\" as an action." << std::endl;

                if (RandomInteger(0, 5000) == 5000 / 2)
                    std::cerr << "Bruh, what you try'na do here? Run nothing?" << std::endl;

                return true;
            }

            if (arg == "prepare") {
                action = ACTION_PREPARE;
                pushArg = true;
            }

            if (arg == "init") {
                action = ACTION_INITIALIZE;
                pushArg = true;
            }

            if (arg == "fetch") {
                action = ACTION_FETCH;
                pushArg = true;
            }

            if (arg == "build") {
                action = ACTION_BUILD;
                pushArg = true;
            }

            if (arg == "help") {
                help();
                return true;
            }

            if (pushArg)
                actionList.push_back(arg);
        }

        if (pushArg)
            pushArg = false;
    }

    if (action == ACTION_NONE) {
        std::cerr << "Invalid action was given" << std::endl;
        return true;
    }

    if (actionList.empty()) {
        std::cerr << "No actions defined" << std::endl;
        return true;
    }

    if (actionList.size() > 1) {
        std::cerr << "More than one action defined" << std::endl;
        return true;
    }

    return false;
}

int main(int argc, char **argv, char **env) {
    if (argc == 1) {
        help();
        return 0;
    } else {
        if (args(argc, argv))
            return 1;
    }

#ifdef __ANDROID__
    if (__ANDROID_API__ >= 29) {
        std::cout << "Without root, your Android system might cause a bit of Storage mayhem." << std::endl;
        std::cout << "This is due to the integration of \"ScopedStorage\"." << std::endl;
        std::cout << "If possible, proceed with root." << std::endl;
    }
#endif

    if (getuid() != 0) {
        if (RandomInteger(0, 100000) == 102)
            std::cerr << "ROOT IS REQUIRED. ROOT, BROTHER, ROOT! ROOT YER DEVICE!" << std::endl;
        else
            std::cerr << "root required to operate" << std::endl;

        return 1;
    }

    for (char **currentEnv = env; *currentEnv; ++currentEnv) {
        std::string env_var(*currentEnv);

        size_t pos = env_var.find('=');
        if (pos == std::string::npos) {
            continue;
        }

        std::string key = env_var.substr(0, pos);
        std::string val = env_var.substr(pos + 1);

        if (key == "AOSP_WORK_DIR")
            Application::Variables::AOSP_WORK_DIR = val;

        if (key == "AOSP_OUTPUT_DIR")
            Application::Variables::AOSP_OUTPUT_DIR = val;

        if (key == "AOSP_REMOTE_URL")
            Application::Variables::AOSP_REMOTE_URL = val;

        if (key == "AOSP_REMOTE_BRANCH")
            Application::Variables::AOSP_REMOTE_BRANCH = val;

        if (key == "DRIVE_PATH")
            Application::Variables::DRIVE_PATH = val;

        if (key == "GIT_DEPTH") {
            if (!SafeIntConversion(val)) {
                std::cerr << "Cannot set \"" << val << "\" as a valid number value" << std::endl;
                return 1;
            }

            Application::Variables::GIT_DEPTH = std::stoi(val);
        }
    }

    return 0;
}
