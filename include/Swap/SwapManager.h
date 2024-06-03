#ifndef ABOAWT_SWAPMANAGER_H
#define ABOAWT_SWAPMANAGER_H

#define SWAP_TYPE_FILE "file"
#define SWAP_TYPE_PARTITION "partition"

#include <vector>
#include <string>


namespace SwapManager {

    struct SwapDisk {
        std::string fileName;
        std::string swapType;
        long swapSize;
        long usedSize;
        int priority;
    };

    /*
     * Reads "/proc/swaps", if present, and returns them in the "SwapDisk" structure
     */
    std::vector<SwapDisk> SwapDisks();

    bool IsFile(const SwapDisk& disk);

    bool IsPartition(const SwapDisk& disk);

}

#endif //ABOAWT_SWAPMANAGER_H
