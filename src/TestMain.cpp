/*
 * Test code that was used during development process,
 * separating the main file code and its testing.
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char **argv, char **envp) {
    std::cout << "Hello Code" << std::endl;

    const char *pathEnv = std::getenv("PATH");
    if (pathEnv == nullptr || std::string(pathEnv).empty()) {
        std::cerr << "PATH env not found" << std::endl;
        return 1;
    }

    std::vector<std::string> pathArr;
    std::string pathString(pathEnv);
    std::stringstream ss(pathString);
    std::string _path;

    while (std::getline(ss, _path, ':')) {
        pathArr.push_back(_path);
    }

    for (auto &pathEntry: pathArr) {
        if (fs::exists(pathEntry) && fs::is_directory(pathEntry)) {
            std::cout << "Contents of directory " << pathEntry << ":" << std::endl;
            for (const auto &entry: fs::directory_iterator(pathEntry)) {
                std::cout << entry.path().filename().string() << std::endl;
            }

            std::cout << "\n";
        }
    }

    return 0;
}