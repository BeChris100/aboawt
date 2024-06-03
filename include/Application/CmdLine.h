#ifndef ABOAWT_CMDLINE_H
#define ABOAWT_CMDLINE_H

#include <Application/Definitions.h>

using namespace Application::Variables;

namespace Application::Cmdline {

    std::string GitCommandLine(bool isGitlab, const std::string& gitUsername, const std::string& gitRepoName);

    std::string RepoCmdCommandLine();

    std::string ConstructCmdline();

    std::string MakeCommandLine();

}

#endif //ABOAWT_CMDLINE_H
