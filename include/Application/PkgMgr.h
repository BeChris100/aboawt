#ifndef ABOAWT_PKGMGR_H
#define ABOAWT_PKGMGR_H

#include <string>

namespace Linux {

    std::string DeterminePackageManager();

    std::string CorrectPkgMgrBinPath(const std::string& forBin);

    bool IsAndroid();

}

#endif //ABOAWT_PKGMGR_H
