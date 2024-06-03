#include <Application/PkgMgr.h>
#include <Application/Utils.h>

#include <map>
#include <fstream>
#include <cstdlib>
#include <filesystem>


namespace fs = std::filesystem;

namespace Linux {

    std::string DeterminePackageManager() {
        std::map<std::string, std::string> distro_files = {
                {"/etc/debian_version", "/usr/bin/apt"},
                {"/etc/redhat-release", "/bin/dnf"},
                {"/etc/SuSE-release", "/bin/zypper"},
                {"/etc/arch-release", "/bin/pacman"}
        };

        for (const auto& value : distro_files) {
            std::ifstream is(value.first);
            if (is.good()) {
                if (is.is_open())
                    is.close();

                return value.second;
            }
        }

        if (IsAndroid())
            return "/system/bin/pm";

        return "-";
    }

    std::string CorrectPkgMgrBinPath(const std::string& forBin) {
        std::vector<std::string> pathArr = Application::Utils::PathEnv();

        for (auto& pathEntry : pathArr) {
            if (fs::exists(pathEntry) && fs::is_directory(pathEntry)) {
                for (const auto &entry: fs::directory_iterator(pathEntry)) {
                    if (entry.path().filename().string() == forBin)
                        return entry.path();
                }
            }
        }

        return DeterminePackageManager();
    }

    bool IsAndroid() {
        bool android = false;

#ifdef __ANDROID__
        android = true;
#endif

        return android;
    }

}