#include <Application/CmdLine.h>

#include <sstream>

namespace Application::Cmdline {

    std::string GitCommandLine(bool isGitlab, const std::string& gitUsername, const std::string& gitRepoName) {
        std::stringstream ss;
        ss << "git clone https://" << (isGitlab ? "gitlab.com" : "github.com") << "/" << gitUsername << "/" << gitRepoName;

        if (GIT_DEPTH != 0)
            ss << " --depth=" << GIT_DEPTH;

        return ss.str();
    }

    std::string RepoCmdCommandLine() {
        return "";
    }

    std::string ConstructCmdline() {
        return "";
    }

    std::string MakeCommandLine() {
        return "";
    }

}