#ifndef ABOAWT_SWAPMANAGER_H
#define ABOAWT_SWAPMANAGER_H

#define SWAP_DEFVAL_STR "--"
#define SWAP_DEFVAL_INT -500
#define SWAP_DEFVAL_LNG -500L

#define SWAP_TYPE_FILE "swap_file"
#define SWAP_TYPE_PARTITION "swap_partition"

#include <vector>
#include <string>

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

#endif //ABOAWT_SWAPMANAGER_H
