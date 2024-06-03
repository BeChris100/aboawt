#include <Swap/SwapManager.h>

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace SwapManager {

    /*
     * Reads "/proc/swaps", if present, and returns them in the "SwapDisk" structure
     */
    std::vector<SwapDisk> SwapDisks() {
        std::vector<SwapDisk> disks;
        std::ifstream file("/proc/swaps");
        if (!file.is_open())
            throw std::runtime_error("File Open Error: /proc/swaps");

        std::string line;
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            SwapDisk disk;
            iss >> disk.fileName >> disk.swapType >> disk.swapSize >> disk.usedSize >> disk.priority;

            disks.push_back(disk);
        }

        file.close();

        return disks;
    }

    bool IsFile(const SwapDisk& disk) {
        if (disk.swapType.empty())
            return false;

        return disk.swapType == SWAP_TYPE_FILE;
    }

    bool IsPartition(const SwapDisk& disk) {
        if (disk.swapType.empty())
            return false;

        return disk.swapType == SWAP_TYPE_PARTITION;
    }

}